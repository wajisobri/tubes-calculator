#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarytree.h"
#include "calculator.h"

int main(){
	char expressionInput[1001];
	char *expressionInputAddr;
	float calculateResult;
	bool isValid;

	strcpy(expressionInput, calculatorMenu());

	isValid = validateExpression(expressionInput);
	
	if(isValid) {
		expressionInputAddr = expressionInput;
		convertExpression(&expressionInputAddr, &calculateResult, &isValid);
	} else {
		printf("Expression Not Valid\n");
	}

	if (isValid) {
		printf("\nRESULT: %.2f\n", calculateResult);
	}
}