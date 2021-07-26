#ifndef	CALCULATOR_TEMEPATURE_H 
#define	CALCULATOR_TEMEPATURE_H 

#include <stdio.h>
#include <stdlib.h>


void gotoxy(int x,int y);

float celciusConverter(float c, char to);

float reamurConverter(float r, char to);

float fahrenheitConverter(float f, char to);

float kelvinConverter(float k, char to);

void suhuConverterMenu();

#endif