/**
Version: 0a
Tecnocoli - 08/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F103C8 - Grow Sensors
**/
#include <Arduino.h>

#ifndef __SERVICE_07_SER_H__
#define __SERVICE_07_SER_H__

void on_service_07_ser(String line_in);
void save_on_flash_serv7();
void com_ser7_0x00(String command);
void com_ser7_0x01(String command);
void com_ser7_0x02(String command);
void com_ser7_0x03(String command);
void com_ser7_0x04(String command);
void com_ser7_0x05(String command);
void com_ser7_0x06(String command);
void com_ser7_0x07(String command);
void com_ser7_0x08(String command);
void com_ser7_0x09(String command);
void com_ser7_0x0A(String command);
void com_ser7_0x0B(String command);

void com_ser7_0xFF(String command);


#endif