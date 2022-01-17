/*
 * PID.c
 *
 *  Created on: Jan 17, 2022
 *      Author: anton
 */
#include "PID.h"
void PID_init(arm_pid_instance_f32 *PID)
{
	PID->Kd=KD*Tp;
	PID->Ki=KI*Tp;
	PID->Kp=KP*Tp;
	arm_pid_init_f32(PID, 0);
}
int PID_Routine(arm_pid_instance_f32 *PID,float ADC[])
{
	float32_t e=ADC[1]-ADC[0];
	int u=arm_pid_f32(PID,e);
	if(u>1000)u=1000;
	if(u<0)u=0;
	return u;
}
