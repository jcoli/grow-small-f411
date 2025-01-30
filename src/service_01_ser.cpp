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
#include "schedule.h"
#include "tools.h"
#include "eprom.h"

void on_service_01_ser(String line_in);
void save_on_flash_serv1();
void com_ser01_0x00(int command);
void com_ser01_0x01(int command);
void com_ser01_0x02(int command);
void com_ser01_0x03(int command);
void com_ser01_0x04(int command);
void com_ser01_0x05(int command);
void com_ser01_0x06(int command);
void com_ser01_0x07(int command);
void com_ser01_0x08(int command);
void com_ser01_0x09(int command);
void com_ser01_0x0A(int command);
void com_ser01_0x0B(int command);
void com_ser01_0x0C(int command);
void com_ser01_0x0D(int command);
void com_ser01_0x0E(int command);
void com_ser01_0x0F(int command);
void com_ser01_0x10(int command);
void com_ser01_0x11(int command);
void com_ser01_0x12(int command);
void com_ser01_0x13(int command);
void com_ser01_0x14(int command);
void com_ser01_0x15(int command);
void com_ser01_0x16(int command);
void com_ser01_0x17(int command);
void com_ser01_0x18(int command);
void com_ser01_0x19(int command);
void com_ser01_0x1A(int command);
void com_ser01_0x1B(int command);
void com_ser01_0x1C(int command);
void com_ser01_0x1D(int command);
void com_ser01_0x1E(int command);
void com_ser01_0x1F(int command);
void com_ser01_0x20(int command);
void com_ser01_0x21(int command);
void com_ser01_0x22(int command);
void com_ser01_0x23(int command);
void com_ser01_0x24(int command);
void com_ser01_0x25(int command);
void com_ser01_0xFF(int command);

extern byte minutes;
extern byte hours; 
extern byte weekDay;
extern byte day;
extern byte month;
extern byte year;

extern bool first_run;

extern int language;

//Service 01

extern int temp_int_min_stp;
extern int temp_int_max_stp;

extern int hum_int_on_stp;

extern int hum_int_min_stp;
extern int hum_int_max_stp;


extern int vpd_int_min_stp;
extern int vpd_int_max_stp;

extern int soil_hum_min_stp;
extern int soil_hum_max_stp;
extern int ph_irrig_stp;
extern int ph_hum_stp;

extern int light_hr_on_stp;
extern int light_min_on_stp;
extern int light_hr_off_stp;
extern int light_min_off_stp;

extern int pump_irr_on_stp;
extern int pump_hr_irr_on_stp;
extern int pump_min_irr_on_stp;
extern int pump_hr_irr_off_stp;
extern int pump_min_irr_off_stp;

extern int irr_interval_stp;
extern int irr_time_stp;
extern int irr_interval_on_stp;
extern int irr_on_stp; 


extern int light_pwm_stp;
extern int fan1_inf_pwm_stp;
extern int fan2_inf_pwm_stp;
// extern int fan3_inf_pwm_stp;

extern int fan1_inf_pwm_light_stp;
extern int fan2_inf_pwm_light_stp;
// extern int fan3_inf_pwm_light_stp;

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

extern String line1;
extern String retMsg5[5];

extern var_grow var_grow_1[40];



