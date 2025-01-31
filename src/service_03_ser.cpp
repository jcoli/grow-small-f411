/**
Version: 0a
Tecnocoli - 08/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F103C8 - Grow Sensors
**/

#include <Arduino.h>
#include <SPI.h>

#include "defines.h"
#include "io_defines.h"
#include "display.h"
#include "structures.h"
#include "defines_protocol.h"
#include "tools.h" 

void on_service_03_ser(String line_in);
void com_ser03_0x00(String line_in);
void com_ser03_0x01(String line_in);
void com_ser03_0x01(String line_in);
void com_ser03_0x02(String line_in);
void com_ser03_0x03(String line_in);
void com_ser03_0x04(String line_in);
void com_ser03_0x05(String line_in);
void com_ser03_0x06(String line_in);
void com_ser03_0x07(String line_in);
void com_ser03_0x08(String line_in);
void com_ser03_0x09(String line_in);
void com_ser03_0x0A(String line_in);
void com_ser03_0x0B(String line_in);
void com_ser03_0x0C(String line_in);
void com_ser03_0x0D(String line_in);
void com_ser03_0x0E(String line_in);
void com_ser03_0x0F(String line_in);
void com_ser03_0x10(String line_in);
void com_ser03_0x11(String line_in);
void com_ser03_0x12(String line_in);
void com_ser03_0x13(String line_in);
void com_ser03_0x14(String line_in);
void com_ser03_0x15(String line_in);
void com_ser03_0x16(String line_in);
void com_ser03_0x17(String line_in);
void com_ser03_0x21(String line_in);
void com_ser03_0x22(String line_in);
void com_ser03_0x23(String line_in);

extern bool first_run;

extern int language;

extern byte minutes;
extern byte hours; 
extern byte weekDay;
extern byte day;
extern byte month;
extern byte year;

extern bool first_run;

extern int language;

//Service 01
extern int temp_int_stp;
extern int hum_int_stp;
extern int soil_hum_stp;
extern int ph_irrig_stp;
extern int ph_hum_stp;
extern int light_hr_on_stp;
extern int light_min_on_stp;
extern int light_hr_off_stp;
extern int light_min_off_stp;
extern int pump_hr_irr_on_stp;
extern int pump_min_irr_on_stp;
extern int pump_hr_irr_off_stp;
extern int pump_min_irr_off_stp;
extern int irr_interval_stp;
extern int irr_1_hr_stp;
extern int irr_1_min_stp;
extern int irr_2_hr_stp;
extern int irr_2_min_stp;
extern int irr_3_hr_stp;
extern int irr_3_min_stp;
extern int irr_4_hr_stp;
extern int irr_4_min_stp;
extern int irr_5_hr_stp;
extern int irr_5_min_stp;
extern int irr_6_hr_stp;
extern int irr_6_min_stp;
extern int light_pwm_stp;
extern int fan1_inf_pwm_stp;
extern int fan2_inf_pwm_stp;
// extern int fan3_inf_pwm_stp;

//Service 02
extern float eco2_ext;
extern float eco2_int;
extern float temp_ext;
extern float hum_ext;
extern float temp_ext;
extern float temp_int;
extern float hum_int;
extern float soil_1_hum;
extern float soil_2_hum;
extern float soil_3_hum;
extern float soil_4_hum;
extern float light_1_int;

//Service 03
extern bool water_irrig_1_level;
extern bool water_hum_1_level;
extern bool door;
extern bool wifi_connected;
extern bool mqtt_connected;
extern bool bt_connected;

//Service 04
extern bool fan_dehum_on;
extern bool fan1_inf_on;
extern bool fan2_inf_on;
extern bool fan3_inf_on;

extern bool fan_hum_on;
extern bool light_on;
extern bool pump_irr_on;
extern bool hum_on;

extern bool relay_1_on;
extern bool relay_2_on;


extern bool hum_1_on;

