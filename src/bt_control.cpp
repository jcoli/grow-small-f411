/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#include <Arduino.h>
#include <STM32RTC.h>

#include "defines.h"
#include "io_defines.h"
#include "display.h"
#include "tools.h"
#include "structures.h"
#include "service_00_ser.h"
#include "service_01_ser.h"
#include "service_02_ser.h"
#include "service_03_ser.h"
#include "service_04_ser.h"
#include "service_05_ser.h"
#include "service_06_ser.h"
#include "service_07_ser.h"

void bt_begin();
void on_receive_bt(String line1);
void setup_rtc(String msg);
void BTconnectionCheck();
void sendMsgBT();
void service_0x0A_ser(String line_in);

extern STM32RTC& rtc;

extern uint32_t subSec;
extern byte seconds;
extern byte minutes;
extern byte hours; 
extern byte weekDay;
extern byte day;
extern byte month;
extern byte year;

extern String retMsg2[2];
extern String retMsg3[3];
extern String retMsg4[4];
extern String retMsg5[5];
extern String retMsg10[10];

extern float celsius;
extern int pwm1;
extern int pwm2;
extern int spValue;
extern int program_cycle;

extern float temp_int;
extern float temp_ext;
extern float hum_int;
extern float hum_ext;
extern float soil_1_hum;
extern float light_1_int;

extern bool water_irrig_1_level;
extern bool water_hum_1_level;

extern bool light_on;
extern bool pump_irr_on;

extern bool relay_1_on;
extern bool relay_2_on;

extern bool fan1_inf_on;
extern bool fan2_inf_on;

extern int fan1_inf_pwm;
extern int fan2_inf_pwm;
extern int light_pwm;

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


extern float temp_ext;
extern float hum_ext;
extern float temp_ext;
extern float temp_int;
extern float hum_int;
extern float soil_1_hum;
extern float light_1_int;

extern bool water_irrig_1_level;
extern bool water_hum_1_level;

extern bool fan_dehum_on;
extern bool fan1_inf_on;
extern bool fan2_inf_on;

extern bool fan_hum_on;
extern bool light_on;
extern bool pump_irr_on;
extern bool hum_1_on;

extern bool relay_1_on;
extern bool relay_2_on;

extern bool soil_hum_dig;

extern bool bt_connected;

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

extern String line;
extern String line1;
extern String line2;

extern bool stringComplete;
extern bool string1Complete;
extern bool string2Complete;

void bt_begin(){
    Serial.println("BT Serial Begin ");
    char COMM_CHK[] = "AT"; 
    BT_SERIAL.write(COMM_CHK);
    delay(1000);
    if (BT_SERIAL.available()) {
      String command = BT_SERIAL.readStringUntil('\n');
        Serial.println(command); 
     }
    //  BT_SERIAL.write("AT+NAMEGrow");
    // delay(1000);
    //  if (BT_SERIAL.available()) {
    //   String command = BT_SERIAL.readStringUntil('\n');
    //     Serial.println(command); 
    //  }

    // BT_SERIAL.write("AT+BAUD7");
    // delay(1000);
    // if (BT_SERIAL.available()) {
    // while (BT_SERIAL.available())Serial.println(BT_SERIAL.read());
    //  }
    //  BT_SERIAL.write("AT+PIN0000");
    // delay(1000);
    // if (BT_SERIAL.available()) {
    // while (BT_SERIAL.available())Serial.println(BT_SERIAL.read());
    //  }
    //  BT_SERIAL.write("AT+VERSION");
    // delay(1000);
    // if (BT_SERIAL.available()) {
    // while (BT_SERIAL.available())Serial.println(BT_SERIAL.read());
    //  }
    // BT_SERIAL.write("AT+");
    // Serial.println("BT Serial Begin 1");

}


void on_receive_bt(String line_in){
    Serial.print("BT Serial: ");
    Serial.println(line1);
    int i;
    if (line_in.substring(0,1)!="9"){
      split_msg_5(line_in);
      i = toHexc(retMsg5[1]);
      // Serial.println("on_ser_comm: "+i);
    }else{
      split_msg_10(line_in);
      i = 9;
      // Serial.print("on_ser_comm: == 7");
    }
    
    // Serial.println(i);
     switch (i) {
        case 0:
          Serial.println("esp- case 0");
        //   service_0x00_ser(line_in);
          break;
        case 1:
          Serial.println("esp - case 1");
        //   service_0x01_ser(line_in);
          break;
        case 2:
          Serial.println("esp - case 2");
        //   service_0x02_ser(line_in);
          break;
        case 3:
          Serial.println("esp - case 3");
        //   service_0x03_ser(line_in);
          break;
        case 4:
          Serial.println("esp - case 4");
          service_04_ser(line_in);
          break;
        case 5:
          Serial.println("esp - case 5");
          service_05_ser(line_in);
          break;  
        case 6:
          Serial.println("esp - case 6");
        //   service_0x06_ser(line_in);
          break;    
        case 7:
          Serial.println("esp - case 7");
        //   service_0x07_ser(line_in);
          break;    
        case 9:
          Serial.println("esp - case 9");
        //   setup_rtc(line1);
          break; 
         case 10:
          Serial.println("esp - case 10");
          service_0x0A_ser(line_in);
          break;          
    }    
}

