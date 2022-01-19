/*
 * menu.c
 *
 *  Created on: Jan 19, 2022
 *      Author: anton
 */
int state=0;
#include "menu.h"
void add_spaces(char *dest, int num_of_spaces) {
    int len = strlen(dest);
    memset( dest+len, ' ', num_of_spaces );
    dest[len + num_of_spaces] = '\0';
}
void menuDispRoutine()
{
	int nr_of_states=3;
	for(int i=0;i<2;i++)
	{
		LCD_SetCursor(&hlcd1, i, 0);
		char buffer[17];
		int buf=(state+i)%(nr_of_states);
		switch(buf)
		{
			case 0:
			{
				int duty=100*__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_2)/20000.0f;
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
void menubuttons(uint16_t ADCconv)
{

//	if (ADCconv < 60) {
//	   lcd.print ("Right ");
//	 }
//	 else if (x < 200) {
//	   lcd.print ("Up    ");
//	 }
//	 else if (x < 400){
//	   lcd.print ("Down  ");
//	 }
//	 else if (x < 600){
//	   lcd.print ("Left  ");
//	 }
//	 else if (x < 800){
//	   LCD.print ("Select");
//	 }
}
