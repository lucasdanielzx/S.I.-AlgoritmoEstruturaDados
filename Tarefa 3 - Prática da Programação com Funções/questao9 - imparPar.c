/* Fa�a um programa que leia um n�mero, passe este n�mero como par�metro para uma fun��o que 
retorne 0 se o n�mero for par ou 1 se o n�mero for �mpar. O programa deve informar o resultado. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int imparPar(int numero) {
	if(numero % 2 == 0) {
			printf("N�mero: %d - Par\n", numero);
		}
		else {
			printf("N�mero: %d - Impar\n", numero);
		}
}

int main () {
	setlocale(LC_ALL, "Portuguese");

	int numero;
	
	printf("Digite um n�mero: ");
	scanf("%d", &numero);
	
	imparPar(numero);	
}
