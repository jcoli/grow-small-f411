/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#ifndef __IO_DEFINES_H__
#define __IO_DEFINES_H__

//Serial BlueTooth
#define TX_BT        PA9
#define RX_BT        PA10

#define BT_POWER    PB12

//I2C display
#define SDA1        PB7 
#define SCL1        PB6

//Sensor
// #define DHTPIN PC14
#define SOIL_HUM_1  PA0     //ana
#define LV_W_IRR    PB10    //dig
#define LV_W_HUM    PB2     //dig
#define INT_DHT    PB8      //DHT1
#define EXT_DHT    PB9      //DHT2

// EPROM WINBOND W25Q16BV
#define EP_CS   PA4     //19
#define EP_DO   PA6     //74
#define EP_DI   PA7     //6
#define EP_CLK  PA5     //7

#define LED_PIN    PC13

#define FAN01   PB13    //PWM
#define FAN02   PB14    //PWM
#define LIGHTS  PB15    //PWM
#define PUMP1   PA15    //dig
#define HUM     PB3     //dig

//Relay output
#define RELAY1          PB0 //Relay
#define RELAY2          PB1 //Relay

//buttons
#define BD_0    PA1 //display
#define BD_1    PA2 //fan
#define BD_2    PA3 //light
#define BD_3    PA8 //hum
#define BD_4    PB4 //irrigation


#endif