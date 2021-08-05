#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "binarytree.h"
#include "common.h"

#define UNDEFINE -9999
#define PI 3.14159265

void printToScreen(char* expression) {
	int i = 0;
	while(expression[i] != '\0') {
		if(expression[i] == 's') {
			printf("sin");
		} else if(expression[i] == 'c') {
			printf("cos");
		} else if(expression[i] == 't') {
			printf("tan");
		} else if(expression[i] == 'l') {
			printf("log");
		} else if(expression[i] == 'n') {
			printf("ln");
		} else {
			printf("%c",expression[i]);
		}
		i++;
	}
}

/* 	Type: Function
	Deskripsi: Menampilkan ui lalu menerima ekpresi matematika dari user input dan mengembalikan ekpresi matematikanya
	Penanggung Jawab: Luthfi Maajid
	*/
char* calculatorMenu() {
	int pilihan = 1;
	static char math_expression[1001];
	int char_counter = 0;

	// Ensure to delete all character
	for (int i=strlen(math_expression)-1; i >= 0; i--) {
		math_expression[i] = '\0';
	}

	do {
		system(CLEARSCREEN);
		printf("KALKULATOR UMUM\n");
		printf("===============================\n");
		// printf("%s\n", math_expression);
		printToScreen(math_expression);
		printf("\n");
		printf("===============================\n");
		printf("Contoh Ekspresi Valid\n");
		printf("Tambah/Kurang : 14+88-19+3\n");
		printf("Kali/Bagi     : 80/5+8*9/24\n");
		printf("Pangkat/Akar  : v144+52/2*2^3-24+2^5/16\n");
		printf("Trigonometri  : v225*3/9+86*sin30+cos60   (dalam derajat, misal sin30 = 1/2)\n");
		printf("Logaritma     : 8*9/24+log100+ln80   (log100 = 10log100 = 2)\n");

		printf("\nPilihan Tombol\n");
		printf("(0) 0     (10) (       (20) tan\n");
		printf("(1) 1     (11) )       (21) log\n");
		printf("(2) 2     (12) +       (22) ln\n");
		printf("(3) 3     (13) -       (23) .\n");
		printf("(4) 4     (14) *       (24) =\n");
		printf("(5) 5     (15) /       (25) <-\n");
		printf("(6) 6     (16) ^       (26) CE\n");
		printf("(7) 7     (17) v        \n");
		printf("(8) 8     (18) sin      \n");
		printf("(9) 9     (19) cos      \n");

		printf("Masukkan tombol diantara 1 s.d. 26 untuk memilih satu karakter\n");
		printf("INPUT: ");
		scanf("%d", &pilihan);

		if ((pilihan < 0) || (pilihan >26)) {
			// user mamasukkan opsi yang tidak sesuai
			printf("Pilih opsi yang benar!\n");
		}

		if (pilihan == 25) {
			// user memilih opsi <- (25) hapus 1 char
			if (char_counter == 0) {
				continue;
			}
			char_counter--;
			math_expression[char_counter] = '\0';
		} else if (pilihan == 26) {
			// user memilih opsi CE (26) hapus semua
			for (int i=char_counter-1; i >= 0; i--) {
				math_expression[i] = '\0';
			}
			char_counter = 0;
		} else {
			if (pilihan < 10) {
				math_expression[char_counter] = pilihan + '0';
			} else {
				switch (pilihan) {
					case 10:
						math_expression[char_counter] = '(';
						break;

					case 11:
						math_expression[char_counter] = ')';
						break;
	
					case 12:
						math_expression[char_counter] = '+';
						break;
					
					case 13:
						math_expression[char_counter] = '-';
						break;

					case 14:
						math_expression[char_counter] = '*';
						break;

					case 15:
						math_expression[char_counter] = '/';
						break;

					case 16:
						math_expression[char_counter] = '^';
						break;

					case 17:
						math_expression[char_counter] = 'v';
						break;

					case 18:
						math_expression[char_counter] = 's';
						break;
							
					case 19:
						math_expression[char_counter] = 'c';
						break;

					case 20:
						math_expression[char_counter] = 't';
						break;

					case 21:
						math_expression[char_counter] = 'l';
						break;
					
					case 22:
						math_expression[char_counter] = 'n';
						break;

					case 23:
						math_expression[char_counter] = '.';
						break;

					default:
						break;
				}
			}
			char_counter++;
		}
	} while (pilihan != 24);

	return (char*) math_expression;
}

