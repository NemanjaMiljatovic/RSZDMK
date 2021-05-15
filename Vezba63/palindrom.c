/**
 * @file	main.c
 * @brief	Aplikacija koja vrsi provjeru da li je unesena rec palindrom
 * @author	Milica Panic
 * @date    05-12-2021
 * @version 1.0
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
 * Operacija - Funkcija koja na osnovu unesenog operatora odredjuje i vrsi operaciju
 * @param op - ulaz tipa uint8_t - unesena rec
 * @return - Nema povratne vrijednosti
 */
void Palindrom(uint8_t tekst[])
{
	uint16_t duzina;
	uint16_t pom = 0;

	for(duzina = 0;tekst[duzina] != '\0';duzina++);
	   for(uint16_t i = 0; i < duzina; i++)
	   {
		   if(tekst[i] == tekst[duzina - 1 - i])
		   {
			   pom++;
		   }
	   }
if(pom == duzina)
{
	usartPutString_P(PSTR("Vasa rec jeste palindrom.\r\n"));
}
else
{
	usartPutString_P(PSTR("Vasa rec nije palindrom.\r\n"));
}
}

/**
 * main - Funkcija koja implementira glavnu operaciju
 * @param Nema parametara
 * @return Nema povratnu vrijednost
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
		usartPutString_P(PSTR("Unesite rec: \r\n"));
		while(!usartAvailable())
		;
		_delay_ms(50);

		usartGetString(tekst);

		Palindrom(tekst);

	}
	return 0;

}