void setup_rtc(String msg){
  split_msg_10(msg);
  // Serial.println("setup rtc");
  // Serial.println(retMsg10[3]);
  // Serial.println(retMsg10[4]);
  // Serial.println(retMsg10[5]);
  // Serial.println(retMsg10[6]);
  // Serial.println(retMsg10[7]);
  // Serial.println(retMsg10[8]);


  rtc.setHours(retMsg10[6].toInt());
  rtc.setMinutes(retMsg10[7].toInt());
  rtc.setSeconds(retMsg10[8].toInt());
  rtc.setWeekDay(retMsg10[2].toInt());
  rtc.setDay(retMsg10[3].toInt());
  rtc.setMonth(retMsg10[4].toInt());
  rtc.setYear(retMsg10[5].toInt()-2000); 

  rtc.getDate(&weekDay, &day, &month, &year);
  rtc.getTime(&hours, &minutes, &seconds, &subSec);
  // Serial.printf("%02d/%02d/%02d ", day, month, year);
  // Serial.printf("%02d:%02d\n", hours, minutes);

}

void BTconnectionCheck(){
    
  // if (BT_SERIAL.){
  //   // Serial.println("BlueTooth Connect");
  //   bt_connected = true;
  // } else{
  //   bt_connected = false;
  // } 
  
}

void service_0x0A_ser(String line_in){
    Serial.print("Receive Service 0A SER: ");
    Serial.println(line_in);
    split_msg_5(line_in);
    int i = toHexc(retMsg5[2]);
    if (i == 0){
        Serial.print("User: ");
        Serial.println(retMsg5[3]);
        if (!(var_grow_7[11].var_string->equals("0"))){
          if (var_grow_7[10].var_string->equals(retMsg5[3])){
              Serial.println("User OK ");
          }else{
              Serial.println("User NOT OK ");
              char COMM_CHK[] = "AT+DISC"; 
              BT_SERIAL.write(COMM_CHK);
              // BT_SERIAL
              
          }
        }
    }else if(i == 1){
        Serial.print("Password: ");
        Serial.println(retMsg5[3]);
        if (!(var_grow_7[11].var_string->equals("0"))){
          if (var_grow_7[11].var_string->equals(retMsg5[3])){
            Serial.println("Password OK ");
          }else{
            Serial.println("PWD NOT OK ");
            char COMM_CHK[] = "AT+DISC"; 
            BT_SERIAL.write(COMM_CHK); 
            //  bt_begin();       
          }
        }
        
    }
    // on_service_0A_ser(line_in);

}

void sendMsgBT(){
  if (bt_connected){
          // Serial.println("Bluetooth Connected");
          BT_SERIAL.print("3,0x02,0x00,"+ String(temp_ext)+",#\n"); 
          delay(100);
          BT_SERIAL.print("3,0x02,0x02,"+String(hum_ext)+",#\n"); 
          delay(100);
          BT_SERIAL.print("3,0x02,0x01,"+ String (temp_int)+",#\n"); 
          delay(100);
          BT_SERIAL.print("3,0x02,0x03,"+String(hum_int)+",#\n"); 
          delay(100);
          BT_SERIAL.print("3,0x02,0x12,"+String(soil_1_hum)+",#\n");
          delay(100);
          BT_SERIAL.print("3,0x02,0x11,"+String(light_1_int)+",#\n");
          delay(100);
          BT_SERIAL.print("3,0x03,0x06,"+String(water_irrig_1_level)+",#\n");
          delay(100);
          BT_SERIAL.print("3,0x03,0x07,"+String(water_hum_1_level)+",#\n");
          delay(100);
          if (fan1_inf_on){
            BT_SERIAL.print("3,0x04,0x01,1,#\n");
          }else{
            BT_SERIAL.print("3,0x04,0x01,0,#\n");
          }
          delay(100);
          if (fan2_inf_on){
            BT_SERIAL.print("3,0x04,0x02,1,#\n");
          }else{
            BT_SERIAL.print("3,0x04,0x02,0,#\n");
          }
          delay(100);
          if (light_on){
            BT_SERIAL.print("3,0x04,0x06,1,#\n");
          }else{
            BT_SERIAL.print("3,0x04,0x06,0,#\n");
          }
          delay(100);
          if (pump_irr_on){
            BT_SERIAL.print("3,0x04,0x0B,1,#\n");
          }else{
            BT_SERIAL.print("3,0x04,0x0B,0,#\n");
          }
          delay(100);
          if (relay_1_on){
            BT_SERIAL.print("3,0x04,0x0E,1,#\n");
          }else{
            BT_SERIAL.print("3,0x04,0x0E,0,#\n");
          }
          delay(100);
          if (relay_2_on){
            BT_SERIAL.print("3,0x04,0x0F,1,#\n");
          }else{
            BT_SERIAL.print("3,0x04,0x0F,0,#\n");
          }
          
          delay(100);
          BT_SERIAL.print("3,0x05,0x01,"+String(fan1_inf_pwm)+",#\n");
          delay(100);
          BT_SERIAL.print("3,0x05,0x02,"+String(fan2_inf_pwm)+",#\n");
          delay(100);
          BT_SERIAL.print("3,0x05,0x06,"+String(light_pwm)+",#\n");
          // Serial.print("Light PWM: ");
          // Serial.println(light_pwm);
          delay(100);
  }else{
        // Serial.println("bt not connected");
  }

}

