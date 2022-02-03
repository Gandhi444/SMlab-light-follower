/*
 * menu.h
 *
 *  Created on: Jan 19, 2022
 *      Author: anton
 */
#include "lcd.h"
#include "lcd_config.h"
#include <stdio.h>
#include "stm32l4xx_hal_tim.h"
#include "tim.h"
#include "main.h"

#define NR_OF_STATES 3

void add_spaces(char *dest, int num_of_spaces);
void menuDispRoutine();
void menubuttons(uint16_t GPIO_button);