void on_service_01_ser(String line_in){
    split_msg_5(line1);
    int i = toHexc(retMsg5[2]);
    // Serial.println("Receive Service 1");

     switch (i) {
        case 0x00:
            // Serial.println("Status Temp Ext 0x03 0x00");
            com_ser01_0x00(retMsg5[3].toInt()); 
            break;
        case 0x01:
            // Serial.println("Status Temp int 0x03 0x01");
            com_ser01_0x01(retMsg5[3].toInt());
            break;    
        case 0x02:
            // Serial.println("Status Hum Ext 0x03 0x02");
            com_ser01_0x02(retMsg5[3].toInt());
            break;
        case 0x03:
            // Serial.println("Status Hum Ext 0x03 0x03");
            com_ser01_0x03(retMsg5[3].toInt());
            break;    
        case 0x04:
            // Serial.println("Status C02 Ext 0x03 0x04");
            com_ser01_0x04(retMsg5[3].toInt());
            break;    
        case 0x05:
            // Serial.println("Status C02 int 0x03 0x05");
            com_ser01_0x05(retMsg5[3].toInt());
            break;    
        case 0x06:
            // Serial.println("Status Fan desum 0x03 0x06");
            com_ser01_0x06(retMsg5[3].toInt());
            break;    
        case 0x07:
            // Serial.println("Status Fan1 0x03 0x07");
            com_ser01_0x07(retMsg5[3].toInt());
            break;    
        case 0x08:
            // Serial.println("Status Fan2 0x03 0x08");
            com_ser01_0x08(retMsg5[3].toInt());
            break;    
        case 0x09:
            // Serial.println("Status Light 0x03 0x09");
            com_ser01_0x09(retMsg5[3].toInt());
            break;    
        case 0x0A:
            // Serial.println("Status Fan Peltier Insu 0x03 0x0A");
            com_ser01_0x0A(retMsg5[3].toInt());
            break;    
        case 0x0B:
            // Serial.println("Status Fan Peltier Desum 0x03 0x0B");
            com_ser01_0x0B(retMsg5[3].toInt());
            break;    
        case 0x0C:
            // Serial.println("Status Light 0x03 0x0C");
            com_ser01_0x0C(retMsg5[3].toInt());
            break;
        case 0x0D:
            // Serial.println("Status Door 0x03 0x0D");
            com_ser01_0x0D(retMsg5[3].toInt());
            break;       
        case 0x0E:
            // Serial.println("Status Water Level irrigation 0x03 0x0E");
            com_ser01_0x0E(retMsg5[3].toInt());
            break;
        case 0x0F:
            // Serial.println("Status Water Level Hum 0x03 0x0F");
            com_ser01_0x0F(retMsg5[3].toInt());
            break;         
        case 0x10:
            // Serial.println("Status Fan Petier 0x03 0x10");
            com_ser01_0x10(retMsg5[3].toInt());
            break;
        case 0x11:
            // Serial.println("Status Fan Petier 0x03 0x11");
            com_ser01_0x11(retMsg5[3].toInt());
            break;
        // case 0x12:
        //     // Serial.println("Status Pump Desum 0x03 0x12");
        //     com_ser01_0x12(retMsg5[3].toInt());
        //     break;
        // case 0x13:
        //     // Serial.println("Status Pump Insu 0x03 0x13");
        //     com_ser01_0x13(retMsg5[3].toInt());
        //     break;
        // case 0x14:
        //     // Serial.println("Status Pump Insu 0x03 0x13");
        //     com_ser01_0x14(retMsg5[3].toInt());
        //     break;    
        // case 0x15:
        //     // Serial.println("Status Pump Insu 0x03 0x13");
        //     com_ser01_0x15(retMsg5[3].toInt());
        //     break;    
        case 0x16:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x16(retMsg5[3].toInt());
            break;    
        case 0x17:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x17(retMsg5[3].toInt());
            break;    
        case 0x18:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x18(retMsg5[3].toInt());
            break;    
        case 0x19:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x19(retMsg5[3].toInt());
            break;    
        case 0x1A:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x1A(retMsg5[3].toInt());
            break;    
        case 0x1B:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x1B(retMsg5[3].toInt());
            break;    
        case 0x1C:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x1C(retMsg5[3].toInt());
            break;    
        case 0x1D:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x1D(retMsg5[3].toInt());
            break;    
        case 0x1E:
            // Serial.println("Status Pump Insu 0x03 0x13");
            com_ser01_0x1E(retMsg5[3].toInt());
            break;    
        // case 0x1F:
        //     // Serial.println("Status Pump Insu 0x03 0x13");
        //     com_ser01_0x1F(retMsg5[3].toInt());
        //     break;    
        case 0xFF:
            Serial.println("Save Flash");
            com_ser01_0xFF(retMsg5[3].toInt());
            break;              
        
     }
}

