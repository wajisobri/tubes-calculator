#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

float celciusConverter(float c, char to) {
    float result;
    
    if(to == 'R')
        result = (4/5) * c;
    else if(to == 'F')
        result = (9/5) * c + 32;
    else if(to == 'K')
        result = c + 32;
    else
        result = 0;

    return result;
}

float reamurConverter(float r, char to) {
    float result;

    if(to == 'C')
        result = (5/4) * r;
    else if(to == 'F')
        result = (9/4) * r + 32;
    else if(to == 'K')
        result = (5/4) * r + 273;
    else
        result = 0;

    return result;
}

float fahrenheitConverter(float f, char to) {
    float result;

    if(to == 'C')
        result = (5/9) * (f - 32);
    else if(to == 'R')
        result = (4/9) * (f - 32);
    else if(to == 'K')
        result = (5/9) * (f - 32) + 273;
    else
        result = 0;

    return result;
}

float kelvinConverter(float k, char to) {
    float result;

    if(to == 'C')
        result = k - 273;
    else if(to == 'F')
        result = (9/5) * (k - 273) + 32;
    else if(to == 'R')
        result = (4/5) * (k - 273);
    else
        result = 0;

    return result;
}