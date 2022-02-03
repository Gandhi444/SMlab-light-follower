/*
 * Regulator.h
 *
 *  Created on: Jan 17, 2022
 *      Author: anton
 */
#include "arm_math.h"
#include "stdint.h"
#include <stdlib.h>
#define KD 0
#define KI 0.3
#define KP 0.03
#define Tp 0.1

void PID_init(arm_pid_instance_f32 *PID);
int Regulation(arm_pid_instance_f32 *PID, int e);
