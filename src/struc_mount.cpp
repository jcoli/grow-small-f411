/**
Version: 0a
Tecnocoli - 08/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F103C8 - Grow Sensors
**/

#include <Arduino.h>
#include <SPI.h>


#include "defines.h"
#include "io_defines.h"
#include "display.h"
#include "structures.h"
#include "program.h"

void struc_mount_begin();



extern byte minutes;
extern byte hours; 
extern byte weekDay;
extern byte day;
extern byte month;
extern byte year;

extern bool first_run;

extern int language;


//Service 01

extern int temp_int_min_stp;
extern int temp_int_max_stp;

extern int hum_int_on_stp;

extern int hum_int_min_stp;
extern int hum_int_max_stp;

extern int vpd_int_min_stp;
extern int vpd_int_max_stp;

extern int soil_hum_min_stp;
extern int soil_hum_max_stp;
extern int ph_irrig_stp;
extern int ph_hum_stp;

extern int light_hr_on_stp;
extern int light_min_on_stp;
extern int light_hr_off_stp;
extern int light_min_off_stp;

extern int pump_irr_on_stp;
extern int pump_hr_irr_on_stp;
extern int pump_min_irr_on_stp;
extern int pump_hr_irr_off_stp;
extern int pump_min_irr_off_stp;

extern int irr_interval_stp;
extern int irr_time_stp;
extern int irr_interval_on_stp;

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

extern int fan1_inf_pwm_light_stp;
extern int fan2_inf_pwm_light_stp;


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


extern int fan1_inf_pwm;
extern int fan2_inf_pwm;

extern int light_pwm;


extern float VRef;
extern float intTemp;

extern bool ch_page;
extern bool ch_page_ana;
extern int tft_page;
extern int tft_page_ant;
extern int tft_sub_page;
extern int tft_sub_page_ant;
extern int draw_tab;
extern int draw_page;

extern String owner_name;
extern String user_name;
extern String user_pwd;

extern var_grow var_grow_1[30];
extern var_grow var_grow_2[30];
extern var_grow var_grow_3[40];
extern var_grow var_grow_4[40];
extern var_grow var_grow_5[30];
extern var_grow var_grow_6[30];
extern var_grow var_grow_7[30];
extern var_grow var_grow_8[30];

