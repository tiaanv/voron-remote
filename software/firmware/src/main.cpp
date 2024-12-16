#include "display.h"
#include <WiFi.h>
#include <ArduinoJson.h>
#include <ESP32Encoder.h>
#include "OneButton.h"
#include <Fetch.h>
#include <WiFiManager.h>

void get_printer_data();
void set_status(const char * status);
void process_printer_data(String data);
void set_active_axis(char axis);
void Click(void *oneButton);
void DoubleClick(void *oneButton);
void LongPressStart(void *oneButton);
void LongPressStop(void *oneButton);
void DuringLongPress(void *oneButton);

//DECLARATIONS
#define PIN_STOP_BUTTON GPIO_NUM_13
#define PIN_ENCODER_BUTTON GPIO_NUM_12
#define PIN_ENCODER_A GPIO_NUM_11
#define PIN_ENCODER_B GPIO_NUM_10
#define PIN_VBAT GPIO_NUM_4
#define SLEEP_TIMEOUT 180

const char* ssid = "VILJOEN";
const char* password = "wearesecure";
const char* serverName = "http://192.168.0.50:7125/";

#define BG_NORMAL 0xcd8405
#define BG_HIGHLIGHT 0xfbbf57

RTC_DATA_ATTR int bootCount = 0;
static RTC_NOINIT_ATTR bool AP_mode = false;

WiFiManager wm;
FetchClient client;
FetchClient client_command;
ESP32Encoder encoder;
OneButton button(12, true, true);

WiFiManagerParameter moonraker_url("moonraker_url", "Moonraker URL", "http://192.168.0.50:7125/", 40);

String serverPath = serverName;
String command;
unsigned long lastmove;
unsigned long lastgetdata;
unsigned long lastgetvoltage;
unsigned long last_input;
float step_size;
int64_t encoder_last;
int16_t encoder_delta = 0;

float x_val;
float y_val;
float z_val;

int16_t x_max = 350;
int16_t y_max = 350;
int16_t z_max = 300;

float x_target = -1;
float y_target = -1;
float z_target = -1;

bool data_pending = false;
bool request_pending = false;
bool first_connect = true;

char axis_active = 'X';
String dist_active = "0.1";

//===================== HTTP CLIENT =======================//

void handleResponse(Response response) {

    String responsetext(response.text());
    process_printer_data(responsetext.substring(198));

    request_pending = false;
}

void sendRequest(String url)
{
  static bool requestOpenResult;
  request_pending = true;

  RequestOptions options;
  options.method = "GET";
  options.caCert = "";


  client = fetch(url.c_str(), options, handleResponse);  
}

void handleCommandResponse(Response response) {

    String responsetext(response.text());

    request_pending = false;
}

void sendCommandRequest(String url)
{
  RequestOptions options;
  options.method = "POST";
  options.caCert = "";

  client_command = fetch(url.c_str(), options, handleCommandResponse);
  Serial.println(url.c_str());

}

//===================== SETUP/ INIT =======================//

void init_encoder()
{
	encoder.attachHalfQuad(PIN_ENCODER_A, PIN_ENCODER_B);
	encoder.clearCount();

}

void configModeCallback (WiFiManager *myWiFiManager) 
{
    set_status("AP MODE: " + WiFi.softAPIP());
    //Serial.println(myWiFiManager->getConfigPortalSSID());
}

void saveParamsCallback () {
  Serial.println("Get Params:");
  Serial.print(moonraker_url.getID());
  Serial.print(" : ");
  Serial.println(moonraker_url.getValue());
}

void init_wifi()
{
    WiFi.mode(WIFI_STA);

    //wm.resetSettings();

    wm.addParameter(&moonraker_url);
    wm.setConfigPortalBlocking(false);
    wm.setSaveParamsCallback(saveParamsCallback);
    //wm.setAPCallback(&configModeCallback);

    if (AP_mode)
    {
        AP_mode = false;
        wm.startConfigPortal("VORON-remote");
        set_status(("AP MODE: " + WiFi.softAPIP().toString()).c_str());
    }
    else
    {
        set_status("wifi connecting...");
        lv_obj_clear_flag(ui_imgWifiDisconnected, LV_OBJ_FLAG_HIDDEN);  
        if(wm.autoConnect("VORON-remote")){
            set_status("connected!");
        }
        else {
                set_status(("AP MODE: " + WiFi.softAPIP().toString()).c_str());
        }
    }




    // WiFi.begin(ssid, password);
    // set_status("wifi connecting...");
    // int wifi_start_time = millis();
    // lv_obj_clear_flag(ui_imgWifiDisconnected, LV_OBJ_FLAG_HIDDEN);
    // while(WiFi.status() != WL_CONNECTED ) {
    //     delay(200);
    //     if ((millis()- wifi_start_time) > 30000)
    //     {
    //         esp_restart();
    //     }
    //     int wifi_time = (millis()- wifi_start_time) / 1000;
    //     set_status(("wifi connecting... "+ String(wifi_time)).c_str());
    // }
    // lv_obj_add_flag(ui_imgWifiDisconnected, LV_OBJ_FLAG_HIDDEN);
    // set_status("connected!");
    
}


