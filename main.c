
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_Direction DDRD
#define LED_PORT	  PORTD
#define LED_chuc 0
#define LED_dvi  1
char array[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void display(int);

int main(void)
{
    // DEFINE LED
	DDRC |= (1<<LED_chuc) | (1<<LED_dvi);
	LED_Direction = 0xff; // Set tat ca cac chan thanh 1111 1111 (1 = out put, 0 = input ) - DDRD (1,0) SET CHAN RA VAO
	LED_PORT = 0xff;   // Set ta ca cac port cua D thanh 1111 1111 (vi chon led anode 1 tat, 0 sang ) mac dinh se tat
	
    while (1) 
    {
		display(07);
    }
}

void display(int a) 
{
	int chuc = a/10;
	int dvi = a%10;
	PORTC &= ~(1<<LED_dvi);
	LED_PORT = array[chuc];
	PORTC |= (1<<LED_chuc);
	_delay_ms(200);
	PORTC &= ~(1<<LED_chuc);
	LED_PORT = array[dvi];
	PORTC |= (1<<LED_dvi);
	_delay_ms(200);	
}
