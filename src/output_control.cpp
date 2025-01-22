/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#include <Arduino.h>
#include <HardwareTimer.h>

#include "defines.h"
#include "io_defines.h"


void output_begin();
void TimerHandler();
void zeroDetect(); 
void write_output();


extern bool light_on;
extern bool pump_irr_on;

extern bool fan1_inf_on;
extern bool fan2_inf_on;

extern bool relay_1_on;
extern bool relay_2_on;

extern int fan1_inf_pwm;
extern int fan2_inf_pwm;
extern int light_pwm;

extern bool water_irrig_1_level;
extern bool water_hum_1_level;

extern bool zeroChangeDetect;
extern bool lastZeroState;
extern bool run_on;

extern bool pwm_bool;
extern int pwm1;

HardwareTimer *tim1 = new HardwareTimer(TIM1);

#define TIMER_INTERVAL_0_3S           300L
#define TIMER_INTERVAL_1S             1000L
#define TIMER_INTERVAL_1_5S           1500L
#define TIMER_INTERRUPT_DEBUG         0
#define TIMERINTERRUPT_LOGLEVEL_     0
#define TIMER_INTERVAL_MS         100
#define HW_TIMER_INTERVAL_MS      50


void output_begin(){
    Serial.println("Output Begin ");
    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);
    pinMode(FAN01, OUTPUT);
    pinMode(FAN02, OUTPUT);
    pinMode(LIGHTS, OUTPUT);
    pinMode(PUMP1, OUTPUT);
    pinMode(HUM, OUTPUT);
    pinMode(BT_POWER, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(BT_POWER, LOW);


    
    tim1->setPWM(1, FAN01, 10000, 0);
    tim1->setPWM(2, FAN02, 10000, 0);
    tim1->setPWM(3, LIGHTS, 10000, 0);
}

// 
