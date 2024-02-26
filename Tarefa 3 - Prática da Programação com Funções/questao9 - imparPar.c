/* Faça um programa que leia um número, passe este número como parâmetro para uma função que 
retorne 0 se o número for par ou 1 se o número for ímpar. O programa deve informar o resultado. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int imparPar(int numero) {
	if(numero % 2 == 0) {
			printf("Número: %d - Par\n", numero);
		}
		else {
			printf("Número: %d - Impar\n", numero);
		}
}

int main () {
	setlocale(LC_ALL, "Portuguese");

	int numero;
	
	printf("Digite um número: ");
	scanf("%d", &numero);
	
	imparPar(numero);	
}