/*	Type: Function
	Deskripsi: Mendapatkan derajat dari suatu operator, mengembalikan dalam bentuk integer
	Penanggung Jawab: Sobri Waskito Aji
	*/
int getDegree(char operator) {
	switch(operator){
		case '+' : return 1; break;
		case '-' : return 1; break;
		case '*' : return 2; break;
		case '/' : return 2; break;
		case '^' : return 3; break;
		case 'v' : return 4; break;
		case 's' : return 4; break;
		case 'c' : return 4; break;
		case 't' : return 4; break;
		case 'l' : return 4; break;
		case 'n' : return 4; break;
		case '.' : return 5; break;
		default : return 99; break;
	}
}

/*	Type: Function
	Deskripsi: Mendapatkan jenis/tipe dari suatu karakter, apakah angka, tanda kurung, atau operator,
			mengembalikan dalam bentuk integer
	Penanggung Jawab: Sobri Waskito Aji
	*/
int getCharType(char value) {
	switch(value){
		case '0' : return 0; break;
		case '1' : return 1; break;
		case '2' : return 2; break;
		case '3' : return 3; break;
		case '4' : return 4; break;
		case '5' : return 5; break;
		case '6' : return 6; break;
		case '7' : return 7; break;
		case '8' : return 8; break;
		case '9' : return 9; break;
		case '(' : return -2; break;
		default : return -1; break; // operator
	}
}

/*	Type: Function
	Deskripsi: Melakukan perhitungan terhadap Binary Expression Tree dengan Root = T yang dilakukan secara PostOrder
			Mengembalikan dalam bentuk float
	Penanggung Jawab: Sobri Waskito Aji
	*/
float evaluateTree(addrNode T, bool *isValid) {
	float calcResult=0;
	if(*isValid) { // ekspresi valid
		float leftCalc=0, rightCalc=0;
		bool isValid2=true;
		
		if((Info(T)).operator == 'b'){ // Operand
			calcResult = (Info(T)).value;
		} else if((Info(T)).operator == '+') { // Operasi Addition ( + )
			leftCalc = evaluateTree(Left(T),&isValid2);
			rightCalc = evaluateTree(Right(T),&isValid2);
			calcResult = leftCalc+rightCalc;
		} else if((Info(T)).operator == '-') { // Operasi Substraction ( - )
			leftCalc = evaluateTree(Left(T),&isValid2);
			rightCalc = evaluateTree(Right(T),&isValid2);
			calcResult = leftCalc-rightCalc;
		} else if((Info(T)).operator == '*') { // Operasi Multiplication ( * )
			leftCalc = evaluateTree(Left(T),&isValid2);
			rightCalc = evaluateTree(Right(T),&isValid2);
			calcResult = leftCalc*rightCalc;
		} else if((Info(T)).operator == '/') { // Operasi Division ( / )
			leftCalc = evaluateTree(Left(T),&isValid2);
			rightCalc = evaluateTree(Right(T),&isValid2);
			if(rightCalc != 0){
				calcResult = leftCalc/rightCalc;
			} else{
				*isValid = false;
			}
		} else if((Info(T)).operator == '^') { // Operasi Exponent ( ^ )
			leftCalc = evaluateTree(Left(T),&isValid2);
			rightCalc = evaluateTree(Right(T),&isValid2);
			if((leftCalc < 0) && ((rightCalc) > (-1)) && (leftCalc < 1)){ // operand tidak boleh negatif
				*isValid = false;
			} else{
				calcResult = pow(leftCalc,rightCalc);
			}
		} else if((Info(T)).operator == 'v') { // Operasi Square Root ( √ )
			if(Left(T) != Nil) leftCalc = evaluateTree(Left(T),&isValid2);
			if(Right(T) != Nil) rightCalc = evaluateTree(Right(T),&isValid2);
			if(rightCalc < 0) { // operand tidak boleh negatif
				*isValid = false;
			} else {
				calcResult = sqrt(rightCalc);
			}
		} else if((Info(T)).operator == 's') { // Operasi Trigonometri ( Sin )
			if(Left(T) != Nil) leftCalc = evaluateTree(Left(T),&isValid2);
			if(Right(T) != Nil) rightCalc = evaluateTree(Right(T),&isValid2);
			if(rightCalc < 0) {
				*isValid = false;
			} else {
				calcResult = sin(rightCalc*PI/180);
			}
		} else if((Info(T)).operator == 'c') { // Operasi Trigonometri ( Cos )
			if(Left(T) != Nil) leftCalc = evaluateTree(Left(T),&isValid2);
			if(Right(T) != Nil) rightCalc = evaluateTree(Right(T),&isValid2);
			if(rightCalc < 0) {
				*isValid = false;
			} else {
				calcResult = cos(rightCalc*PI/180);
			}
		} else if((Info(T)).operator == 't') { // Operasi Trigonometri ( Tan )
			if(Left(T) != Nil) leftCalc = evaluateTree(Left(T),&isValid2);
			if(Right(T) != Nil) rightCalc = evaluateTree(Right(T),&isValid2);
			if(rightCalc < 0) {
				*isValid = false;
			} else {
				calcResult = tan(rightCalc*PI/180);
			}
		} else if((Info(T)).operator == 'l') { // Operasi Logaritma ( Log10 )
			if(Left(T) != Nil) leftCalc = evaluateTree(Left(T),&isValid2);
			if(Right(T) != Nil) rightCalc = evaluateTree(Right(T),&isValid2);
			if(rightCalc < 0) {
				*isValid = false;
			} else {
				calcResult = log10(rightCalc);
			}
		} else if((Info(T)).operator == 'n') { // Operasi Logaritma ( Ln )
			if(Left(T) != Nil) leftCalc = evaluateTree(Left(T),&isValid2);
			if(Right(T) != Nil) rightCalc = evaluateTree(Right(T),&isValid2);
			if(rightCalc < 0) {
				*isValid = false;
			} else {
				calcResult = log(rightCalc);
			}
		} else if((Info(T)).operator == '.') { // Operasi Lain ( Decimal )
			leftCalc = evaluateTree(Left(T),&isValid2);
			rightCalc = evaluateTree(Right(T),&isValid2);
			while((rightCalc > 1) || (rightCalc < -1)){
				rightCalc /= 10;
			}
			calcResult = leftCalc+rightCalc;
		} else {
			calcResult = 0;
		}
	}

	return calcResult;
}