void init_printer_state()
{
    get_printer_data();
    x_target = x_val;
    y_target = y_val;
    z_target = z_val;

    dist_active = "0.1";
    encoder_last = 0;
    encoder_delta = 0;

    step_size = dist_active.toFloat();

    lv_label_set_text(ui_lblTarX,String(x_target,0).c_str());
    lv_label_set_text(ui_lblTarY,String(y_target,0).c_str());
    lv_label_set_text(ui_lblTarZ,String(z_target,0).c_str());

    set_active_axis('X');
    lv_label_set_text(ui_lblDist,dist_active.c_str());

}

void init_buttons()
{
  button.attachClick(Click, &button);
  button.attachDoubleClick(DoubleClick, &button);

  button.attachLongPressStart(LongPressStart, &button);
  button.attachDuringLongPress(DuringLongPress, &button);
  button.attachLongPressStop(LongPressStop, &button);

  button.setLongPressIntervalMs(1000);  

  pinMode(PIN_STOP_BUTTON, INPUT_PULLUP);
  
}

void setup ()
{

    Serial.begin(115200);
    delay(500);

    last_input = millis();

    init_display_touch();
    init_encoder();
    init_buttons();
    init_wifi();

}

//===================== SLEEP =======================//

void sleep_now()
{
    disp_sleep = true;
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_11, LOW);
    esp_deep_sleep_start();
}

int inactive_time()
{
    int inactive_time = lv_disp_get_inactive_time(NULL);
    if (inactive_time > (millis()-last_input))
    {
        inactive_time = (millis()-last_input);
    }
    return inactive_time / 1000;
}

//===================== PRINTER DATA =======================//


void process_printer_data(String data)
{
    JsonDocument payload;
    DeserializationError error = deserializeJson(payload, data);

    if (error) {
        Serial.print("deserializeJson() returned ");
        Serial.println(error.c_str());
        return;
    }

    x_val = payload["result"]["status"]["motion_report"]["live_position"][0];
    y_val = payload["result"]["status"]["motion_report"]["live_position"][1];
    z_val = payload["result"]["status"]["motion_report"]["live_position"][2];

    if ((millis() - lastmove) > 2000) {
        x_target = x_val;
        y_target = y_val;
        z_target = z_val;
        lv_label_set_text(ui_lblTarX,String(x_target,1).c_str());
        lv_label_set_text(ui_lblTarY,String(y_target,1).c_str());
        lv_label_set_text(ui_lblTarZ,String(z_target,1).c_str());

    }


    lv_label_set_text(ui_lblPosX,String(x_val,1).c_str());
    lv_label_set_text(ui_lblPosY,String(y_val,1).c_str());
    lv_label_set_text(ui_lblPosZ,String(z_val,1).c_str());
    data_pending = true;

}

void get_printer_data()
{
    if ((millis() < lastgetdata + 250) or request_pending) return;
    lastgetdata = millis();

    command = "printer/objects/query?motion_report";
    sendRequest(serverPath.c_str()+command);

}

//===================== ACTIONS =======================//

void set_status(const char * status)
{
    lv_label_set_text(ui_lblStatus,status);
}

void set_active_axis(char axis)
{
    axis_active = axis;

    if (axis == 'X')
        lv_obj_set_style_bg_color(ui_pnlX, lv_color_hex(BG_HIGHLIGHT),0);
    else
        lv_obj_set_style_bg_color(ui_pnlX, lv_color_hex(BG_NORMAL),0);
    if (axis == 'Y')
        lv_obj_set_style_bg_color(ui_pnlY, lv_color_hex(BG_HIGHLIGHT),0);
    else
        lv_obj_set_style_bg_color(ui_pnlY, lv_color_hex(BG_NORMAL),0);
    if (axis == 'Z')
        lv_obj_set_style_bg_color(ui_plnZ, lv_color_hex(BG_HIGHLIGHT),0);
    else
        lv_obj_set_style_bg_color(ui_plnZ, lv_color_hex(BG_NORMAL),0);

    encoder.clearCount();
    encoder_last = 0;    
}

void cycle_axis()
{
    if (axis_active == 'X')
        set_active_axis('Y');
    else if (axis_active == 'Y')
        set_active_axis('Z');
    else
        set_active_axis('X');

}

void cycle_stepsize()
{
    if (dist_active == "0.1")
        dist_active = "1";
    else if (dist_active == "1")
        dist_active = "10";
    else
        dist_active = "0.1";
    
    step_size = dist_active.toFloat();

    lv_label_set_text(ui_lblDist,dist_active.c_str());
    encoder.clearCount();
    encoder_last = 0;  
}

void printer_home()
{
    command = "printer/gcode/script?script=G28";
    sendCommandRequest(serverPath.c_str()+command);
    set_status("HOME");
    last_input = millis();


}

