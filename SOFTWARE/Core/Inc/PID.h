/*
 * PID.h
 *
 *  Created on: Jan 17, 2022
 *      Author: anton
 */
#include "arm_math.h"
#include "stdint.h"
#define KD 0
#define KI 0.5
#define KP 0
#define Tp 0.001

void PID_init(arm_pid_instance_f32 *PID);
int PID_Routine(arm_pid_instance_f32 *PID,float ADC[]);
