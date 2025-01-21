/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#include <Arduino.h>

#include "defines.h"
#include "tools.h"
#include "eprom.h"
#include "structures.h"


void program_begin();
void vpd_calculate();
void append_struct_life_bit(); 
bool eraseDataSetup();
void avg_calculate();

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

extern bool water_irrig_1_level;
extern bool water_hum_1_level;

extern bool fan_dehum_on;
extern bool fan1_inf_on;
extern bool fan2_inf_on;
extern bool fan3_inf_on;

extern bool fan_hum_on;
extern bool light_on;
extern bool pump_irr_on;
extern bool hum_1_on;

extern bool relay_1_on;
extern bool relay_2_on;
extern bool relay_3_on;
extern bool relay_4_on;
extern bool output_1_on;
extern bool output_2_on;

extern bool soil_hum_dig;

extern bool door;
extern bool wifi_connected;
extern bool mqtt_connected;
extern bool bt_connected;

extern int fan1_inf_pwm;
extern int fan2_inf_pwm;
extern int light_pwm;
extern int hum_1_pwm;


extern float VRef;
extern float intTemp;

extern bool first_run;
extern bool scheduleRun;

extern float actual_vpd;
extern float avg_vpd_int;
extern float sum_vpd_int;

extern float avg_temp_int;
extern float sum_temp_int;

extern float avg_hum_int;
extern float sum_hum_int;

extern var_grow var_grow_1[30];
extern var_grow var_grow_2[30];
extern var_grow var_grow_3[40];
extern var_grow var_grow_4[40];
extern var_grow var_grow_5[30];
extern var_grow var_grow_6[30];
extern var_grow var_grow_7[30];

bool eraseDataSetup(){
    int32_t addr = var_grow_4[0].eprom_address;
    eraseSector(addr);
    return true;
}




void program_begin(){
   
    uint32_t addr;
    uint8_t data = 0;
    uint32_t data_int = 0;
    // sendValuesFloat(CANID_OUTPUT , 0x05, 0x01, 100);
    // sendValuesFloat(CANID_OUTPUT , 0x05, 0x02, 100);
    for (int i = 0; i < 6; i++){
        addr = var_grow_5[i].eprom_address;
        data_int = read_int(addr);
        *var_grow_5[i].var_int = data_int;
        Serial.print("Program PWM ");
        Serial.print(var_grow_5[i].descr);
        Serial.print(", ");
        Serial.print(addr);
        Serial.print(", ");
        Serial.println(data_int);
        // sendValuesFloat(CANID_OUTPUT , var_grow_5[i].service, var_grow_5[i].pid, *var_grow_5[i].var_int);
        // Serial.print(CANID_OUTPUT, HEX);
        Serial.print(" - ");
        Serial.print(var_grow_5[i].service, HEX);
        Serial.print(" - ");
        Serial.print(var_grow_5[i].pid, HEX);
        Serial.print(" - ");
        Serial.println(*var_grow_5[i].var_int);
        delay(300);
    }
    for (int i = 0; i < 14; i++){
        addr = var_grow_4[i].eprom_address;
        uint8_t data = read_Byte(addr);
        *var_grow_4[i].var_bool = data;

        Serial.print("Program ON/OFF ");
        Serial.print(var_grow_4[i].descr);
        Serial.print(", ");
        Serial.print(addr);
        Serial.print(", ");
        Serial.println(data, BIN);
        // sendValuesBoolean(CANID_OUTPUT , var_grow_4[i].service, var_grow_4[i].pid, *var_grow_4[i].var_bool);
        delay(300);
        
    }  
    
    scheduleRun = true;  
    // sendValuesBoolean(CANID_OUTPUT , 0x04, 0x02, ret);
}

void avg_calculate(){
     if ((hum_int>0) && (temp_int>0)){
        if (sum_hum_int == 0){
            sum_hum_int = hum_int * 100;
        }
        if (sum_temp_int==0){
            sum_temp_int = temp_int *100; 
        }
        if (sum_vpd_int==0){
           sum_vpd_int = actual_vpd * 100;
        }
        if (sum_hum_int>0){
            avg_hum_int = sum_hum_int/100;
        }
        if (sum_temp_int>0){
            avg_temp_int = sum_temp_int/100;
        }
        if (sum_vpd_int>0){
            avg_vpd_int = sum_vpd_int/100;
        }
    }
}

