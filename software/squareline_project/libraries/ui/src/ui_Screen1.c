// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BtnDist = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_BtnDist, 165);
    lv_obj_set_height(ui_BtnDist, 59);
    lv_obj_set_x(ui_BtnDist, 0);
    lv_obj_set_y(ui_BtnDist, 18);
    lv_obj_set_align(ui_BtnDist, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnDist, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnDist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BtnDist, lv_color_hex(0x37A8E2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnDist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblDist = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblDist, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblDist, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblDist, 0);
    lv_obj_set_y(ui_lblDist, 19);
    lv_obj_set_align(ui_lblDist, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblDist, "10");
    lv_obj_set_style_text_color(ui_lblDist, lv_color_hex(0x090909), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblDist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblDist, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pnlX = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_pnlX, 165);
    lv_obj_set_height(ui_pnlX, 46);
    lv_obj_set_x(ui_pnlX, 0);
    lv_obj_set_y(ui_pnlX, -132);
    lv_obj_set_align(ui_pnlX, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_pnlX, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_pnlX, lv_color_hex(0xCD8405), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pnlX, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, 0);
    lv_obj_set_y(ui_Label1, -133);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "X");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblPosX = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblPosX, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblPosX, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblPosX, -51);
    lv_obj_set_y(ui_lblPosX, -133);
    lv_obj_set_align(ui_lblPosX, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblPosX, "000");
    lv_obj_set_style_text_color(ui_lblPosX, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblPosX, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblPosX, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblTarX = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblTarX, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblTarX, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblTarX, 51);
    lv_obj_set_y(ui_lblTarX, -133);
    lv_obj_set_align(ui_lblTarX, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblTarX, "000");
    lv_obj_set_style_text_color(ui_lblTarX, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblTarX, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblTarX, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pnlY = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_pnlY, 165);
    lv_obj_set_height(ui_pnlY, 46);
    lv_obj_set_x(ui_pnlY, 0);
    lv_obj_set_y(ui_pnlY, -85);
    lv_obj_set_align(ui_pnlY, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_pnlY, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_pnlY, lv_color_hex(0xCD8405), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pnlY, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_plnZ = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_plnZ, 165);
    lv_obj_set_height(ui_plnZ, 46);
    lv_obj_set_x(ui_plnZ, 0);
    lv_obj_set_y(ui_plnZ, -38);
    lv_obj_set_align(ui_plnZ, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_plnZ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_plnZ, lv_color_hex(0xCD8405), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_plnZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 0);
    lv_obj_set_y(ui_Label4, -86);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Y");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, 0);
    lv_obj_set_y(ui_Label5, -38);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "Z");
    lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblPosY = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblPosY, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblPosY, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblPosY, -51);
    lv_obj_set_y(ui_lblPosY, -86);
    lv_obj_set_align(ui_lblPosY, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblPosY, "000");
    lv_obj_set_style_text_color(ui_lblPosY, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblPosY, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblPosY, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblTarY = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblTarY, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblTarY, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblTarY, 51);
    lv_obj_set_y(ui_lblTarY, -86);
    lv_obj_set_align(ui_lblTarY, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblTarY, "000");
    lv_obj_set_style_text_color(ui_lblTarY, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblTarY, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblTarY, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblPosZ = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblPosZ, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblPosZ, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblPosZ, -51);
    lv_obj_set_y(ui_lblPosZ, -38);
    lv_obj_set_align(ui_lblPosZ, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblPosZ, "000");
    lv_obj_set_style_text_color(ui_lblPosZ, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblPosZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblPosZ, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblTarZ = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblTarZ, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblTarZ, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblTarZ, 51);
    lv_obj_set_y(ui_lblTarZ, -38);
    lv_obj_set_align(ui_lblTarZ, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblTarZ, "000");
    lv_obj_set_style_text_color(ui_lblTarZ, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblTarZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblTarZ, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 165);
    lv_obj_set_height(ui_Panel2, 105);
    lv_obj_set_x(ui_Panel2, -1);
    lv_obj_set_y(ui_Panel2, 103);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_lblStatus = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblStatus, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblStatus, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblStatus, 0);
    lv_obj_set_y(ui_lblStatus, 145);
    lv_obj_set_align(ui_lblStatus, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblStatus, "-------");

    ui_imgWifiConnected = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_imgWifiConnected, &ui_img_1228895389);
    lv_obj_set_width(ui_imgWifiConnected, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_imgWifiConnected, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_imgWifiConnected, -66);
    lv_obj_set_y(ui_imgWifiConnected, 67);
    lv_obj_set_align(ui_imgWifiConnected, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_imgWifiConnected, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_imgWifiConnected, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_lblBat = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lblBat, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblBat, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblBat, 58);
    lv_obj_set_y(ui_lblBat, 65);
    lv_obj_set_align(ui_lblBat, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblBat, "4.20V");
    lv_obj_set_style_text_color(ui_lblBat, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblBat, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_lblBat, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_imgWifiDisconnected = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_imgWifiDisconnected, &ui_img_1882247861);
    lv_obj_set_width(ui_imgWifiDisconnected, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_imgWifiDisconnected, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_imgWifiDisconnected, -66);
    lv_obj_set_y(ui_imgWifiDisconnected, 67);
    lv_obj_set_align(ui_imgWifiDisconnected, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_imgWifiDisconnected, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_imgWifiDisconnected, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_BtnDist, ui_event_BtnDist, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pnlX, ui_event_pnlX, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pnlY, ui_event_pnlY, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_plnZ, ui_event_plnZ, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel2, ui_event_Panel2, LV_EVENT_ALL, NULL);

}
