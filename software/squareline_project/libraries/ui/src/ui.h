// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t * ui_Screen1;
void ui_event_BtnDist(lv_event_t * e);
extern lv_obj_t * ui_BtnDist;
extern lv_obj_t * ui_lblDist;
void ui_event_pnlX(lv_event_t * e);
extern lv_obj_t * ui_pnlX;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_lblPosX;
extern lv_obj_t * ui_lblTarX;
void ui_event_pnlY(lv_event_t * e);
extern lv_obj_t * ui_pnlY;
void ui_event_plnZ(lv_event_t * e);
extern lv_obj_t * ui_plnZ;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_lblPosY;
extern lv_obj_t * ui_lblTarY;
extern lv_obj_t * ui_lblPosZ;
extern lv_obj_t * ui_lblTarZ;
void ui_event_Panel2(lv_event_t * e);
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_lblStatus;
extern lv_obj_t * ui_imgWifiConnected;
extern lv_obj_t * ui_lblBat;
extern lv_obj_t * ui_imgWifiDisconnected;
// CUSTOM VARIABLES

// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
extern lv_obj_t * ui_Screen2;
void ui_event_BtnHome(lv_event_t * e);
extern lv_obj_t * ui_BtnHome;
void ui_event_BtnQGL(lv_event_t * e);
extern lv_obj_t * ui_BtnQGL;
void ui_event_BtnConfig(lv_event_t * e);
extern lv_obj_t * ui_BtnConfig;
void ui_event_BtnExit(lv_event_t * e);
extern lv_obj_t * ui_BtnExit;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_Label7;
// CUSTOM VARIABLES

// EVENTS

extern lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE(ui_img_1228895389);    // assets/wifi-connected-sml.png
LV_IMG_DECLARE(ui_img_1882247861);    // assets/wifi-disconnected-sml.png

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif