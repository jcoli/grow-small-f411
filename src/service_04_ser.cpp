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

void on_service_04_ser(String line_in);
void save_on_flash_serv4();
void com_ser04_0x00(String line_in);
void com_ser04_0x01(String line_in);
void com_ser04_0x01(String line_in);
void com_ser04_0x02(String line_in); 
void com_ser04_0x03(String line_in);
void com_ser04_0x06(String line_in);
void com_ser04_0x0B(String line_in);
void com_ser04_0x0C(String line_in);
void com_ser04_0x0D(String line_in);
void com_ser04_0x0E(String line_in);
void com_ser04_0x0F(String line_in);
void com_ser04_0x10(String line_in);
void com_ser04_0x11(String line_in);
void com_ser04_0x12(String line_in);
void com_ser04_0x13(String line_in);
void com_ser04_0x14(String line_in);
void com_ser04_0x15(String line_in);
void com_ser04_0x16(String line_in);
void com_ser04_0x17(String line_in);

extern byte minutes;
extern byte hours; 
extern byte weekDay;
extern byte day;
extern byte month;
extern byte year;

extern unsigned long loopDelay_pump;

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

extern int relay_red[4];


//Service 02
extern float temp_ext;
extern float hum_ext;
extern float temp_ext;
extern float temp_int;
extern float hum_int;
extern float soil_1_hum;
extern float light_1_int;

//Service 03
extern bool water_irrig_1_level;
extern bool water_hum_1_level;
extern bool bt_connected;

//Service 04
extern bool fan1_inf_on;
extern bool fan2_inf_on;
extern bool light_on;
extern bool pump_irr_on;
extern bool hum_1_on;
extern bool relay_1_on;
extern bool relay_2_on;

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

// extern var_grow var_grow_1[50];
// extern var_grow var_grow_2[40];
// extern var_grow var_grow_3[40];
extern var_grow var_grow_4[40];
// extern var_grow var_grow_5[30];
// extern var_grow var_grow_6[30];
// extern var_grow var_grow_7[30];


void on_service_04_ser(String line_in){
 
    split_msg_5(line1);
    int i = toHexc(retMsg5[2]);

    switch (i) {
        case 0x00:
            // Serial.println("on/off 0x04 0x00 Fan Desum");
            com_ser04_0x00(retMsg5[3]);
            break;
        case 0x01:
            // Serial.println("on/off 0x04 0x01 Fan1 Insu");
            com_ser04_0x01(retMsg5[3]);
            break;       
        case 0x02:
            // Serial.println("on/off 0x04 0x02 Fan2 Insu");
            com_ser04_0x02(retMsg5[3]);
            break;
        case 0x06:
            // Serial.println("on/off 0x04 0x06 Lights");
            com_ser04_0x06(retMsg5[3]);
            break;
        case 0x0B:
            // Serial.println("on/off 0x04 0x0B Bomba Rega");
            com_ser04_0x0B(retMsg5[3]);
            break;                        
        case 0x0C:
            // Serial.println("on/off 0x04 0x0B Um");
            com_ser04_0x0C(retMsg5[3]);
            break;                        
        case 0x0D:
            // Serial.println("on/off 0x04 0x0D");
            com_ser04_0x0D(retMsg5[3]);
            break;
        case 0x0E:
            // Serial.println("on/off 0x04 0x0E");
            com_ser04_0x0E(retMsg5[3]);
            break;    
        case 0x0F:
            // Serial.println("on/off 0x04 0x0F");   
            com_ser04_0x0F(retMsg5[3]);
            break;    
        case 0x10:
            // Serial.println("on/off 0x04 0x0F");   
            com_ser04_0x10(retMsg5[3]);
            break;        
        case 0x11:
            // Serial.println("on/off 0x04 0x0F");   
            com_ser04_0x11(retMsg5[3]);
            break;       
        case 0x12:
            // Serial.println("on/off 0x04 0x0F");   
            com_ser04_0x12(retMsg5[3]);
            break;
        case 0x13:
            // Serial.println("on/off 0x04 0x0F");   
            com_ser04_0x13(retMsg5[3]);
            break;
     }
     show_display_2();
    
}

void save_on_flash_serv4(){
    Serial.print("Save Flash");
    uint32_t addr;
    uint8_t data = 0;
    eraseSector(12288);
    for (int i = 0; i <= 6; i++){
        addr = var_grow_4[i].eprom_address;
        if (*var_grow_4[i].var_bool){
            data = 255; 
            if(writeByte(addr, data)){
                    Serial.print("Write 1 OK ");
                    // Serial.print("save flash: ");
                    // Serial.println(i);
                    // Serial.print("Eprom 1 ");
                    Serial.print(data, BIN);
                    Serial.print(", ");
                    // Serial.println(addr);
                    uint8_t ret = read_Byte(addr);
                    // Serial.print("Eprom 1 ");
                    Serial.println(ret, BIN);
            }else{
                    Serial.println("Write 1 not OK");
            }
        }else{
            data = 0;
            if(writeByte(addr, data)){
                
                Serial.println("Write 0 OK ");
                // Serial.print("save flash: ");
                // Serial.println(i);
                // Serial.print("Eprom 1 ");
                Serial.print(data, BIN);
                Serial.print(", ");
                // Serial.println(addr);
                uint8_t ret = read_Byte(addr);
                // Serial.print("Eprom 1 ");
                Serial.println(ret, BIN);
            }else{
                Serial.println("Write 0 Not OK");
            }
        }
    }
    
}

void com_ser04_0x00(String command){
    
}
//1 - Fan1, 2 - Fan2, 3 - light, 4 - Rega, 5 - Umidificador
void com_ser04_0x01(String command){
    Serial.println("Fan1");
    if (command.equals("1")){
        fan1_inf_on = true;
        tim1->setCaptureCompare(1, fan1_inf_pwm, PERCENT_COMPARE_FORMAT);
        for (int i = 0; i <= 3; i++){
            if (relay_red[i] == 1){
                if (i==0) com_ser04_0x0E("1");
                if (i==1) com_ser04_0x0F("1");
                if (i==2) com_ser04_0x10("1");
                if (i==3) com_ser04_0x11("1");
            }
        }
        Serial.println("com_0x01 on");
    }else{
        fan1_inf_on = false;
        tim1->setCaptureCompare(1, 0, PERCENT_COMPARE_FORMAT);
        for (int i = 0; i <= 3; i++){
            if (relay_red[i] == 1){
                if (i==0) com_ser04_0x0E("0");
                if (i==1) com_ser04_0x0F("0");
                if (i==2) com_ser04_0x10("0");
                if (i==3) com_ser04_0x11("0");
            }
        }
        Serial.println("com_0x01 off");
    } 
    // digitalWrite(FAN01, fan1_inf_on);  
    save_on_flash_serv4();
}
//1 - Fan1, 2 - Fan2, 3 - light, 4 - Rega, 5 - Umidificador
void com_ser04_0x02(String command){
    Serial.println("Fan2");
    if (command.equals("1")){
        fan2_inf_on = true;
        tim1->setCaptureCompare(2, fan2_inf_pwm, PERCENT_COMPARE_FORMAT);
        for (int i = 0; i <= 3; i++){
            if (relay_red[i] == 2){
                if (i==0) com_ser04_0x0E("1");
                if (i==1) com_ser04_0x0F("1");
                if (i==2) com_ser04_0x10("1");
                if (i==3) com_ser04_0x11("1");
            }
        }
        Serial.println("com_0x02 on");
      }else{
        fan2_inf_on = false;
        tim1->setCaptureCompare(2, 0, PERCENT_COMPARE_FORMAT);
        for (int i = 0; i <= 3; i++){
            if (relay_red[i] == 2){
                if (i==0) com_ser04_0x0E("0");
                if (i==1) com_ser04_0x0F("0");
                if (i==2) com_ser04_0x10("0");
                if (i==3) com_ser04_0x11("0");
            }
        }
        Serial.println("com_0x02 off");
    }    
    // digitalWrite(FAN02, fan2_inf_on);
    save_on_flash_serv4();
}
//1 - Fan1, 2 - Fan2, 3 - light, 4 - Rega, 5 - Umidificador
void com_ser04_0x06(String command){
    Serial.println("Light");
    if (command.equals("1")){
        light_on = true;
        tim1->setCaptureCompare(3, light_pwm, PERCENT_COMPARE_FORMAT);
        for (int i = 0; i <= 3; i++){
            Serial.print("Light Relay: ");
            Serial.print(i);
            Serial.print(", ");
            Serial.println(relay_red[i]);
            if (relay_red[i] == 3){
                Serial.println("Light Relay");
                if (i==0) com_ser04_0x0E("1");
                if (i==1) com_ser04_0x0F("1");
                if (i==2) com_ser04_0x10("1");
                if (i==3) com_ser04_0x11("1");
            }
        }
        Serial.println("com_0x06 on");
    }else{
        light_on = false;
        tim1->setCaptureCompare(3, 0, PERCENT_COMPARE_FORMAT);
        for (int i = 0; i <= 3; i++){
            Serial.print("Light Relay: ");
            Serial.print(i);
            Serial.print(", ");
            Serial.println(relay_red[i]);
            if (relay_red[i] == 3){
                Serial.println("Light Relay");
                if (i==0) com_ser04_0x0E("0");
                if (i==1) com_ser04_0x0F("0");
                if (i==2) com_ser04_0x10("0");
                if (i==3) com_ser04_0x11("0");
            }
        }
        Serial.println("com_0x06 off");
    }    
    // digitalWrite(LIGHTS, light_on);
    save_on_flash_serv4();
}
//1 - Fan1, 2 - Fan2, 3 - light, 4 - Rega, 5 - Umidificador
void com_ser04_0x0B(String command){
    Serial.println("Rega");
    if (command.equals("1")){
        pump_irr_on= true;
        Serial.println("com_0x0B on");
        for (int i = 0; i <= 3; i++){
            if (relay_red[i] == 4){
                if (i==0) com_ser04_0x0E("1");
                if (i==1) com_ser04_0x0F("1");
                if (i==2) com_ser04_0x10("1");
                if (i==3) com_ser04_0x11("1");
            }
        }
    }else{
        pump_irr_on = false;
        Serial.println("com_0x0B off");
        for (int i = 0; i <= 3; i++){
            if (relay_red[i] == 4){
                if (i==0) com_ser04_0x0E("0");
                if (i==1) com_ser04_0x0F("0");
                if (i==2) com_ser04_0x10("0");
                if (i==3) com_ser04_0x11("0");
            }
        }
    }    
    save_on_flash_serv4();
    digitalWrite(PUMP1, pump_irr_on);
    loopDelay_pump = millis();
}
//1 - Fan1, 2 - Fan2, 3 - light, 4 - Rega, 5 - Umidificador
void com_ser04_0x0C(String command){
    Serial.println("Hum");
    if (command.equals("1")){
        hum_1_on = true;
        Serial.println("com_0x0C on");
        for (int i = 0; i <= 3; i++){
            if (relay_red[i] == 5){
                if (i==0) com_ser04_0x0E("1");
                if (i==1) com_ser04_0x0F("1");
                if (i==2) com_ser04_0x10("1");
                if (i==3) com_ser04_0x11("1");
            }
        }
    }else{
        hum_1_on = false;
        Serial.println("com_0x0C off");
        for (int i = 0; i <= 3; i++){
            if (relay_red[i] == 5){
                if (i==0) com_ser04_0x0E("0");
                if (i==1) com_ser04_0x0F("0");
                if (i==2) com_ser04_0x10("0");
                if (i==3) com_ser04_0x11("0");
            }
        }
    }    
    save_on_flash_serv4();
    digitalWrite(HUM, hum_1_on);

}
//1 - Fan1, 2 - Fan2, 3 - light, 4 - Rega, 5 - Umidificador
void com_ser04_0x0D(String command){
    Serial.println("Desum");
    // if (command.equals("1")){
    //     dehum_1_on = true;
    // }else{
    //     dehum_1_on = false;
    // }    
    // save_on_flash_serv4();
}

void com_ser04_0x0E(String command){
    Serial.println("Relay 1");
    if (command.equals("1")){
        relay_1_on = true;
        Serial.println("com_0x0E on");
    }else{
        relay_1_on = false;
        Serial.println("com_0x0E off");
    }    
    save_on_flash_serv4();
    digitalWrite(RELAY1, !relay_1_on);
}

void com_ser04_0x0F(String command){
    Serial.println("Relay 2");
    if (command.equals("1")){
        relay_2_on = true;
        Serial.println("com_0x0F on");
    }else{
        relay_2_on = false;
        Serial.println("com_0x0F off");
    }    
    save_on_flash_serv4();
    digitalWrite(RELAY2, !relay_2_on);
}

void com_ser04_0x10(String command){
    Serial.println("Relay 3");
    // if (command.equals("1")){
    //     relay_3_on = true;
    // }else{
    //     relay_3_on = false;
    // }    
    // save_on_flash_serv4();
}

void com_ser04_0x11(String command){
    Serial.println("Relay 4");
    // if (command.equals("1")){
    //     relay_4_on = true;
    // }else{
    //     relay_4_on = false;
    // }    
    // sendValuesBoolean(CANID_OUTPUT , 0x04, 0x11, *var_grow_4[11].var_bool );
    // save_on_flash_serv4();
}

void com_ser04_0x12(String command){
    // if (command.equals("1")){
    //     output_1_on = true;
    // }else{
    //     output_1_on = false;
    // }    
    // sendValuesBoolean(CANID_OUTPUT , 0x04, 0x12, *var_grow_4[12].var_bool );
    // save_on_flash_serv4();
}

void com_ser04_0x13(String command){
    // if (command.equals("1")){
    //     output_2_on = true;
    // }else{
    //     output_2_on = false;
    // }    
    // sendValuesBoolean(CANID_OUTPUT , 0x04, 0x13, *var_grow_4[13].var_bool );
    // save_on_flash_serv4();
}