void struc_mount_begin(){

    //===================================
    //===================================
    //===================================
    //      SERVICE 1
    //===================================
    //===================================

    //initial address service 7 8408
    //last address service 7 8400


    var_grow_1[0].pid = 0x00;
    var_grow_1[0].service = 0x01;
    var_grow_1[0].device = 0x0F;
    var_grow_1[0].descr = "Temperatura Maxima Interna";
    var_grow_1[0].eprom_address = 16384;
    var_grow_1[0].eprom_size = 16;
    var_grow_1[0].var_int = &temp_int_max_stp;

    var_grow_1[1].pid = 0x01;
    var_grow_1[1].service = 0x01;
    var_grow_1[1].device = 0x0F;
    var_grow_1[1].descr = "Temperatura Minima Interna";
    var_grow_1[1].eprom_address = 16400;
    var_grow_1[1].eprom_size = 16;
    var_grow_1[1].var_int = &temp_int_min_stp;

    var_grow_1[2].pid = 0x02;
    var_grow_1[2].service = 0x01;
    var_grow_1[2].device = 0x0F;
    var_grow_1[2].descr = "Umidade Maxima Interna";
    var_grow_1[2].eprom_address = 16;
    var_grow_1[2].eprom_size = 16416;
    var_grow_1[2].var_int = &hum_int_max_stp;

    var_grow_1[3].pid = 0x03;
    var_grow_1[3].service = 0x01;
    var_grow_1[3].device = 0x0F;
    var_grow_1[3].descr = "Umidade Minima Interna";
    var_grow_1[3].eprom_address = 16432;
    var_grow_1[3].eprom_size = 16;
    var_grow_1[3].var_int = &hum_int_min_stp;

    var_grow_1[4].pid = 0x04;
    var_grow_1[4].service = 0x01;
    var_grow_1[4].device = 0x0F; 
    var_grow_1[4].descr = "Umidade Maxima do Solo";
    var_grow_1[4].eprom_address = 16448;
    var_grow_1[4].eprom_size = 16;
    var_grow_1[4].var_int = &soil_hum_max_stp;

    var_grow_1[5].pid = 0x05;
    var_grow_1[5].service = 0x01;
    var_grow_1[5].device = 0x0F;
    var_grow_1[5].descr = "Umidade Minima do Solo";
    var_grow_1[5].eprom_address = 16464;
    var_grow_1[5].eprom_size = 16;
    var_grow_1[5].var_int = &soil_hum_min_stp;
    
    // var_grow_1[6].pid = 0x06;
    // var_grow_1[6].service = 0x01;
    // var_grow_1[6].device = 0x0F;
    // var_grow_1[6].descr = "PH Água de Rega";
    // var_grow_1[6].eprom_address = 16480;
    // var_grow_1[6].eprom_size = 16;
    // var_grow_1[6].var_int = &ph_irrig_stp;
    
    // var_grow_1[7].pid = 0x07;
    // var_grow_1[7].service = 0x01;
    // var_grow_1[7].device = 0x0F;
    // var_grow_1[7].descr = "PH Água do Umidificador";
    // var_grow_1[7].eprom_address = 16496;
    // var_grow_1[7].eprom_size = 16;
    // var_grow_1[7].var_int = &ph_hum_stp;

    var_grow_1[6].pid = 0x08;
    var_grow_1[6].service = 0x01;
    var_grow_1[6].device = 0x0F;
    var_grow_1[6].descr = "Iluminação ON (hora)";
    var_grow_1[6].eprom_address = 16512;
    var_grow_1[6].eprom_size = 16;
    var_grow_1[6].var_int = &light_hr_on_stp;
    
    var_grow_1[7].pid = 0x09;
    var_grow_1[7].service = 0x01;
    var_grow_1[7].device = 0x0F;
    var_grow_1[7].descr = "Iluminação ON (min)";
    var_grow_1[7].eprom_address = 16528;
    var_grow_1[7].eprom_size = 16;
    var_grow_1[7].var_int = &light_min_on_stp;
    
    var_grow_1[8].pid = 0x0A;
    var_grow_1[8].service = 0x01;
    var_grow_1[8].device = 0x0F;
    var_grow_1[8].descr = "Iluminação OFF (hora)";
    var_grow_1[8].eprom_address = 16544;
    var_grow_1[8].eprom_size = 16;
    var_grow_1[8].var_int = &light_hr_off_stp;
    
    var_grow_1[9].pid = 0x0B;
    var_grow_1[9].service = 0x01;
    var_grow_1[9].device = 0x0F;
    var_grow_1[9].descr = "Iluminação OFF (min)";
    var_grow_1[9].eprom_address = 16560;
    var_grow_1[9].eprom_size = 16;
    var_grow_1[9].var_int = &light_min_off_stp;

    var_grow_1[10].pid = 0x0C;
    var_grow_1[10].service = 0x01;
    var_grow_1[10].device = 0x0F;
    var_grow_1[10].descr = "Rega ON (hora)";
    var_grow_1[10].eprom_address = 16576;
    var_grow_1[10].eprom_size = 16;
    var_grow_1[10].var_int = &pump_hr_irr_on_stp;

    var_grow_1[11].pid = 0x0D;
    var_grow_1[11].service = 0x01;
    var_grow_1[11].device = 0x0F;
    var_grow_1[11].descr = "Rega ON (min)";
    var_grow_1[11].eprom_address = 16592;
    var_grow_1[11].eprom_size = 16;
    var_grow_1[11].var_int = &pump_min_irr_on_stp;
    
    var_grow_1[12].pid = 0x0E;
    var_grow_1[12].service = 0x01;
    var_grow_1[12].device = 0x0F;
    var_grow_1[12].descr = "Rega OFF (hora)";
    var_grow_1[12].eprom_address = 16608;
    var_grow_1[12].eprom_size = 16;
    var_grow_1[12].var_int = &pump_hr_irr_off_stp;

    var_grow_1[13].pid = 0x0F;
    var_grow_1[13].service = 0x01;
    var_grow_1[13].device = 0x0F;
    var_grow_1[13].descr = "Rega OFF (min)";
    var_grow_1[13].eprom_address = 16624;
    var_grow_1[13].eprom_size = 16;
    var_grow_1[13].var_int = &pump_min_irr_off_stp;
    
    var_grow_1[14].pid = 0x10;
    var_grow_1[14].service = 0x01;
    var_grow_1[14].device = 0x0F;
    var_grow_1[14].descr = "Rega Intervalo (h)";
    var_grow_1[14].eprom_address = 16640;
    var_grow_1[14].eprom_size = 16;
    var_grow_1[14].var_int = &irr_interval_stp;

    var_grow_1[15].pid = 0x11;
    var_grow_1[15].service = 0x01;
    var_grow_1[15].device = 0x0F;
    var_grow_1[15].descr = "Rega Tempo (s)";
    var_grow_1[15].eprom_address = 16656;
    var_grow_1[15].eprom_size = 16;
    var_grow_1[15].var_int = &irr_time_stp;
    
    var_grow_1[16].pid = 0x12;
    var_grow_1[16].service = 0x01;
    var_grow_1[16].device = 0x0F;
    var_grow_1[16].descr = "Rega 1 ON (hora)";
    var_grow_1[16].eprom_address = 16672;
    var_grow_1[16].eprom_size = 16;
    var_grow_1[16].var_int = &irr_1_hr_stp;

    var_grow_1[17].pid = 0x13;
    var_grow_1[17].service = 0x01;
    var_grow_1[17].device = 0x0F;
    var_grow_1[17].descr = "Rega 1 ON (min)";
    var_grow_1[17].eprom_address = 16688;
    var_grow_1[17].eprom_size = 16;
    var_grow_1[17].var_int = &irr_1_min_stp;
    
    var_grow_1[18].pid = 0x14;
    var_grow_1[18].service = 0x01;
    var_grow_1[18].device = 0x0F;
    var_grow_1[18].descr = "Rega 2 ON (hora)";
    var_grow_1[18].eprom_address = 16704;
    var_grow_1[18].eprom_size = 16;
    var_grow_1[18].var_int = &irr_2_hr_stp;

    var_grow_1[19].pid = 0x15;
    var_grow_1[19].service = 0x01;
    var_grow_1[19].device = 0x0F;
    var_grow_1[19].descr = "Rega 2 ON (min)";
    var_grow_1[19].eprom_address = 16720;
    var_grow_1[19].eprom_size = 16;
    var_grow_1[19].var_int = &irr_2_min_stp;

    var_grow_1[20].pid = 0x16;
    var_grow_1[20].service = 0x01;
    var_grow_1[20].device = 0x0F;
    var_grow_1[20].descr = "Iluminação Intensidade (PWM)";
    var_grow_1[20].eprom_address = 16736;
    var_grow_1[20].eprom_size = 16;
    var_grow_1[20].var_int = &light_pwm_stp;
    
    var_grow_1[21].pid = 0x17;
    var_grow_1[21].service = 0x01;
    var_grow_1[21].device = 0x0F;
    var_grow_1[21].descr = "Fan 1 Intensidade (PMW)";
    var_grow_1[21].eprom_address = 16752;
    var_grow_1[21].eprom_size = 16;
    var_grow_1[21].var_int = &fan1_inf_pwm_stp;
    
    var_grow_1[22].pid = 0x18;
    var_grow_1[22].service = 0x01;
    var_grow_1[22].device = 0x0F;
    var_grow_1[22].descr = "Fan 2 Intensidade (PMW)";
    var_grow_1[22].eprom_address = 16768;
    var_grow_1[22].eprom_size = 16;
    var_grow_1[22].var_int = &fan2_inf_pwm_stp;
    
    // var_grow_1[23].pid = 0x19;
    // var_grow_1[23].service = 0x01;
    // var_grow_1[23].device = 0x0F;
    // var_grow_1[23].descr = "Fan 3 Intensidade (PMW)";
    // var_grow_1[23].eprom_address = 16784;
    // var_grow_1[23].eprom_size = 16;
    // var_grow_1[23].var_int = &fan3_inf_pwm_stp;

    var_grow_1[24].pid = 0x1A;
    var_grow_1[24].service = 0x01;
    var_grow_1[24].device = 0x0F;
    var_grow_1[24].descr = "Fan 1 Intensidade Luz (PMW)";
    var_grow_1[24].eprom_address = 16800;
    var_grow_1[24].eprom_size = 16;
    var_grow_1[24].var_int = &fan1_inf_pwm_light_stp;
    
    var_grow_1[25].pid = 0x1B;
    var_grow_1[25].service = 0x01;
    var_grow_1[25].device = 0x0F;
    var_grow_1[25].descr = "Fan 2 Intensidade Luz (PMW)";
    var_grow_1[25].eprom_address = 16816;
    var_grow_1[25].eprom_size = 16;
    var_grow_1[25].var_int = &fan2_inf_pwm_light_stp;
    
    // var_grow_1[26].pid = 0x1C;
    // var_grow_1[26].service = 0x01;
    // var_grow_1[26].device = 0x0F;
    // var_grow_1[26].descr = "Fan 3 Intensidade Luz (PMW)";
    // var_grow_1[26].eprom_address = 16832;
    // var_grow_1[26].eprom_size = 16;
    // var_grow_1[26].var_int = &fan3_inf_pwm_light_stp;

    var_grow_1[27].pid = 0x1D;
    var_grow_1[27].service = 0x01;
    var_grow_1[27].device = 0x0F;
    var_grow_1[27].descr = "Rega Intervalo ON";
    var_grow_1[27].eprom_address = 16848;
    var_grow_1[27].eprom_size = 16;
    var_grow_1[27].var_int = &irr_interval_on_stp;

    var_grow_1[28].pid = 0x1E;
    var_grow_1[28].service = 0x01;
    var_grow_1[28].device = 0x0F;
    var_grow_1[28].descr = "Umidificador ON";
    var_grow_1[28].eprom_address = 16864;
    var_grow_1[28].eprom_size = 16;
    var_grow_1[28].var_int = &irr_interval_on_stp;

    // var_grow_1[29].pid = 0x1F;
    // var_grow_1[29].service = 0x01;
    // var_grow_1[29].device = 0x0F;
    // var_grow_1[29].descr = "Umidificador Intensidade";
    // var_grow_1[29].eprom_address = 16880;
    // var_grow_1[29].eprom_size = 16;
    // var_grow_1[29].var_int = &irr_interval_on_stp;


    // var_grow_1[22].pid = 0x16;
    // var_grow_1[22].service = 0x01;
    // var_grow_1[22].device = 0x0F;
    // var_grow_1[22].descr = "Rega 3 ON (hora)";
    // var_grow_1[22].eprom_address = 16672;
    // var_grow_1[22].eprom_size = 16;
    // var_grow_1[22].var_int = &irr_3_hr_stp;

    // var_grow_1[23].pid = 0x17;
    // var_grow_1[23].service = 0x01;
    // var_grow_1[23].device = 0x0F;
    // var_grow_1[23].descr = "Rega 3 ON (min)";
    // var_grow_1[23].eprom_address = 16688;
    // var_grow_1[23].eprom_size = 16;
    // var_grow_1[23].var_int = &irr_3_min_stp;
    
    // var_grow_1[24].pid = 0x18;
    // var_grow_1[24].service = 0x01;
    // var_grow_1[24].device = 0x0F;
    // var_grow_1[24].descr = "Rega 4 ON (hora)";
    // var_grow_1[24].eprom_address = 16704;
    // var_grow_1[24].eprom_size = 16;
    // var_grow_1[24].var_int = &irr_4_hr_stp;

    // var_grow_1[25].pid = 0x19;
    // var_grow_1[25].service = 0x01;
    // var_grow_1[25].device = 0x0F;
    // var_grow_1[25].descr = "Rega 4 ON (min)";
    // var_grow_1[25].eprom_address = 16720;
    // var_grow_1[25].eprom_size = 16;
    // var_grow_1[25].var_int = &irr_4_min_stp;
    
    // var_grow_1[26].pid = 0x1A;
    // var_grow_1[26].service = 0x01;
    // var_grow_1[26].device = 0x0F;
    // var_grow_1[26].descr = "Rega 5 ON (hora)";
    // var_grow_1[26].eprom_address = 16736;
    // var_grow_1[26].eprom_size = 16;
    // var_grow_1[26].var_int = &irr_5_hr_stp;

    // var_grow_1[27].pid = 0x1B;
    // var_grow_1[27].service = 0x01;
    // var_grow_1[27].device = 0x0F;
    // var_grow_1[27].descr = "Rega 5 ON (min)";
    // var_grow_1[27].eprom_address = 16752;
    // var_grow_1[27].eprom_size = 16;
    // var_grow_1[27].var_int = &irr_5_min_stp;
    
    // var_grow_1[28].pid = 0x1C;
    // var_grow_1[28].service = 0x01;
    // var_grow_1[28].device = 0x0F;
    // var_grow_1[28].descr = "Rega 6 ON (hora)";
    // var_grow_1[28].eprom_address = 16768;
    // var_grow_1[28].eprom_size = 16;
    // var_grow_1[28].var_int = &irr_6_hr_stp;
    
    // var_grow_1[29].pid = 0x1D;
    // var_grow_1[29].service = 0x01;
    // var_grow_1[29].device = 0x0F;
    // var_grow_1[29].descr = "Rega 6 ON (min)";
    // var_grow_1[29].eprom_address = 16784;
    // var_grow_1[29].eprom_size = 16;
    // var_grow_1[29].var_int = &irr_6_min_stp;
    
    //===================================
    //===================================
    //===================================
    //      SERVICE 2
    //===================================
    //===================================


    var_grow_2[0].pid = 0x00;
    var_grow_2[0].service = 0x02;
    var_grow_2[0].device = 0x0F;
    var_grow_2[0].descr = "Temperatura Interna";
    var_grow_2[0].oldValue = 0.00F;
    var_grow_2[0].unity = "C";
    var_grow_2[0].var_name = "temp_int";
    var_grow_2[0].var_float = &temp_int;

    var_grow_2[1].pid = 0x01;
    var_grow_2[1].service = 0x02;
    var_grow_2[1].device = 0x0F;
    var_grow_2[1].descr = "Temperatura Externa";
    var_grow_2[1].oldValue = 0.00F;
    var_grow_2[1].unity = "C";
    var_grow_2[1].var_name = "temp_ext";
    var_grow_2[1].var_float = &temp_ext;

    var_grow_2[2].pid = 0x02;
    var_grow_2[2].service = 0x02;
    var_grow_2[2].device = 0x0F;
    var_grow_2[2].descr = "Umidade Externa";
    var_grow_2[2].oldValue = 0.00F;
    var_grow_2[2].unity = "%";
    var_grow_2[2].var_name = "hum_ext";
    var_grow_2[2].var_float = &hum_ext;

    var_grow_2[3].pid = 0x03;
    var_grow_2[3].service = 0x02;
    var_grow_2[3].device = 0x0F;
    var_grow_2[3].descr = "Umidade Interna";
    var_grow_2[3].oldValue = 0.00F;
    var_grow_2[3].unity = "%";
    var_grow_2[3].var_name = "hum_int";
    var_grow_2[3].var_float = &hum_int;

    // var_grow_2[4].pid = 0x04;
    // var_grow_2[4].service = 0x02;
    // var_grow_2[4].device = 0x0F;
    // var_grow_2[4].descr = "C02 Externo";
    // var_grow_2[4].oldValue = 0.00F;
    // var_grow_2[4].unity = "ppm";
    // var_grow_2[4].var_name = "eco2_ext";
    // var_grow_2[4].var_float = &eco2_ext;

    // var_grow_2[5].pid = 0x05;
    // var_grow_2[5].service = 0x02;
    // var_grow_2[5].device = 0x0F;
    // var_grow_2[5].descr = "C02 Interno";
    // var_grow_2[5].oldValue = 0.00F;
    // var_grow_2[5].unity = "ppm";
    // var_grow_2[5].var_name = "eco2_int";
    // var_grow_2[5].var_float = &eco2_int;

    var_grow_2[6].pid = 0x11;
    var_grow_2[6].service = 0x02;
    var_grow_2[6].device = 0x0F;
    var_grow_2[6].descr = "Iluminação";
    var_grow_2[6].oldValue = 0.00F;
    var_grow_2[6].unity = "%";
    var_grow_2[6].var_name = "light_1_int";
    var_grow_2[6].var_float = &light_1_int;

    var_grow_2[7].pid = 0x12;
    var_grow_2[7].service = 0x02;
    var_grow_2[7].device = 0x0F;
    var_grow_2[7].descr = "Umidade do Solo 1";
    var_grow_2[7].oldValue = 0.00F;
    var_grow_2[7].unity = "%";
    var_grow_2[7].var_name = "soil_1_hum";
    var_grow_2[7].var_float = &soil_1_hum;

    // var_grow_2[8].pid = 0x13;
    // var_grow_2[8].service = 0x02;
    // var_grow_2[8].device = 0x0F;
    // var_grow_2[8].descr = "Umidade do Solo 2";
    // var_grow_2[8].oldValue = 0.00F;
    // var_grow_2[8].unity = "%";
    // var_grow_2[8].var_name = "soil_2_hum";
    // var_grow_2[8].var_float = &soil_2_hum;

    // var_grow_2[9].pid = 0x14;
    // var_grow_2[9].service = 0x02;
    // var_grow_2[9].device = 0x0F;
    // var_grow_2[9].descr = "Umidade do Solo 3";
    // var_grow_2[9].oldValue = 0.00F;
    // var_grow_2[9].unity = "%";
    // var_grow_2[9].var_name = "soil_3_hum";
    // var_grow_2[9].var_float = &soil_3_hum;

    // var_grow_2[10].pid = 0x15;
    // var_grow_2[10].service = 0x02;
    // var_grow_2[10].device = 0x0F;
    // var_grow_2[10].descr = "Umidade do Solo 2";
    // var_grow_2[10].oldValue = 0.00F;
    // var_grow_2[10].unity = "%";
    // var_grow_2[10].var_name = "soil_4_hum";
    // var_grow_2[10].var_float = &soil_4_hum;
    
    //===================================
    //===================================
    //===================================
    //      SERVICE 3
    //===================================
    //===================================

    var_grow_3[0].pid = 0x06;
    var_grow_3[0].service = 0x03;
    var_grow_3[0].device = 0x0F;
    var_grow_3[0].descr = "Nivel da Agua Rega";
    var_grow_3[0].oldValue = 0.00F;
    var_grow_3[0].unity = "B";
    var_grow_3[0].var_name = "water_irrig_1_level";
    var_grow_3[0].var_bool = &water_irrig_1_level;

    // var_grow_3[1].pid = 0x0D;
    // var_grow_3[1].service = 0x03;
    // var_grow_3[1].device = 0x0F;
    // var_grow_3[1].descr = "Door";
    // var_grow_3[1].oldValue = 0.00F;
    // var_grow_3[1].unity = "B";
    // var_grow_3[1].var_name = "door";
    // var_grow_3[1].var_bool = &door;

    // var_grow_3[2].pid = 0x21;
    // var_grow_3[2].service = 0x03;
    // var_grow_3[2].device = 0x0F;
    // var_grow_3[2].descr = "WIFI";
    // var_grow_3[2].oldValue = 0.00F;
    // var_grow_3[2].unity = "B";
    // var_grow_3[2].var_name = "wifi_connected";
    // var_grow_3[2].var_bool = &wifi_connected;


    var_grow_3[3].pid = 0x22;
    var_grow_3[3].service = 0x03;
    var_grow_3[3].device = 0x0F;
    var_grow_3[3].descr = "Bluetooth";
    var_grow_3[3].oldValue = 0.00F;
    var_grow_3[3].unity = "B";
    var_grow_3[3].var_name = "bt_connected";
    var_grow_3[3].var_bool = &bt_connected;

    // var_grow_3[4].pid = 0x23;
    // var_grow_3[4].service = 0x03;
    // var_grow_3[4].device = 0x0F;
    // var_grow_3[4].descr = "MQTT";
    // var_grow_3[4].oldValue = 0.00F;
    // var_grow_3[4].unity = "B";
    // var_grow_3[4].var_name = "mqtt_connected";
    // var_grow_3[4].var_bool = &mqtt_connected;
    
    //===================================
    //===================================
    //===================================
    //      SERVICE 4
    //===================================
    //===================================

    //initial address service 7 7936
    //last address service 7 8400


    // var_grow_4[0].pid = 0x00;
    // var_grow_4[0].service = 0x04;
    // var_grow_4[0].device = 0x0F;
    // var_grow_4[0].descr = "Ventilador desumidificador";
    // var_grow_4[0].oldValue = false;
    // var_grow_4[0].unity = "B";
    // var_grow_4[0].eprom_address = 12288;
    // var_grow_4[0].eprom_size = 8;
    // var_grow_4[0].var_name = "fan_dehum_on";
    // var_grow_4[0].var_bool = &fan_dehum_on;

    var_grow_4[1].pid = 0x01;
    var_grow_4[1].service = 0x04;
    var_grow_4[1].device = 0x0F;
    var_grow_4[1].descr = "Ventilador 1 Insuflamento";
    var_grow_4[1].oldValue = false;
    var_grow_4[1].unity = "B";
    var_grow_4[1].eprom_address = 12304;
    var_grow_4[1].eprom_size = 8;
    var_grow_4[1].var_name = "fan1_inf_on";
    var_grow_4[1].var_bool = &fan1_inf_on;

    var_grow_4[2].pid = 0x02;
    var_grow_4[2].service = 0x04;
    var_grow_4[2].device = 0x0F;
    var_grow_4[2].descr = "Ventilador 2 Insuflamento";
    var_grow_4[2].oldValue = false;
    var_grow_4[2].unity = "B";
    var_grow_4[2].eprom_address = 12320;
    var_grow_4[2].eprom_size = 8;
    var_grow_4[2].var_name = "fan2_inf_on";
    var_grow_4[2].var_bool = &fan2_inf_on;

    // var_grow_4[3].pid = 0x03;
    // var_grow_4[3].service = 0x04;
    // var_grow_4[3].device = 0x0F;
    // var_grow_4[3].descr = "Ventilador 3 Insuflamento";
    // var_grow_4[3].oldValue = false;
    // var_grow_4[3].unity = "B";
    // var_grow_4[3].eprom_address = 12336;
    // var_grow_4[3].eprom_size = 8;
    // var_grow_4[3].var_name = "fan3_inf_on";
    // var_grow_4[3].var_bool = &fan3_inf_on;

    var_grow_4[4].pid = 0x06;
    var_grow_4[4].service = 0x04;
    var_grow_4[4].device = 0x0F;
    var_grow_4[4].descr = "Iluminação";
    var_grow_4[4].oldValue = false;
    var_grow_4[4].unity = "B";
    var_grow_4[4].eprom_address = 12384;
    var_grow_4[4].eprom_size = 8;
    var_grow_4[4].var_name = "light_on";
    var_grow_4[4].var_bool = &light_on;

    var_grow_4[5].pid = 0x0B;
    var_grow_4[5].service = 0x04;
    var_grow_4[5].device = 0x0F;
    var_grow_4[5].descr = "Bomba Rega";
    var_grow_4[5].oldValue = false;
    var_grow_4[5].unity = "B";
    var_grow_4[5].eprom_address = 12480;
    var_grow_4[5].eprom_size = 8;
    var_grow_4[5].var_name = "pump_irr_on";
    var_grow_4[5].var_bool = &pump_irr_on;

    var_grow_4[6].pid = 0x0C;
    var_grow_4[6].service = 0x04;
    var_grow_4[6].device = 0x0F;
    var_grow_4[6].descr = "Umidificador";
    var_grow_4[6].oldValue = false;
    var_grow_4[6].unity = "B";
    var_grow_4[6].eprom_address = 12496;
    var_grow_4[6].eprom_size = 8;
    var_grow_4[6].var_name = "hum_1_on";
    var_grow_4[6].var_bool = &hum_1_on;
    
    // var_grow_4[7].pid = 0x0D;
    // var_grow_4[7].service = 0x04;
    // var_grow_4[7].device = 0x0F;
    // var_grow_4[7].descr = "Desumidificador";
    // var_grow_4[7].oldValue = false;
    // var_grow_4[7].unity = "B";
    // var_grow_4[7].eprom_address = 12496;
    // var_grow_4[7].eprom_size = 8;
    // var_grow_4[7].var_name = "dehum_1_on";
    // var_grow_4[7].var_bool = &dehum_1_on;
    

    var_grow_4[8].pid = 0x0E;
    var_grow_4[8].service = 0x04;
    var_grow_4[8].device = 0x0F;
    var_grow_4[8].descr = "Relay 1";
    var_grow_4[8].oldValue = false;
    var_grow_4[8].unity = "B";
    var_grow_4[8].eprom_address = 12512;
    var_grow_4[8].eprom_size = 8;
    var_grow_4[8].var_name = "relay_1_on";
    var_grow_4[8].var_bool = &relay_1_on;

    var_grow_4[9].pid = 0x0F;
    var_grow_4[9].service = 0x04;
    var_grow_4[9].device = 0x0F;
    var_grow_4[9].descr = "Relay 2";
    var_grow_4[9].oldValue = false;
    var_grow_4[9].unity = "B";
    var_grow_4[9].eprom_address = 12528;
    var_grow_4[9].eprom_size = 8;
    var_grow_4[9].var_name = "relay_2_on";
    var_grow_4[9].var_bool = &relay_2_on;

    // var_grow_4[10].pid = 0x10;
    // var_grow_4[10].service = 0x04;
    // var_grow_4[10].device = 0x0F;
    // var_grow_4[10].descr = "Relay 3";
    // var_grow_4[10].oldValue = false;
    // var_grow_4[10].unity = "B";
    // var_grow_4[10].eprom_address = 12544;
    // var_grow_4[10].eprom_size = 8;
    // var_grow_4[10].var_name = "relay_3_on";
    // var_grow_4[10].var_bool = &relay_3_on;

    // var_grow_4[11].pid = 0x11;
    // var_grow_4[11].service = 0x04;
    // var_grow_4[11].device = 0x0F;
    // var_grow_4[11].descr = "Relay 4";
    // var_grow_4[11].oldValue = false;
    // var_grow_4[11].unity = "B";
    // var_grow_4[11].eprom_address = 12560;
    // var_grow_4[11].eprom_size = 8;
    // var_grow_4[11].var_name = "relay_4_on";
    // var_grow_4[11].var_bool = &relay_4_on;

    // var_grow_4[12].pid = 0x12;
    // var_grow_4[12].service = 0x04;
    // var_grow_4[12].device = 0x0F;
    // var_grow_4[12].descr = "Saida 1";
    // var_grow_4[12].oldValue = false;
    // var_grow_4[12].unity = "B";
    // var_grow_4[12].eprom_address = 12576;
    // var_grow_4[12].eprom_size = 8;
    // var_grow_4[12].var_name = "output_1_on";
    // var_grow_4[12].var_bool = &output_1_on;

    // var_grow_4[13].pid = 0x13;
    // var_grow_4[13].service = 0x04;
    // var_grow_4[13].device = 0x0F;
    // var_grow_4[13].descr = "Saida 2";
    // var_grow_4[13].oldValue = false;
    // var_grow_4[13].unity = "B";
    // var_grow_4[13].eprom_address = 12592;
    // var_grow_4[13].eprom_size = 8; 
    // var_grow_4[13].var_name = "output_2_on";
    // var_grow_4[13].var_bool = &output_2_on;

    //===================================
    //===================================
    //===================================
    //      SERVICE 5
    //===================================
    //===================================


    // var_grow_5[0].pid = 0x00;
    // var_grow_5[0].service = 0x05;
    // var_grow_5[0].device = 0x0F;
    // var_grow_5[0].descr = "Ventilador Desumidificador";
    // var_grow_5[0].oldValue = 0.00F;
    // var_grow_5[0].unity = "%";
    // var_grow_5[0].eprom_address = 20480;
    // var_grow_5[0].eprom_size = 16;
    // var_grow_5[0].var_name = "fan_dehum_pwm";
    // var_grow_5[0].var_int = &fan_dehum_pwm;

    var_grow_5[1].pid = 0x01;
    var_grow_5[1].service = 0x05;                                   
    var_grow_5[1].device = 0x0F; 
    var_grow_5[1].descr = "Ventilador 1 Insuflamento";
    var_grow_5[1].oldValue = 0.00F;
    var_grow_5[1].unity = "%";
    var_grow_5[1].eprom_address = 20496;
    var_grow_5[1].eprom_size = 16;
    var_grow_5[1].var_name = "fan1_inf_pwm";
    var_grow_5[1].var_int = &fan1_inf_pwm;

    var_grow_5[2].pid = 0x02;
    var_grow_5[2].service = 0x05;
    var_grow_5[2].device = 0x0F;
    var_grow_5[2].descr = "Ventilador 2 Insuflamento";
    var_grow_5[2].oldValue = 0.00F;
    var_grow_5[2].unity = "%";
    var_grow_5[2].eprom_address = 20512;
    var_grow_5[2].eprom_size = 16;
    var_grow_5[2].var_name = "fan2_inf_pwm";
    var_grow_5[2].var_int = &fan2_inf_pwm;

    // var_grow_5[3].pid = 0x03;
    // var_grow_5[3].service = 0x05;
    // var_grow_5[3].device = 0x0F;
    // var_grow_5[3].descr = "Ventilador 1 Exaustao";
    // var_grow_5[3].oldValue = 0.00F;
    // var_grow_5[3].unity = "%";
    // var_grow_5[3].eprom_address = 20528;
    // var_grow_5[3].eprom_size = 16;
    // var_grow_5[3].var_name = "fan3_inf_pwm";
    // var_grow_5[3].var_int = &fan3_inf_pwm;

    var_grow_5[4].pid = 0x06;
    var_grow_5[4].service = 0x05;
    var_grow_5[4].device = 0x0F;
    var_grow_5[4].descr = "Iluminação";
    var_grow_5[4].oldValue = 0.00F;
    var_grow_5[4].unity = "%";
    var_grow_5[4].eprom_address = 20544;
    var_grow_5[4].eprom_size = 16;
    var_grow_5[4].var_name = "light_pwm";
    var_grow_5[4].var_int = &light_pwm;

    // var_grow_5[5].pid = 0x0C;
    // var_grow_5[5].service = 0x05;
    // var_grow_5[5].device = 0x0F;
    // var_grow_5[5].descr = "Umidificador";
    // var_grow_5[5].oldValue = 0.00F;
    // var_grow_5[5].unity = "%";
    // var_grow_5[5].eprom_address = 20560;
    // var_grow_5[5].eprom_size = 16;
    // var_grow_5[5].var_name = "hum_1_pwm";
    // var_grow_5[5].var_int = &hum_1_pwm;


    //===================================
    //===================================
    //===================================
    //      SERVICE 6
    //===================================
    //===================================

    // var_grow_6[0].pid = 0x00;
    // var_grow_6[0].service = 0x06;
    // var_grow_6[0].device = 0x0F;
    // var_grow_6[0].descr = "Wifi begin (ssid, pwd)";



    // var_grow_6[1].pid = 0x01;
    // var_grow_6[1].service = 0x06;
    // var_grow_6[1].device = 0x0F;
    // var_grow_6[1].descr = "List Networks";

    // var_grow_6[2].pid = 0x02;
    // var_grow_6[2].service = 0x06;
    // var_grow_6[2].device = 0x0F;
    // var_grow_6[2].descr = "Chosen Network";

    var_grow_6[3].pid = 0x03;
    var_grow_6[3].service = 0x06;
    var_grow_6[3].device = 0x0F;
    var_grow_6[3].descr = "update Variables";

    // var_grow_6[4].pid = 0x04;
    // var_grow_6[4].service = 0x06;
    // var_grow_6[4].device = 0x0F;
    // var_grow_6[4].descr = "send commands wifi/bt → master";

    // var_grow_6[5].pid = 0x05;
    // var_grow_6[5].service = 0x06;
    // var_grow_6[5].device = 0x0F;
    // var_grow_6[5].descr = "life_bit";

    var_grow_6[6].pid = 0x06;
    var_grow_6[6].service = 0x06;
    var_grow_6[6].device = 0x0F;
    var_grow_6[6].descr = "Reset";

    var_grow_6[7].pid = 0x07;
    var_grow_6[7].service = 0x06;
    var_grow_6[7].device = 0x0F;
    var_grow_6[7].descr = "send time (ntp) wifi→master";

    //===================================
    //===================================
    //===================================
    //      SERVICE 7
    //===================================
    //===================================

    //initial address service 7 1024
    //last address service 7 7680


    // var_grow_7[0].pid = 0x00;
    // var_grow_7[0].service = 0x07;
    // var_grow_7[0].descr = "WIFI SSID";
    // var_grow_7[0].eprom_address = 0;
    // var_grow_7[0].eprom_size = 255;
    // var_grow_7[0].var_name = "ssid_name";
    // var_grow_7[0].var_string = &ssid_name;

    // var_grow_7[1].pid = 0x01;
    // var_grow_7[1].service = 0x07;
    // var_grow_7[1].descr = "WIFI Password";
    // var_grow_7[1].eprom_address = 256;
    // var_grow_7[1].eprom_size = 255;
    // var_grow_7[1].var_name = "ssid_pwd";
    // var_grow_7[1].var_string = &ssid_pwd;

    // var_grow_7[2].pid = 0x02;
    // var_grow_7[2].service = 0x07;
    // var_grow_7[2].descr = "Local IP";
    // var_grow_7[2].eprom_address = 512;
    // var_grow_7[2].eprom_size = 16;
    // var_grow_7[2].var_name = "ipaddress";
    // var_grow_7[2].var_string = &ipaddress;

    // var_grow_7[3].pid = 0x03;
    // var_grow_7[3].service = 0x07;
    // var_grow_7[3].descr = "Local Gateway";
    // var_grow_7[3].eprom_address = 768;
    // var_grow_7[3].eprom_size = 16;
    // var_grow_7[3].var_name = "gateway";
    // var_grow_7[3].var_string = &gateway;

    // var_grow_7[4].pid = 0x04;
    // var_grow_7[4].service = 0x07;
    // var_grow_7[4].descr = "SubNet";
    // var_grow_7[4].eprom_address = 1024;
    // var_grow_7[4].eprom_size = 16;
    // var_grow_7[4].var_name = "subnet";
    // var_grow_7[4].var_string = &subnet;

    // var_grow_7[5].pid = 0x05;
    // var_grow_7[5].service = 0x07;
    // var_grow_7[5].descr = "HA IP";
    // var_grow_7[5].eprom_address = 1280;
    // var_grow_7[5].eprom_size = 16;
    // var_grow_7[5].var_name = "ha_ip";
    // var_grow_7[5].var_string = &ha_ip;

    // var_grow_7[6].pid = 0x06;
    // var_grow_7[6].service = 0x07;
    // var_grow_7[6].descr = "HA UserName";
    // var_grow_7[6].eprom_address = 1536;
    // var_grow_7[6].eprom_size = 255;
    // var_grow_7[6].var_name = "ha_user";
    // var_grow_7[6].var_string = &ha_user;

    // var_grow_7[7].pid = 0x07;
    // var_grow_7[7].service = 0x07;
    // var_grow_7[7].descr = "HA Password";
    // var_grow_7[7].eprom_address = 1792;
    // var_grow_7[7].eprom_size = 255;
    // var_grow_7[7].var_name = "ha_pwd";
    // var_grow_7[7].var_string = &ha_pwd;

    // var_grow_7[8].pid = 0x08;
    // var_grow_7[8].service = 0x07;
    // var_grow_7[8].descr = "HA Device Name";
    // var_grow_7[8].eprom_address = 2048;
    // var_grow_7[8].eprom_size = 255;
    // var_grow_7[8].var_name = "ha_device_name";
    // var_grow_7[8].var_string = &ha_device_name;

    var_grow_7[9].pid = 0x09;
    var_grow_7[9].service = 0x07;
    var_grow_7[9].descr = "Owner Name";
    var_grow_7[9].eprom_address = 2304;
    var_grow_7[9].eprom_size = 255;
    var_grow_7[9].var_name = "owner_name";
    var_grow_7[9].var_string = &owner_name;

    var_grow_7[10].pid = 0x0A;
    var_grow_7[10].service = 0x07;
    var_grow_7[10].descr = "UserName";
    var_grow_7[10].eprom_address = 2560;
    var_grow_7[10].eprom_size = 255;
    var_grow_7[10].var_name = "user_name";
    var_grow_7[10].var_string = &user_name;

    var_grow_7[11].pid = 0x0B;
    var_grow_7[11].service = 0x07;
    var_grow_7[11].descr = "UserName Password";
    var_grow_7[11].eprom_address = 2816;
    var_grow_7[11].eprom_size = 255;
    var_grow_7[11].var_name = "user_pwd";
    var_grow_7[11].var_string = &user_pwd;

    //next address 2878
    
    //===================================
    //===================================
    //===================================
    //      SERVICE 8
    //===================================
    //===================================

    //initial address service 7 1024
    //last address service 7 7680


    // var_grow_8[0].pid = 0x00;
    // var_grow_8[0].service = 0x08;
    // var_grow_8[0].descr = "WIFI SSID";
    // var_grow_8[0].eprom_address = 0;
    // var_grow_8[0].eprom_size = 255;
    // var_grow_8[0].var_name = "ssid_name";
    // var_grow_8[0].var_string = &ssid_name;

}