//Service 05
extern int fan1_inf_pwm;
extern int fan2_inf_pwm;
extern int light_pwm;
extern int hum_1_pwm;


// extern bool soil_hum_dig;

// extern bool ch_page;
// extern bool ch_page_ana;
// extern int tft_page;
// extern int tft_page_ant;
// extern int tft_sub_page;
// extern int tft_sub_page_ant;
// extern int draw_tab;
// extern int draw_page;

// extern String line;
extern String line1;
// extern String line2;
// extern String retMsg2[2];
// extern String retMsg3[3];
// extern String retMsg4[4];
extern String retMsg5[5];
// extern String retMsg6[6];
// extern String retMsg7[7];
// extern String retMsg8[8];
// extern String retMsg9[9];
// extern String retMsg10[10];

// extern var_grow var_grow_1[50];
// extern var_grow var_grow_2[40];
extern var_grow var_grow_3[40];
// extern var_grow var_grow_4[40];
// extern var_grow var_grow_5[30];
// extern var_grow var_grow_6[30];
// extern var_grow var_grow_7[30];

void on_service_03_ser(String line_in){

    split_msg_5(line_in);
    int i = toHexc(retMsg5[2]);

    switch (i) {
        
        case 0x06:
            // Serial.println("Status Fan desum 0x03 0x06");
            com_ser03_0x06(retMsg5[3]);
            break;    
        case 0x07:
            // Serial.println("Status Fan1 0x03 0x07");
            com_ser03_0x07(retMsg5[3]);
            break;    
        case 0x0D:
            // Serial.println("Status Door 0x03 0x0D");
            com_ser03_0x0D(retMsg5[3]);
            break;       
        case 0x21:
            // Serial.println("Status WiFi 0x03 0x21");
            com_ser03_0x21(retMsg5[3]);
            break;                        
        case 0x22:
            // Serial.println("Status BlueTooth 0x03 0x22");
            com_ser03_0x22(retMsg5[3]);
            break;
        case 0x23:
            // Serial.println("Status MQTT 0x03 0x21");
            com_ser03_0x23(retMsg5[3]);
            break;    
     }
    
    // tft_page = 0;
    // ch_page = true;
    // draw_tab = 0;
    // draw_page = 0;
    // draw_page0();
   
}


void com_ser03_0x06(String command){
    if (command.equals("1")){
        water_irrig_1_level = true;
    }else{
        water_irrig_1_level = false;
    }
}    
void com_ser03_0x07(String command){
    if (command.equals("1")){
        water_hum_1_level = true;
    }else{
        water_hum_1_level = false;
    }
}    
void com_ser03_0x0D(String command){
    // if (command.equals("1")){
    //     door = true;
    // }else{
    //     door = false;
    // }
    // if (door){
    //     Serial.println("door: close");
    // }else{
    //     Serial.println("door: open");
    // }
}    
void com_ser03_0x21(String command){
    
    // if (command.equals("1")){
    //     wifi_connected = true;
    //     // Serial.println("com_ser04_0x21 true");
    // }else{
    //     wifi_connected = false;
    //     // Serial.println("com_ser04_0x21 false");
    // }
    // sendValuesBoolean(0x33A, 0x03, 0x21, wifi_connected);    
}    
void com_ser03_0x22(String command){
    
    if (command.equals("1")){
        bt_connected = true;
        // Serial.println("com_ser04_0x22 true");
    }else{
        bt_connected = false;
        // Serial.println("com_ser04_0x22 false");
    }
    // sendValuesBoolean(0x33A, 0x03, 0x22, bt_connected);    
}    
void com_ser03_0x23(String command){
    // Serial.println("com_ser04_0x23");
    // if (command.equals("1")){
    //     mqtt_connected = true;
    //     // Serial.println("com_ser04_0x23 true");
    // }else{
    //     mqtt_connected = false;
    //     // Serial.println("com_ser04_0x23 false");
    // }
    // sendValuesBoolean(0x33A, 0x03, 0x23, mqtt_connected);    
}    


