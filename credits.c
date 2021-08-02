#include "credits.h"
#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void creditsMenu() {
	char ch = '\0';
	while (tolower(ch) != 'b') {
		system(CLEARSCREEN);
		puts("Dibuat oleh: ");
		puts("1. Eben Ezer Napitu");
		puts("2. Luthfi Maajid");
		puts("3. Sobri Waskito Aji\n");
		puts("Politeknik Negeri Bandung 2020/2021\n\n");

		printf("ketik (b) untuk kembali ");
  	  	while ((ch = getchar()) != '\n' && ch != EOF);
		scanf("%c", &ch);
	}
}