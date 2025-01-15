/**
Version: 0a
Tecnocoli - 01/2025
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F411 - GrowSmall
**/

#ifndef __BT_CONTROL_H__
#define __BT_CONTROL_H__

void bt_begin();
void on_receive_bt(String line1);
void setup_rtc(String msg);
void BTconnectionCheck();
void sendMsgBT();


#endif
