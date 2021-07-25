#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarytree.h"
#include "calculator.h"

int main(){
	char expressionInput[512];
	char *expressionInputAddr;
	float calculateResult;
	bool isValid;

	scanf("%s", expressionInput);

	isValid = validateExpression(expressionInput);
	
	if(isValid) {
		expressionInputAddr = expressionInput;
		convertExpression(&expressionInputAddr, &calculateResult, &isValid);
	} else {
		printf("Expression Not Valid\n");
	}

	if (isValid) {
		printf("\n%.2f\n", calculateResult);
	}
}