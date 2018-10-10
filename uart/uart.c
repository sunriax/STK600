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

#include "uart.h"

int uart_init(void)
{	
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	
	#if USE_2X
		UCSR0A |= (1<<U2X0);
	#else
		UCSR0A &= ~(1<<U2X0);
	#endif
	
		UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	
	return 0;
}

int uart_putchar(char data, FILE *stream)
{
	if (data == '\n')
		uart_putchar('\r', stream);
	
	while(!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
	
	return 0;
}

int uart_getchar(FILE *stream)
{
	while(!(UCSR0A & (1<<RXC0)));
	
	return UDR0;
}


