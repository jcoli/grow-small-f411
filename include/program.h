/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include "structures.h"

void program_begin();
void vpd_calculate();
void append_struct_life_bit();
bool eraseDataSetup();
void avg_calculate();

#endif