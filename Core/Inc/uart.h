/*
 * uart.h
 *
 *  Created on: May 17, 2025
 *      Author: ionut
 */

#include "main.h"

#ifndef INC_UART_H_
#define INC_UART_H_

extern UART_HandleTypeDef huart1;

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

#endif /* INC_UART_H_ */
