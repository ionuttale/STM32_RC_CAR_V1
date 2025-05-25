/*
 * engine.h
 *
 *  Created on: May 17, 2025
 *      Author: ionut
 */

#ifndef INC_ENGINE_H_
#define INC_ENGINE_H_

#include "stdint.h"
#include <stdio.h>

#define EnA    GPIO_PIN_2
#define EnB    GPIO_PIN_10
#define IN1    GPIO_PIN_14
#define IN2    GPIO_PIN_13
#define IN3    GPIO_PIN_12
#define IN4    GPIO_PIN_11

#define FORWARD 1
#define REVERSE 2
#define STOP 0

void ENGINE_Init(void);

void ENGINE_Enable(void);

void ENGINE_Set(uint8_t direction);

#endif /* INC_ENGINE_H_ */
