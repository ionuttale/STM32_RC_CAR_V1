/*
 * engine.c
 *
 *  Created on: May 17, 2025
 *      Author: ionut
 */

#include "engine.h"
#include "stm32f1xx_hal.h"
// #include "uart.h"

// Initialize direction pins
void ENGINE_Init(void) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2 || GPIO_PIN_10 || GPIO_PIN_11 || GPIO_PIN_12 || GPIO_PIN_13 || GPIO_PIN_14, GPIO_PIN_RESET);
}

// Enable the motor driver
void ENGINE_Enable(void) {
    printf("Motor enabled\r\n");
    ENGINE_Set(STOP); // Stop the motor
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET); // Enable ENA
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET); // Enable ENB
}

// Set motor direction (FORWARD, REVERSE, STOP)
void ENGINE_Set(uint8_t direction) {
    switch (direction) {
        case FORWARD:
            printf("Motor forward\r\n");
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // IN1
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET); // IN2

            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);   // IN3
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET); // IN4

            break;
        case REVERSE:
            printf("Motor backward\r\n");
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // IN1
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET); // IN2

            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);   // IN3
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET); // IN4

            break;
        case STOP:
        default:
            printf("Motor stop\r\n");
            HAL_GPIO_WritePin(GPIOB, IN1, GPIO_PIN_RESET); // IN1
            HAL_GPIO_WritePin(GPIOB, IN2, GPIO_PIN_RESET); // IN2

            HAL_GPIO_WritePin(GPIOB, IN3, GPIO_PIN_RESET); // IN3
            HAL_GPIO_WritePin(GPIOB, IN4, GPIO_PIN_RESET); // IN4
            break;
    }
}