void vpd_calculate(){
    if ((temp_int>0) && (hum_int>0)){
        float es = 0.6108 * exp((17.27 * temp_int) / (temp_int + 237.3));
        float ea = es * (hum_int / 100.0);
        actual_vpd = es - ea;
    
        if ((sum_hum_int>0) && (sum_temp_int>0) && (sum_vpd_int>0)){
            sum_hum_int = sum_hum_int - avg_hum_int + hum_int;
            sum_temp_int = sum_temp_int - avg_temp_int + temp_int;
            sum_vpd_int = sum_vpd_int - avg_vpd_int + actual_vpd;
        }    
        if ((avg_hum_int>0) && (avg_temp_int>0) && (avg_vpd_int>0)){

            avg_hum_int = sum_hum_int/100;
            avg_temp_int = sum_temp_int/100;
            avg_vpd_int = sum_vpd_int/100;

            // Serial.print("hum medio: ");
            // Serial.print(avg_hum_int);
            // Serial.println(" %");
            // Serial.print("temp medio: ");
            // Serial.print(avg_temp_int);
            // Serial.println(" C");
            // Serial.print("VPD: ");
            // Serial.print(actual_vpd);
            // Serial.println(" kPa");
            // Serial.print("VPD Medio: ");
            // Serial.print(avg_vpd_int);
            // Serial.println(" kPa");
        }  
    }
    

}

// void append_struct_life_bit(){

//     life_bit_com[0].ind = 0;
//     life_bit_com[0].can_id_remote = CANID_MASTER;
//     life_bit_com[0].ackReceived = false;
//     life_bit_com[0].network = net_can;
//     life_bit_com[0].timeoutInterval = 0;
    
//     life_bit_com[1].ind = 1;
//     life_bit_com[1].can_id_remote = CANID_SENSOR;
//     life_bit_com[1].ackReceived = false;
//     life_bit_com[1].network = net_can;
//     life_bit_com[1].timeoutInterval = 0;

//     life_bit_com[2].ind = 2;
//     life_bit_com[2].can_id_remote = CANID_LIGHTS;
//     life_bit_com[2].ackReceived = false;
//     life_bit_com[2].network = net_can;
//     life_bit_com[2].timeoutInterval = 0;

//     life_bit_com[3].ind = 3;
//     life_bit_com[3].can_id_remote = CANID_OUTPUT;
//     life_bit_com[3].ackReceived = false;
//     life_bit_com[3].network = net_can;
//     life_bit_com[3].timeoutInterval = 0;

//     life_bit_com[4].ind = 4;
//     life_bit_com[4].can_id_remote = CANID_IRRIG;
//     life_bit_com[4].ackReceived = false;
//     life_bit_com[4].network = net_can;
//     life_bit_com[4].timeoutInterval = 0;

//     life_bit_com[5].ind = 5;
//     life_bit_com[5].can_id_remote = CANID_WIFI_BT;
//     life_bit_com[5].ackReceived = false;
//     life_bit_com[5].network = net_can;
//     life_bit_com[5].timeoutInterval = 0;

//     life_bit_com[6].ind = 6;
//     life_bit_com[6].can_id_remote = CANID_WIFI;
//     life_bit_com[6].ackReceived = false;
//     life_bit_com[6].network = net_can;
//     life_bit_com[6].timeoutInterval = 0;

//     life_bit_com[7].ind = 7;
//     life_bit_com[7].can_id_remote = CANID_BT;
//     life_bit_com[7].ackReceived = false;
//     life_bit_com[7].network = net_can;
//     life_bit_com[7].timeoutInterval = 0;

//     life_bit_com[8].ind = 8;
//     life_bit_com[8].can_id_remote = SERID_ESP;
//     life_bit_com[8].ackReceived = false;
//     life_bit_com[8].network = net_ser;
//     life_bit_com[8].timeoutInterval = 0;


// }


 