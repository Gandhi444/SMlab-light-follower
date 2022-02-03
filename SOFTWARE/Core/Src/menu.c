/*
 * menu.c
 *
 *  Created on: Jan 19, 2022
 *      Author: anton
 */
#include "menu.h"


int state=1;


/**
 * @brief add spaces to string
 * @param[in] *dest pointer to a string to add too
 * @param[in] num_of_spaces number of spaces to add
 * @return none
 */
void add_spaces(char *dest, int num_of_spaces) {
    int len = strlen(dest);
    memset( dest+len, ' ', num_of_spaces );
    dest[len + num_of_spaces] = '\0';
}

/**
 * @brief Display things on LCD
 * @return none
 */
void menuDispRoutine()
{
	for(int i=0;i<2;i++)
	{
		LCD_SetCursor(&hlcd1, i, 0);
		char buffer[17];
		int buf=(state+i)%(NR_OF_STATES);
		switch(buf)
		{
			case 0:
			{
				int duty=100*__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_1)/20000.0f;
				int n=sprintf(buffer,"LD1 DUTY %d",duty);
				add_spaces(buffer,16-n);
				LCD_printStr(&hlcd1,buffer);
				break;
			}
			case 1:
			{
				int duty=100*__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_3)/20000;
				int n=sprintf(buffer,"LD2 DUTY %d",duty);
				add_spaces(buffer,16-n);
				LCD_printStr(&hlcd1,buffer);
				break;
			}
			case 2:
			{
				int duty=100*__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_4)/20000;
				int n=sprintf(buffer,"LD3 DUTY %d",duty);
				add_spaces(buffer,16-n);
				LCD_printStr(&hlcd1,buffer);
				break;
			}

		}
	}
}

/**
 * @brief Handle lcd buttons presses
 * @param[in] GPIO_Pin pin that was pressed
 * @return none
 */
void menubuttons(uint16_t GPIO_button)
{
	if(GPIO_button==Left_Pin)
	{
		switch(state)
		{
			case 0: __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_1)-200);break;
			case 1: __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_3)-200);break;
			case 2: __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_4)-200);break;
		}
	}
	if(GPIO_button==Right_Pin)
		{
			switch(state)
			{
				case 0: __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_1)-200);break;
				case 1: __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_3)-200);break;
				case 2: __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_4)-200);break;
			}
		}
	if(GPIO_button==Down_Pin)
	{
		state=(state+1)%NR_OF_STATES;
	}
}
