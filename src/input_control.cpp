/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"
// #include <DHT_U.h>
#include <Wire.h>


#include "defines.h"
#include "io_defines.h"


void input_begin();
void input_read();
void printValues();

#define DHTTYPE DHT22
#define DHTTYPE1 DHT22


DHT dht_interno(INT_DHT, DHTTYPE);
DHT dht_externo(EXT_DHT, DHTTYPE1);

// DHT dht[2] = { dht_interno, dht_externo };

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

extern bool zeroChangeDetect;
extern bool lastZeroState;
extern bool run_on;

extern bool pwm_bool;
extern int pwm1;



float my_map(float val, float li, float ls, float lio, float lso);
void test_dht(int idx);

// const uint8_t INP_PINS[NUM_INP] = {LUMI_ANA_DIG, DOOR, SOIL_HUM_DIG};

void input_begin(){
    Serial.println("Input Begin "); 
    dht_interno.begin();
    dht_externo.begin();
    
    pinMode(LV_W_IRR, INPUT_PULLDOWN);
    // pinMode(LV_W_HUM, INPUT_PULLDOWN);
}

void input_read(){
//    Serial.println("Input Read "); 
    float soil_hum_temp = 0.00;
    soil_hum_temp=analogRead(SOIL_HUM_1);
    soil_1_hum = map(soil_hum_temp, 1000, 4095, 100, 0);
    hum_int = dht_interno.readHumidity();
    hum_ext = dht_externo.readHumidity();
    temp_int = dht_interno.readTemperature();
    temp_ext = dht_externo.readTemperature();
    water_irrig_1_level = digitalRead(LV_W_IRR);
    water_hum_1_level = digitalRead(LV_W_HUM);
}

void printValues() {
    Serial.println("===========================");
    Serial.print("soil humidity: ");
    Serial.println(soil_1_hum);
    Serial.print("Temp Int: ");
    Serial.println(temp_int);
    Serial.print("Hum Int: ");
    Serial.println(hum_int);
    Serial.print("Temp Ext: ");
    Serial.println(temp_ext);
    Serial.print("Hum Ext: ");
    Serial.println(hum_ext);
    Serial.println("===========================");
}

float my_map(float val, float li, float ls, float lio, float lso){
    float a =  (lso - lio) / (ls - li);
    float b = li-(a*lio);
    float ret_val = (val*a) - b;
    return ret_val;
}

void test_dht(int idx)
{
  // //  READ DATA
  // uint32_t start = micros();
  // int chk = dht[idx].read();
  // uint32_t stop = micros();

  // Serial.print(idx);
  // Serial.print(",\t");

  // switch (chk)
  // {
  //   case DHTLIB_OK:
  //     Serial.print("OK,\t");
  //     break;
  //   case DHTLIB_ERROR_CHECKSUM:
  //     Serial.print("Checksum error,\t");
  //     break;
  //   case DHTLIB_ERROR_TIMEOUT_A:
  //     Serial.print("Time out A error,\t");
  //     break;
  //   case DHTLIB_ERROR_TIMEOUT_B:
  //     Serial.print("Time out B error,\t");
  //     break;
  //   case DHTLIB_ERROR_TIMEOUT_C:
  //     Serial.print("Time out C error,\t");
  //     break;
  //   case DHTLIB_ERROR_TIMEOUT_D:
  //     Serial.print("Time out D error,\t");
  //     break;
  //   case DHTLIB_ERROR_SENSOR_NOT_READY:
  //     Serial.print("Sensor not ready,\t");
  //     break;
  //   case DHTLIB_ERROR_BIT_SHIFT:
  //     Serial.print("Bit shift error,\t");
  //     break;
  //   case DHTLIB_WAITING_FOR_READ:
  //     Serial.print("Waiting for read,\t");
  //     break;
  //   default:
  //     Serial.print("Unknown: ");
  //     Serial.print(chk);
  //     Serial.print(",\t");
  //     break;
  // }

  // //  DISPLAY DATA
  // Serial.print(dht[idx].getHumidity(), 1);
  // Serial.print(",\t");
  // Serial.print(dht[idx].getTemperature(), 1);
  // Serial.print(",\t");
  // uint32_t duration = stop - start;
  // Serial.print(duration);
  // Serial.print(",\t");
  // Serial.println(dht[idx].getType());
  // delay(500);
}

