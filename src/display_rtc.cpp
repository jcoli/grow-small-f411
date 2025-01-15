/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "io_defines.h"
#include "icons.h"

void show_display_rtc();

extern byte seconds;
extern byte minutes;
extern byte hours;
extern byte weekDay ;
extern byte day;
extern byte month;
extern byte year;

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

extern Adafruit_SSD1306 display;

void show_display_rtc(){

    
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(15, 10);
    display.setTextSize(2);
    display.printf("%02d/%02d/%02d ", day, month, year);
    display.setCursor(30, 40);
    display.printf("%02d:%02d\n", hours, minutes);
    display.display(); 
}
