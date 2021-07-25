#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "binarytree.h"

#define UNDEFINE -9999
#define PI 3.14159265

int getDegree(char operator);
int getCharType(char value);
float evaluateTree(addrNode T, bool *isValid);
bool validateExpression(char *expression);
void convertExpression(char **expression, float *calculateResult, bool *isValid);

#endif