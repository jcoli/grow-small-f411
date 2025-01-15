/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#include <Arduino.h>
#include "STM32TimerInterrupt.h"
#include "STM32_ISR_Timer.h"
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


STM32Timer ITimer(TIM9);
STM32_ISR_Timer ISR_Timer;
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
    pinMode(LED_PIN, OUTPUT);

    if (ITimer.attachInterruptInterval(HW_TIMER_INTERVAL_MS * 1000, TimerHandler))
    {
        Serial.println("Starting ITimer OK, millis() = 5 "); 
        // Serial.println(millis());
    }else{
        Serial.println(F("Can't set ITimer. Select another freq. or timer"));
    }
    attachInterrupt(digitalPinToInterrupt(INT_ZERO), zeroDetect, FALLING);
    detachInterrupt(digitalPinToInterrupt(INT_ZERO));
    tim1->setPWM(1, FAN01, 10000, 0);
    tim1->setPWM(2, FAN02, 10000, 0);
    tim1->setPWM(3, LIGHTS, 10000, 0);
}

void zeroDetect(){
    if (!digitalRead(INT_ZERO)){
       zeroChangeDetect = true; 
       write_output();
    }
}

void TimerHandler()
{
  ISR_Timer.run();
}

void write_output(){
     //This delay controls the power
    if ((pwm1>0) && (fan2_inf_on)){ 
        digitalWrite(FAN02,HIGH);
        delayMicroseconds( pwm1);
        digitalWrite(FAN02,LOW);
    //     digitalWrite(P2_LED,LOW);
    //     digitalWrite(P1_LED,HIGH);
    }
    zeroChangeDetect = false;

}



