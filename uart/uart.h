/* -------------------------------------
 * SUNriaX Project
 * www.sunriax.at
 * -------------------------------------
 * Hardware: Megacard/STK500
 * Platform: ATmega8/16/32
 * -------------------------------------
 * Name: uart
 * Ver.: 1.0 Release
 * Type: Library
 * Text: Routines for initializing and
 *       communication over UART
 * -------------------------------------
 */

#ifndef UART_H_
#define UART_H_

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#ifndef BAUD
	#define BAUD 115200UL
#endif

#include <stdio.h>
#include <avr/io.h>
#include <util/setbaud.h>

int uart_init(void);
int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);

#endif /* UART_H_ */