void save_on_flash_serv1(){
    Serial.print("Save Flash");
    uint32_t addr;
    uint32_t data = 0;
    eraseSector(var_grow_1[0].eprom_address);
    for (int i = 0; i <= 35; i++){
        addr = var_grow_1[i].eprom_address;
        data = *var_grow_1[i].var_int; 
        Serial.print("Eprom 1 ");
        Serial.print(i);

        Serial.print(" - ");
        Serial.print(data);
        Serial.print(" - ");

        if((writeShort(addr, data))){
                Serial.print("Write 1 OK ");
                Serial.print("save flash: ");
                Serial.print(i);
                Serial.print("Eprom 1 ");
                Serial.print(var_grow_1[i].descr);
                Serial.print(" - ");
                Serial.print(data);
                Serial.print(" - ");
                Serial.print(addr);
                uint8_t ret = read_Byte(addr);
                Serial.print(" - ");
                Serial.println(ret);
                delay(100);
        }else{
                Serial.println("Write 1 not OK");
                Serial.print("Eprom 1 ");
                Serial.print(var_grow_1[i].descr);
                Serial.print(" - ");
                Serial.print(data);
                Serial.print(" - ");
                Serial.print(addr);
        }
    }
}

void com_ser01_0x00(int command){
    Serial.println("serv 01 - 00");
    temp_int_max_stp = command;    
}

void com_ser01_0x01(int command){
    Serial.println("serv 01 - 01");
    temp_int_min_stp = command;
}

void com_ser01_0x02(int command){
    Serial.println("serv 01 - 02");
    hum_int_max_stp = command;
}

void com_ser01_0x03(int command){
    Serial.println("serv 01 - 03");
    hum_int_min_stp = command;    
}

void com_ser01_0x04(int command){
    Serial.println("serv 01 - 04");
    soil_hum_max_stp = command;
}

void com_ser01_0x05(int command){
    Serial.println("serv 01 - 05");
    soil_hum_min_stp = command;
}

void com_ser01_0x06(int command){
    Serial.println("serv 01 - 06");
    ph_irrig_stp  = command;
}

void com_ser01_0x07(int command){
    Serial.println("serv 01 - 07");
    ph_hum_stp = command;
}

void com_ser01_0x08(int command){
    Serial.println("serv 01 - 08");
    light_hr_on_stp = command;
}

void com_ser01_0x09(int command){
    Serial.println("serv 01 - 09");
    light_min_on_stp = command;
}

void com_ser01_0x0A(int command){
    Serial.println("serv 01 - 0A");
    light_hr_off_stp = command;
}

void com_ser01_0x0B(int command){
    Serial.println("serv 01 - 0B");
    light_min_off_stp = command;
}

void com_ser01_0x0C(int command){
    Serial.println("serv 01 - 0C");
    pump_hr_irr_on_stp = command;
}

void com_ser01_0x0D(int command){
    Serial.println("serv 01 - 0D");
    pump_min_irr_on_stp = command;    
}

void com_ser01_0x0E(int command){
    Serial.println("serv 01 - 0E");
    pump_hr_irr_off_stp = command;
}

void com_ser01_0x0F(int command){
    Serial.println("serv 01 - 0F");
    pump_min_irr_off_stp = command;
}

void com_ser01_0x10(int command){
    Serial.println("serv 01 - 10");
    irr_interval_stp = command;
}

void com_ser01_0x11(int command){
    Serial.println("serv 01 - 11");
    irr_time_stp = command*1000;    
}

void com_ser01_0x16(int command){
    Serial.println("serv 01 - 16");
    light_pwm_stp = command;
}

void com_ser01_0x17(int command){
    Serial.println("serv 01 - 17");
    fan1_inf_pwm_stp = command;
}

void com_ser01_0x18(int command){
    Serial.println("serv 01 - 18");
    fan2_inf_pwm_stp = command;
}

void com_ser01_0x19(int command){
    Serial.println("serv 01 - 19");
   
}

void com_ser01_0x1A(int command){
    Serial.println("serv 01 - 1A");
    fan1_inf_pwm_light_stp = command;
}

void com_ser01_0x1B(int command){
    Serial.println("serv 01 - 1B");
    fan2_inf_pwm_light_stp = command;
}

void com_ser01_0x1C(int command){
    Serial.println("serv 01 - 1C");
   
}

void com_ser01_0x1D(int command){
    Serial.println("serv 01 - 1D");
    irr_on_stp = command;
}

void com_ser01_0x1E(int command){
    Serial.println("serv 01 - 1E");
    hum_int_on_stp = command;
}

void com_ser01_0xFF(int command){
    Serial.println("serv 01 - FF");
    save_on_flash_serv1();
}  

