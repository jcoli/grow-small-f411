/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#ifndef __VARIABLES_H__
#define __VARIABLES_H__
#include <Arduino.h>
#include "structures.h"

unsigned long loopDelay = millis();
unsigned long loopDelay_first = millis();
unsigned long loopDelay_analog = millis();
unsigned long loopDelay_input = millis();
unsigned long lastAvailabilityToggleAt = millis();
unsigned long loopDelay_watchdog = millis();
unsigned long loopDelay_pump = millis();

String retMsg2[2] = {"", ""};
String retMsg3[3] = {"", "", ""};
String retMsg4[4] = {"", "", "", ""};
String retMsg5[5] = {"", "", "", "", ""};
String retMsg6[6] = {"", "", "", "", "", ""};
String retMsg7[7] = {"", "", "", "", "", "", ""};
String retMsg8[8] = {"", "", "", "", "", "", "", ""};
String retMsg9[9] = {"", "", "", "", "", "", "", "", ""};
String retMsg10[10] = {"", "", "", "", "", "", "", "", "", ""};


String name_device = "Grow Master";
String manufacturer = "GreenTomate";

var_grow var_grow_1[40];
var_grow var_grow_2[40];
var_grow var_grow_3[40];
var_grow var_grow_4[40];
var_grow var_grow_5[40];
var_grow var_grow_6[40];
var_grow var_grow_7[40];
var_grow var_grow_8[40];

//TimeStamp
uint32_t subSec;
byte seconds;
byte minutes;
byte hours;
byte weekDay ;
byte day;
byte month;
byte year;

byte lastMinutes;
byte lastHours;
byte lastWeekDay ;
byte lastDay;
byte lastMonth;
byte lastYear;

String owner_name;
String owner_pass; 
String user_name = "";
String user_pwd = "";

//System
bool is_watchdog = false;
bool led_out = false;
bool first_run = true;
bool flash_ok = false;
bool scheduleRun = false; 

bool bt_enabled = false;
bool bt_connected = false;
bool bt_alive = false;
bool bt_rec = false;

String line = "";
String line1 = "";
String line2 = "";

bool stringComplete = false;
bool string1Complete = false;
bool string2Complete = false;

float VRef = 0.00;
float intTemp = 0.00;

int display_to_show = 0;

float temp_int = 0.00;
float temp_ext = 0.00;
float hum_int = 0.00;
float hum_ext = 0.00;
float soil_1_hum = 0.00;
float light_1_int = 0.00;

bool water_irrig_1_level = false;
bool water_hum_1_level = false;

bool light_on = false;
bool pump_irr_on = false;

bool relay_1_on = false;
bool relay_2_on = false;
bool relay_3_on = false;
bool relay_4_on = false;

bool fan1_inf_on = false;
bool fan2_inf_on = false;

bool hum_1_on = false;

int fan1_inf_pwm = 0;
int fan2_inf_pwm = 0;
int light_pwm = 0;

bool zeroChangeDetect = false;
bool lastZeroState = false;
bool run_on = false;


bool pwm_bool = false;
int pwm1 = 0;

//Service 01
int temp_int_min_stp = 0;
int temp_int_max_stp = 0;

int hum_int_on_stp = 0;

int hum_int_min_stp = 0;
int hum_int_max_stp = 0;

int vpd_int_min_stp = 0;
int vpd_int_max_stp = 0;

int soil_hum_min_stp = 0;
int soil_hum_max_stp = 0;
int ph_irrig_stp = 0;
int ph_hum_stp = 0;

int light_hr_on_stp = 0;
int light_min_on_stp = 0;
int light_hr_off_stp = 0;
int light_min_off_stp = 0;

int pump_irr_on_stp = 0;
int pump_hr_irr_on_stp = 0;
int pump_min_irr_on_stp = 0;
int pump_hr_irr_off_stp = 0;
int pump_min_irr_off_stp = 0;

int irr_interval_stp = 0;
int irr_time_stp = 0;
int irr_interval_on_stp = 0;

int irr_1_hr_stp = 0;
int irr_1_min_stp = 0;
int irr_2_hr_stp = 0;
int irr_2_min_stp = 0;
int irr_3_hr_stp = 0;
int irr_3_min_stp = 0;
int irr_4_hr_stp = 0;
int irr_4_min_stp = 0;
int irr_5_hr_stp = 0;
int irr_5_min_stp = 0;
int irr_6_hr_stp = 0;
int irr_6_min_stp = 0;

int light_pwm_stp = 0;
int fan1_inf_pwm_stp = 0;
int fan2_inf_pwm_stp = 0;

int fan1_inf_pwm_light_stp = 0;
int fan2_inf_pwm_light_stp = 0;

#endif