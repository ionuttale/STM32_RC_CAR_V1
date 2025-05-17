/*
 * servo.h
 *
 *  Created on: May 17, 2025
 *      Author: ionut
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "stdint.h"
#include <stdio.h>

#define per_deg 5.55

void SERVO_Init(void);

void SERVO_SetAngle(uint8_t angle);

#endif /* INC_SERVO_H_ */