void printer_qgl()
{
    command = "printer/gcode/script?script=QUAD_GANTRY_LEVEL";
    sendCommandRequest(serverPath.c_str()+command);
    set_status("QGL");
    last_input = millis();

}

void printer_emergency_stop()
{
        Serial.println("EMERGENCY STOP");
        command = "printer/emergency_stop";
        sendCommandRequest(serverPath.c_str()+command);
        set_status("EMERGENCY STOP!");
        last_input = millis();

}

//===================== TOUCH SCREEN ======================//


void BtnDistClick(lv_event_t * e)
{
    cycle_stepsize();
}

void PnlXClick(lv_event_t * e)
{
	set_active_axis('X');
}

void PnlYClick(lv_event_t * e)
{
	set_active_axis('Y');
}

void PnlZClick(lv_event_t * e)
{
	set_active_axis('Z');
}

void HomeClick(lv_event_t * e)
{
    printer_home();
}

void QGLClick(lv_event_t * e)
{
	printer_qgl();
}

void ConfigClick(lv_event_t * e)
{
	AP_mode = true;
    esp_restart();
}

//===================== BUTTON CLICKS =======================//

void Click(void *oneButton)
{
    cycle_stepsize();
    last_input = millis();
}

void DoubleClick(void *oneButton)
{
    cycle_axis();
    last_input = millis();
}


void LongPressStart(void *oneButton)
{
    set_status("RELEASE TO HOME");
}

// this function will be called when the button is released.
void LongPressStop(void *oneButton)
{
    long presstime = ((OneButton *)oneButton)->getPressedMs();
    set_status("READY");
    if (presstime > 3000) return;

    printer_home();


}

// this function will be called when the button is held down.
void DuringLongPress(void *oneButton)
{
  long presstime = ((OneButton *)oneButton)->getPressedMs();
  //Serial.print(((OneButton *)oneButton)->getPressedMs());
  //Serial.println("\t - DuringLongPress()");
  if (presstime > 2000)
  {
        int sleeptime = ((6000 - presstime) / 1000);
        set_status(("Power Off: "+ String(sleeptime)).c_str());

    if (presstime > 5000)
    {
        sleep_now();
    }
  }
}

void get_encoder_data()
{
    if (encoder_last == encoder.getCount()) return;

    encoder_delta = (encoder.getCount() - encoder_last);

    if (abs(encoder_delta) < 2) return;

    encoder_last = encoder.getCount();
    last_input = millis();

}

void do_moves()
{
    if (abs(encoder_delta) < 2) return;

    command = "printer/gcode/script?script=G1";
    
    float move_dist = (encoder_delta/2) * step_size;
    //Serial.println(encoder_delta);
    //Serial.println(step_size);

    if (axis_active == 'X')
    {
        x_target = constrain(x_target + move_dist,0,x_max);
        lv_label_set_text(ui_lblTarX,String(x_target,1).c_str());
        command += "%20X"+String(x_target);
    }
    if (axis_active == 'Y')
    {
        y_target = constrain(y_target + move_dist,0,y_max);
        lv_label_set_text(ui_lblTarY,String(y_target,1).c_str());
        command += "%20Y"+String(y_target);
    }
    if (axis_active == 'Z')
    {
        z_target = constrain(z_target + move_dist,0,z_max);
        lv_label_set_text(ui_lblTarZ,String(z_target,1).c_str());
        command += "%20Z"+String(z_target);
    }

    command += "%20F6000";
    request_pending = true;
    sendCommandRequest(serverPath.c_str()+command);
    lastmove = millis();

    encoder_delta = 0;

}

void check_emergency_stop()
{
    if (digitalRead(13) == LOW)
    {
        printer_emergency_stop();
        delay(1000);
    }
}

void get_voltage()
{
    if ((millis() < lastgetvoltage + 1000)) return;
    lastgetvoltage = millis();

    int analogVolts = analogReadMilliVolts(PIN_VBAT);
    float v_bat = (analogVolts * 2) / 1000.0;
    lv_label_set_text(ui_lblBat,(String(v_bat,2)+"V").c_str());
}

void check_sleep_timeout()
{
    if(inactive_time() > (SLEEP_TIMEOUT-10)) {
        int sleeptime = (SLEEP_TIMEOUT - inactive_time())+1;
        set_status(("Sleeping in "+ String(sleeptime)).c_str());
        delay(100);
    }
    else
    {
        get_voltage();
    }

    if(inactive_time() > SLEEP_TIMEOUT) {
        //init_display_touch();
        set_status("Waking up...");
        sleep_now();
    }
}

void loop ()
{   
    check_sleep_timeout();

    button.tick();
    get_encoder_data();

    wm.process();

    if ( WiFi.status() == WL_CONNECTED )
    {
        if (first_connect)
        {
            first_connect = false;
            lv_obj_add_flag(ui_imgWifiDisconnected, LV_OBJ_FLAG_HIDDEN);
            set_status("Connected");
            init_printer_state();
        }
        client.loop();
        client_command.loop();
        check_emergency_stop();
        get_printer_data();
        do_moves();
    }
    else
    {

    }
}