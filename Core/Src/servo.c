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
	SERVO_SetAngle(90); // Center the servo on init
}

void SERVO_SetAngle(uint8_t angle){
    // Limit angle to safe range
    if(angle > 100)
        angle = 100;
    if(angle < 80)
        angle = 80;

    printf("Servo angle: %d\r\n", angle);

    uint16_t pulse = 250 + (angle * per_deg);

    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
}
