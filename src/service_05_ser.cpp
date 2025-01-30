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
#include "eprom.h"

void on_service_05_ser(String line_in);
void com_ser05_0x00(float com_pwm);
void com_ser05_0x01(float com_pwm);
void com_ser05_0x01(float com_pwm);
void com_ser05_0x02(float com_pwm);
void com_ser05_0x03(float com_pwm);
void com_ser05_0x06(float com_pwm);
void com_ser05_0x0B(float com_pwm);
void save_on_flash_serv5();


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

extern HardwareTimer *tim1;



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

// extern var_grow var_grow_1[30];
// extern var_grow var_grow_2[30];
// extern var_grow var_grow_3[40];
// extern var_grow var_grow_4[40];
extern var_grow var_grow_5[30];
// extern var_grow var_grow_6[30];
// extern var_grow var_grow_7[30];




void on_service_05_ser(String line_in){
    // Serial.println("on service 5");

    split_msg_5(line_in);
    
    float rec_data[5];
    for (int x = 0; x<5; x++){
        rec_data[x] = (retMsg5[x]).toFloat();
        // Serial.print(rec_data[x]);
        // Serial.print(",");
    }
    // Serial.println("");
    int i = rec_data[2]; 
    switch (i) {
        case 0x00:
            // Serial.println("pwm 0x05 0x00 Fan Desum");
            com_ser05_0x00(rec_data[3]);
            break;
        case 0x01:
            // Serial.println("on/off 0x04 0x01 Fan1 Insu");
            com_ser05_0x01(rec_data[3]);
            break;       
         case 0x02:
            // Serial.println("on/off 0x04 0x01 Fan1 Insu");
            com_ser05_0x02(rec_data[3]);
            break;           
        case 0x06:
            // Serial.println("on/off 0x04 0x06 Lights");
            com_ser05_0x06(rec_data[3]);
            break;
    }
    show_display_2();
}

void save_on_flash_serv5(){
    Serial.print("Save Flash");
    uint32_t addr;
    uint32_t data = 0;
    eraseSector(20480);
    for (int i = 0; i <= 2; i++){
        addr = var_grow_5[i].eprom_address;
            data = *var_grow_5[i].var_int; 
            if(writeLong(addr, data)){
                Serial.print("Write 1 OK ");
                Serial.print("save flash: ");
                Serial.print(i);
                Serial.print("Eprom 1 ");
                var_grow_5[i].descr;
                Serial.print(" - ");
                Serial.print(data);
                Serial.print(" - ");
                Serial.print(addr);
                uint8_t ret = read_Byte(addr);
                Serial.print(" - ");
                Serial.println(ret);
            }else{
                Serial.println("Write 1 not OK");
            }
    }
}

void com_ser05_0x00(float com_pwm){
   
}

void com_ser05_0x01(float com_pwm){
    fan1_inf_pwm = com_pwm;
    Serial.println("fan1: "+fan1_inf_pwm);
    if (fan1_inf_on){
        Serial.println("com_pwm_0x01 on");
        tim1->setCaptureCompare(1, fan1_inf_pwm, PERCENT_COMPARE_FORMAT);
    }else{
        Serial.println("com_pwm_0x01 off");
        tim1->setCaptureCompare(1, 0, PERCENT_COMPARE_FORMAT);
    }     
    save_on_flash_serv5();
}

void com_ser05_0x02(float com_pwm){
    fan2_inf_pwm = com_pwm;    
    Serial.println("fan2: "+fan2_inf_pwm);
    if (fan2_inf_on){
        Serial.println("com_pwm_0x02 on");
        tim1->setCaptureCompare(2, fan2_inf_pwm, PERCENT_COMPARE_FORMAT);
    }else{
         Serial.println("com_pwm_0x02 off");
         tim1->setCaptureCompare(2, 0, PERCENT_COMPARE_FORMAT);
    } 
    save_on_flash_serv5();    
}

void com_ser05_0x03(float com_pwm){
    // save_on_flash_serv5();    
}


void com_ser05_0x06(float com_pwm){
    light_pwm = com_pwm;
    
    Serial.println("light1: "+light_pwm);
    if (light_on){
        Serial.println("com_pwm_0x06 on");
        tim1->setCaptureCompare(3, light_pwm, PERCENT_COMPARE_FORMAT);
    }else{
        Serial.println("com_pwm_0x06 off");
        tim1->setCaptureCompare(3, 0, PERCENT_COMPARE_FORMAT);
    }
    save_on_flash_serv5();
    
}

