#ifndef _CALCULATORTEMPERATURE_H_
#define _CALCULATORTEMPERATURE_H_

#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x,int y);
float celciusConverter(float c, char to);
float reamurConverter(float r, char to);
float fahrenheitConverter(float f, char to);
float kelvinConverter(float k, char to);
void suhuConverterMenu();

#endif