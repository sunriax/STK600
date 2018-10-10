/* -------------------------------------
 * SUNriaX Project
 * www.sunriax.at
 * -------------------------------------
 * Hardware: STK600
 * Platform: ATmega2560
 * -------------------------------------
 * Name: main.c
 * Ver.: 1.0 Release
 * Type: Executeable
 * Text: Demo application to initialize
 *       a UART communication
 * -------------------------------------
 */ 

#define F_CPU 16000000UL
#define BAUD 115200UL

// System libraries
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

// User libraries
#include "uart.h"

// Initialize FILE stream
static FILE std_uart_0 = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);

// Satic test variables for printf
static unsigned int x = 123;			// Numeric
static unsigned char a = 'A';			// Character
static unsigned char str[] = "Test";	// String
static double z = 123.43;				// Floating Point

int main(void)
{	
	uart_init();
	
	stdout = &std_uart_0;
	stdin = &std_uart_0;

    while (1)
    {
		// Print a String
		printf("Hello, world!\n");
		
		// Print different variables
		printf("Variables -> %d, %c, %s\n", x, a, str);
		
		// Compiler Parameter necessary: -Wl,-u,vfprintf -lprintf_flt -lm
		printf("Variable y: %f", z);
    }
}

