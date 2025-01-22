/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
// #include "STM32TimerInterrupt.h"
// #include "STM32_ISR_Timer.h"
// #include <HardwareTimer.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <IWatchdog.h>
#include <STM32RTC.h>


#include "display.h"
#include "display_rtc.h"
#include "defines.h"
#include "io_defines.h"
#include "output_control.h"
#include "input_control.h"
#include "variables.h"
#include "tools.h"
#include "bt_control.h"
#include "struc_mount.h"
#include "program.h"
#include "eprom.h"
#include "buttons.h"
#include "schedule.h"

HardwareSerial BT_SERIAL(RX_BT, TX_BT);

STM32RTC& rtc = STM32RTC::getInstance();


void serialEventRun(void)
{
  if (serialEvent && Serial.available())
  {
    serialEvent();
  }
  if (serialEvent1 && BT_SERIAL.available()) {
    serialEvent1();
  }
}


void setup() {
    Serial.begin(115200);
    BT_SERIAL.begin(57600);
    delay(7000);
    Serial.println("==================================");
    Serial.println("setup");

    rtc.setClockSource(STM32RTC::LSE_CLOCK);
    rtc.begin();
    Serial.println("setup a");
    if (flash_begin()){
          Serial.println("flash ok");
          flash_ok = true;
      }else{
          Serial.println("flash not ok");
          flash_ok = false;
      }
    // eraseFlash();
    delay(1000);
    display_begin();
    Serial.println("setup b");
    delay(500);
    struc_mount_begin();
    Serial.println("setup c");
    input_begin();
    Serial.println("setup d");
    delay(500);
    output_begin();
    Serial.println("setup e");
    delay(500);
    bt_begin();
    Serial.println("setup f");
    delay(500);
    IWatchdog.begin(10000000);
    loopDelay_watchdog = millis();
    // if(!rtc.isConfigured()){
      // rtc.setHours(16);
      // rtc.setMinutes(49);
      // rtc.setSeconds(0);
      // rtc.setWeekDay(3);
      // rtc.setDay(22);
      // rtc.setMonth(1);
      // rtc.setYear(25); 
    // }  

    rtc.getDate(&weekDay, &day, &month, &year);
    rtc.getTime(&hours, &minutes, &seconds, &subSec);
    lastMinutes = minutes;
    Serial.println("setup 1");
    delay(300);
    schedule_begin();

}

void loop() {
    if (millis() - loopDelay_watchdog  > TIMER_LED){ 
     loopDelay_watchdog  = millis();
     digitalWrite(LED_PIN, !digitalRead(LED_PIN)); 
     IWatchdog.reload();
    //  digitalWrite(BT_POWER,!(digitalRead(BT_POWER)));
    }

    if (millis() - loopDelay > TIMER_ANALOG){
        rtc.getDate(&weekDay, &day, &month, &year);
        rtc.getTime(&hours, &minutes, &seconds, &subSec);
        loopDelay = millis();
        input_read();
        // printValues();
        display_to_show++;
        if (display_to_show>3) display_to_show=1;  
        switch (display_to_show) {
            case 1:
                show_display_1();
                break;
            case 2:
                show_display_2();
                break;    
            case 3:
                show_display_rtc();
                break;      
        }
          
          Serial.print("BT - ");     
          Serial.println(display_to_show);     
          // BT_SERIAL.write("AT+STATE");
          // delay(1000);
          // if (BT_SERIAL.available()) {
          //   String command = BT_SERIAL.readStringUntil('\n');
          //   Serial.println(command); 
          // }
          sendMsgBT();
    }

    if ((millis() - loopDelay_first > TIMER_FIRST) && first_run){
          loopDelay_first = millis();
          program_begin();
          delay(500);
          schedule_check();
          first_run = false;
      }

    if ((millis() - loopDelay_pump > irr_time_stp) && (pump_irr_on)){ 
      pump_irr_on = false;
      digitalWrite(PUMP1, LOW );
     
      
      Serial.print("com_bool_0x0B off/on: ");
      Serial.println(irr_time_stp);
  }      

}

void serialEvent()
{
  while (Serial.available())
  {
    // delay(30);
    char inChar = (char)Serial.read();
    line += inChar;
    if (inChar == '#')
    {
      stringComplete = true;
      // Serial.print(line);
    }
  }
  if (stringComplete){
    // BT_SERIAL.println(line);
    // Serial2.println(line1);
    stringComplete = false;
    line = "";
  }  
}

void serialEvent1()
{
  // Serial.print("serial 1: ");
  while (BT_SERIAL.available() && !string1Complete)
  {
    // delay(50);
    char inChar = (char)BT_SERIAL.read();
    line1 += inChar;
    // Serial.println(line1);
    if ((inChar == '#'))
    {
      string1Complete = true;
    //   Serial.print("serial uC: ");
    //   Serial.println(line1);
      
    }
  }
  // on_receive(line1);
  if (string1Complete){
    bt_rec = true;
    Serial.print("serial BT: ");
    BT_SERIAL.println(line1);
    on_receive_bt(line1);
    // Serial.println(line1);
    bt_connected = true;
    string1Complete = false;
    line1 = "";
    bt_rec = false;
  }  
}

