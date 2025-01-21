/**
Version: 0a
Tecnocoli - 08/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F103C8 - Grow Sensors
**/
#include <Arduino.h>

#ifndef __SERVICE_05_SER_H__
#define __SERVICE_05_SER_H__

void on_service_05_ser(String line_in);
void com_ser05_0x00(float com_pwm);
void com_ser05_0x01(float com_pwm);
void com_ser05_0x01(float com_pwm);
void com_ser05_0x02(float com_pwm);
void com_ser05_0x03(float com_pwm);
void com_ser05_0x06(float com_pwm);
void com_ser05_0x0B(float com_pwm);

#endif