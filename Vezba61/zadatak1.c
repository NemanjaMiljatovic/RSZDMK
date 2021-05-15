/**
 * @file	main.c
 * @brief	Aplikacija koja vrsi kapitalizaciju teksta
 * @author	Milica Panic
 * @date    05-12-2021
 */
///Standardna arduino biblioteka
#include <avr/io.h>
///Biblioteka koja omogucava koriscenje funkcije kasnjenja _delay_ms()
#include <util/delay.h>
///Bibliteka koj aomogucava pristup podacima u flash memoriji
#include <avr/pgmspace.h>
///Biblioteka koja sadrzi definicije standardnih oznacenih i neoznacenih tipova
#include <stdint.h>
///Standardna C biblioteka
#include <stdio.h>
///Pristup usart statickoj biblioteci
#include "../usart/usart.h"

/**
 * Kapitalizacija - Funkcija koja kapitalizuje ulazni tekst
 * @param tekst - ulaz tipa uint8_t - tekst koji se unosi
 * @return Nema povratne vrijednosti
 */
void Kapitalizacija (uint8_t tekst[])
{
	uint16_t duzina;

	for(duzina = 0;tekst[duzina] != '\0';duzina++)
	{
		for(uint16_t i = 0; i < duzina; i++)
		{
			if(tekst[i] >= 'a' && tekst[i] <= 'z')
			{
				tekst[i] += 'A' - 'a';
			}

		}
	}
	usartPutString_P(PSTR("Kapitalizovani tekst je: "));
	usartPutString(tekst);
	usartPutString_P(PSTR("\r\n"));

}

/**
 * main - Funkcija koja implementira glavnu operaciju
 * @param Nema parametara
 * @return Nema povratne vrijednosti
 */
int main()
{
	//inicijalizacija
	usartInit(9600);
	//ulaz
	uint8_t tekst[64];


	//glavna petlja
	while(1)
	{
		usartPutString_P(PSTR("Unesite tekst: \r\n"));
		while(!usartAvailable())
		;
		_delay_ms(50);

		usartGetString(tekst);

		Kapitalizacija(tekst);

	}


	return 0;
}
