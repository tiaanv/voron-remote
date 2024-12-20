// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t * ui_Screen1;
void ui_event_BtnDist(lv_event_t * e);
lv_obj_t * ui_BtnDist;
lv_obj_t * ui_lblDist;
void ui_event_pnlX(lv_event_t * e);
lv_obj_t * ui_pnlX;
lv_obj_t * ui_Label1;
lv_obj_t * ui_lblPosX;
lv_obj_t * ui_lblTarX;
void ui_event_pnlY(lv_event_t * e);
lv_obj_t * ui_pnlY;
void ui_event_plnZ(lv_event_t * e);
lv_obj_t * ui_plnZ;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label5;
lv_obj_t * ui_lblPosY;
lv_obj_t * ui_lblTarY;
lv_obj_t * ui_lblPosZ;
lv_obj_t * ui_lblTarZ;
void ui_event_Panel2(lv_event_t * e);
lv_obj_t * ui_Panel2;
lv_obj_t * ui_lblStatus;
lv_obj_t * ui_imgWifiConnected;
lv_obj_t * ui_lblBat;
lv_obj_t * ui_imgWifiDisconnected;
// CUSTOM VARIABLES


// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
lv_obj_t * ui_Screen2;
void ui_event_BtnHome(lv_event_t * e);
lv_obj_t * ui_BtnHome;
void ui_event_BtnQGL(lv_event_t * e);
lv_obj_t * ui_BtnQGL;
void ui_event_BtnConfig(lv_event_t * e);
lv_obj_t * ui_BtnConfig;
void ui_event_BtnExit(lv_event_t * e);
lv_obj_t * ui_BtnExit;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Label7;
// CUSTOM VARIABLES

// EVENTS
lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_BtnDist(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        BtnDistClick(e);
    }
}

void ui_event_pnlX(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        PnlXClick(e);
    }
}

void ui_event_pnlY(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        PnlYClick(e);
    }
}

void ui_event_plnZ(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        PnlZClick(e);
    }
}

void ui_event_Panel2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 0, &ui_Screen2_screen_init);
    }
}

void ui_event_BtnHome(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        HomeClick(e);
    }
}

void ui_event_BtnQGL(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        QGLClick(e);
    }
}

void ui_event_BtnConfig(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        ConfigClick(e);
    }
}

void ui_event_BtnExit(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 0, &ui_Screen1_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
