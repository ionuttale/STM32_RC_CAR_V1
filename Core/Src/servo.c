/*
 * servo.c
 *
 *  Created on: May 17, 2025
 *      Author: ionut
 */


/*
 * servo.c
 *
 *  Created on: May 16, 2025
 *      Author: ionut
 */

#include "servo.h"
#include "stm32f1xx_hal.h"
// #include "usart.h"

extern TIM_HandleTypeDef htim2;

void SERVO_Init(){
	printf("SERVO Initialized\r\n");
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//	SERVO_SetAngle(90); // Center the servo on init
}

void SERVO_SetAngle(uint8_t angle){
    // Limit angle to safe range

    printf("Servo angle: %d\r\n", angle);

    uint16_t pulse = 500 + (angle * per_deg) + calib;
    printf("Pulse: %d\r\n", pulse);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
}