/*	Type: Function
	Deskripsi: Memvalidasi input ekspresi matematika dengan mencocokkan jumlah tanda kurung
			Mengembalikan dalam bentuk boolean
	Penanggung Jawab: Sobri Waskito Aji
	*/
bool validateExpression(char *expression) {
	int leftParentheses=0, rightParentheses=0;
	
	// iterasi karakter pada ekspresi
	while(*expression != '\0'){
		if(*expression == '(')
			leftParentheses++;
		else if(*expression == ')')
			rightParentheses++;
		
		expression++;
	}
	
	return (leftParentheses == rightParentheses);
}

/* 	Type: Procedure
	Membangun Tree dengan aturan Binary Expression Tree
	I.S. : Tree belum terbentuk
	F.S. : Tree telah terbentuk berjenis Binary Expression Tree
	Penanggung Jawab: Sobri Waskito Aji
	*/
void convertExpression(char **expression, float *calculateResult, bool *isValid) {
	addrNode T, lastNode, searchPos;
	infotype tempInfo;
	float tempCalcResult;
	int currentDegree;
	bool isLastOperator=false, isDecimal=false;

	*isValid = true;
	
	// inisialisasi Tree
	tempInfo = CreateInfo(0,'b');
	T = Tree(tempInfo);
	lastNode = T;
	currentDegree = 10;
	
	// iterasi karakter pada ekspresi matematika(String)
	while(**expression != '\0' && **expression != ')' && *isValid) {
		// debug
		// printf("[%c %d] ",**expression, isLastOperator);

		if(getCharType(**expression) == -2) { // merupakan jenis tanda kurung '('
			*expression += 1;
			convertExpression(expression, &tempCalcResult, isValid); // rekursif hingga ditemui tanda kurung ')'
			if(*isValid) {
				tempInfo = CreateInfo(tempCalcResult, 'b');
				if (Info(lastNode).operator == 'b') {
					// replace node
					Info(lastNode) = tempInfo;
				} else {
					// add anak kanan
					AddLeaf(&lastNode, false, tempInfo);
					lastNode = Right(lastNode);
				}
				isLastOperator = false;
			}

		} else if(getCharType(**expression) == -1) { // merupakan jenis operator
			tempInfo = CreateInfo(UNDEFINE, **expression);
			if(getDegree(**expression) != 4) { // bukan merupakan operator trigonometri(akar(v)/sin/cos/tan/log/ln)
				if(!isLastOperator) { // karakter sebelumnya bukan operator
					if(getDegree(**expression) == 5) { // merupakan titik(decimal)
						if(isDecimal){ // karakter sebelumnya titik
							*isValid = false;
						} else {
							isDecimal = true;
							if(getDegree(**expression) <= currentDegree){ // merupakan derajat tertinggi
								// Restrukturisasi Tree
								ChangeRoot(&T, tempInfo, true);
								lastNode = T;
							} else {
								// Rotasi kiri
								ChangeRoot(&lastNode, tempInfo, true);
							}
							currentDegree = getDegree(**expression);
							isLastOperator = true;
						}
					} else { // bukan titik (operator)
						isDecimal = false;
						if(getDegree(**expression) < currentDegree){
							if(getDegree(Info(T).operator) < getDegree(**expression)) { // merupakan derajat tertinggi
								searchPos = Parent(lastNode);
								if(searchPos == T) {
									while(getDegree(Info(Parent(searchPos)).operator) > getDegree(**expression)) {
										searchPos = Parent(searchPos);
									}
									// Restrukturisasi Sub Tree
									ChangeRoot(&searchPos, tempInfo, true);
									lastNode = searchPos;
								} else {
									// Restrukturisasi Tree
									ChangeRoot(&T, tempInfo, true);
									lastNode = T;
								}
							} else {
								// Restrukturisasi Tree
								ChangeRoot(&T, tempInfo, true);
								lastNode = T;
							}
						} else if(getDegree(**expression) == currentDegree) {
							if(getDegree(**expression) == 1) {
								// Restrukturisasi Tree
								ChangeRoot(&T, tempInfo, true);
								lastNode = T;
							} else {
								// Restrukturisasi Sub Tree
								searchPos = Parent(lastNode);
								if(searchPos != T) {
									while(getDegree(Info(Parent(searchPos)).operator) > getDegree(**expression) && Parent(searchPos) != Nil) {
										searchPos = Parent(searchPos);
									}
									// Restrukturisasi Sub Tree
									ChangeRoot(&searchPos, tempInfo, true);
									lastNode = searchPos;
								} else {
									// Restrukturisasi Tree
									ChangeRoot(&T, tempInfo, true);
									lastNode = T;
								}
							}
						} else {
							if(getDegree(**expression) == 1) {
								// Restrukturisasi Tree
								ChangeRoot(&T, tempInfo, true);
								lastNode = T;
							} else {
								// Rotasi kiri
								ChangeRoot(&lastNode, tempInfo, true);
							}
						}
						currentDegree = getDegree(**expression);
						isLastOperator = true;
					}
				} else { // karakter sebelumnya operator
					*isValid = false;
				}
			} else { // merupakan operator trigonometri(akar(v)/sin/cos/tan/log/ln)
				if(isLastOperator) { // karakter sebelumnya operator
					isDecimal = false;
					// Add anak kanan
					AddLeaf(&lastNode, false, tempInfo);
					lastNode = Right(lastNode);
					currentDegree = getDegree(**expression);
					isLastOperator = true;
				} else { // karakter sebelumnya bukan operator
					if(Info(lastNode).value != 0) { // node pertama
						*isValid = false;
					} else {
						// Replace node
						isDecimal = false;
						Info(lastNode) = tempInfo;
						currentDegree = getDegree(**expression);
						isLastOperator = true;
					}
				}
			}
		} else { // merupakan operand
			if (Info(lastNode).operator == 'b') { // node pertama(operand pertama)
				// tambah dan replace node
				Info(lastNode).value = Info(lastNode).value * 10 + getCharType(**expression);
			} else {
				// add anak kanan
				tempInfo = CreateInfo(getCharType(**expression), 'b');
				AddLeaf(&lastNode, false, tempInfo);
				lastNode = Right(lastNode);
			}
			isLastOperator = false;
		}

		// debug
		// printf(" Last Node %c , %.2f\n",Info(lastNode).operator, Info(lastNode).value);

		// mengabaikan whitespace
		while (**expression == ' ') {
			*expression += 1;
		}

		// lanjut ke karakter selanjutnya
		*expression += 1;
	}

	// debug
	// PrintTree(T);
	
	if(*isValid) { // penyusunan ekspresi valid
		*calculateResult = evaluateTree(T, isValid);
		if(!*isValid) { // perhitungan tidak valid
			printf("Calculation Error\n");
		}
	} else {
		printf("Expression Error\n");
	}
	
	DestroyTree(T);
}