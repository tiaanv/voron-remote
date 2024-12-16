#ifndef display_h
#define display_h
#include <Arduino_GFX_Library.h>
#define TOUCH_MODULES_CST_SELF
#include <TouchLib.h>
#include <lvgl.h>
#include <ui.h>


enum BoardConstants {
    LVGL_BUFFER_RATIO = 6,
    PIN_LCD_BL=38,
    PIN_LCD_D0=39, PIN_LCD_D1=40, PIN_LCD_D2=41, PIN_LCD_D3=42, PIN_LCD_D4=45, PIN_LCD_D5=46, PIN_LCD_D6=47, PIN_LCD_D7=48,
    PIN_LCD_RST=1, PIN_LCD_CS=6, PIN_LCD_DC=7, //RS
    PIN_LCD_WR=8, PIN_LCD_RD=9,
    PIN_IIC_SCL=17, PIN_IIC_SDA=18,  PIN_TOUCH_INT=16, PIN_TOUCH_RES=21,
    PIN_BUTTON_1=0, PIN_BUTTON_2=14, PIN_BAT_VOLT=4
};


static const uint16_t screenWidth = 170;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf [screenWidth * screenHeight / LVGL_BUFFER_RATIO];

extern bool disp_sleep;

void Task_TFT(void *pvParameters);
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);
void init_display_touch();

#endif

