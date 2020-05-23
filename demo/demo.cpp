/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       james                                                     */
/*    Created:      Sun Sep 15 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "v5lvgl.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;


// define your global instances of motors and other devices here
lv_obj_t * myButton;
lv_obj_t * myButtonLabel;
lv_obj_t * myLabel;

static void btn_click_action(lv_obj_t * btn, lv_event_t event)
{
    uint8_t id = (int)lv_obj_get_user_data(btn); //id usefull when there are multiple buttons

    if(id == 0 && event == LV_EVENT_CLICKED)
    {
  		lv_label_set_text(myLabel, "clicked");
    }

    return ;
}

int demo() {
   static lv_style_t style1;
   lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_WHITE);
   lv_style_set_bg_color(&style1, LV_STATE_PRESSED, LV_COLOR_GRAY);
   lv_style_set_bg_color(&style1, LV_STATE_FOCUSED, LV_COLOR_RED);
   lv_style_set_bg_color(&style1, LV_STATE_FOCUSED | LV_STATE_PRESSED, lv_color_hex(0xf88));

   myButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
   lv_obj_set_user_data(myButton, (lv_font_user_data_t)0); //set button is to 0
   lv_obj_set_event_cb(myButton, btn_click_action); //set function to be called on button click
   lv_obj_add_style(myButton, LV_OBJ_PART_MAIN, &style1);
   lv_obj_set_size(myButton, 200, 50); //set the button size
   lv_obj_align(myButton, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10); //set the position to top mid

    myButtonLabel = lv_label_create(myButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(myButtonLabel, "Click the Button"); //sets label text

    myLabel = lv_label_create(lv_scr_act(), NULL); //create label and puts it on the screen
    lv_label_set_text(myLabel, "Button has not been clicked yet"); //sets label text
    lv_obj_align(myLabel, NULL, LV_ALIGN_IN_LEFT_MID, 10, 0); //set the position to center

    return(0);
}

int main() {
    //int count = 0;
   
    v5_lv_init();
    demo();

    while(1) {
        //Brain.Screen.printAt( 10, 50, "Hello V5 %d", count++ );
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
