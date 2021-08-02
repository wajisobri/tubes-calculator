#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "calculator-temperature.h"
#include "common.h"


void gotoxy(int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

float celciusConverter(float c, char to) {
    float result;
    
    if(tolower(to) == 'r')
        result = (4.0/5.0) * c;
    else if(tolower(to) == 'f')
        result = (9.0/5.0) * c + 32;
    else if(tolower(to) == 'k')
        result = c + 273;
    else
        result = c;

    return result;
}

float reamurConverter(float r, char to) {
    float result;

    if(tolower(to) == 'c')
        result = (5.0/4.0) * r;
    else if(tolower(to) == 'f')
        result = (9.0/4.0) * r + 32;
    else if(tolower(to) == 'k')
        result = (5.0/4.0) * r + 273;
    else
        result = r;

    return result;
}

float fahrenheitConverter(float f, char to) {
    float result;

    if(tolower(to) == 'c')
        result = (5.0/9.0) * (f - 32);
    else if(tolower(to) == 'r')
        result = (4.0/9.0) * (f - 32);
    else if(tolower(to) == 'k')
        result = (5.0/9.0) * (f - 32) + 273;
    else
        result = f;

    return result;
}

float kelvinConverter(float k, char to) {
    float result;

    if(tolower(to) == 'c')
        result = k - 273;
    else if(tolower(to) == 'f')
        result = (9.0/5.0) * (k - 273) + 32;
    else if(tolower(to) == 'r')
        result = (4.0/5.0) * (k - 273);
    else
        result = k;

    return result;
}

bool validateInput(char c) {
    if(tolower(c) == 'c' || tolower(c) == 'r' || tolower(c) == 'f' || tolower(c) == 'k')
        return true;
    else
        return false;
}

void suhuConverterMenu() {
    char from, to;
    float fromTemp;
    char degree=248;

    printf("===============================\n");
    printf("=        Konversi Suhu        =\n");
    printf("===============================\n");
    printf("Unit Konversi\n");
    printf("R : Reamur      C : Celcius\n");
    printf("F : Fahrenheit  K : Kelvin\n");

    gotoxy(1,10);
    printf("DARI (C/R/F/K)  :");
    gotoxy(1,11);
    printf("SUHU (SATUAN%c)  :",degree);

    gotoxy(1,14);
    printf("KE (C/R/F/K)    :");
    gotoxy(1,15);
    printf("SUHU (SATUAN%c)  :",degree);

    do {
        gotoxy(19,10);
        scanf("%c",&from);
    } while(validateInput(from) == false);
    gotoxy(19,11);
    scanf("%f",&fromTemp);
    fflush(stdin);
    do {
        gotoxy(19,14);
        scanf("%c",&to);
    } while(validateInput(to) == false);

    float result;
    if(tolower(from) == 'c') {
        result = celciusConverter(fromTemp, to);
    } else if(tolower(from) == 'r') {
        result = reamurConverter(fromTemp, to);
    } else if(tolower(from) == 'f') {
        result = fahrenheitConverter(fromTemp, to);
    } else if(tolower(from) == 'k') {
        result = kelvinConverter(fromTemp, to);
    }

    gotoxy(19,15); printf("%.2f",result); 
}