/* Escreva uma função que receba como argumento o ano e retorne 1 se for ano bissexto ou 0 se não 
for um ano bissexto. O programa deve informar o resultado. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int bissexto(int ano) {
	if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
	setlocale(LC_ALL, "Portuguese");

	int ano;
	
	printf("Digite o ano: ");
	scanf("%d", &ano);
	
	if (bissexto(ano) == 1) {
		printf("O ano informado é bissexto.");
	}
	else {
		printf("O ano informado não é bissexto.")
	}
}
