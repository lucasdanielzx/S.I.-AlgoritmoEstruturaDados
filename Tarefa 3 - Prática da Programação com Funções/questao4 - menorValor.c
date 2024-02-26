/* Crie uma função em linguagem C que receba 2 números e retorne o menor valor. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int menorValor (float numero1, float numero2) {
	if (numero1 == numero2) {
		printf("Os números digitados (%.1f) são iguais.", numero1);
	} 
	else if (numero1 < numero2) {
		printf("O menor número digitado foi %.1f.", numero1);
	}
	else {
		printf("O menor número digitado foi %.1f.", numero2);
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");

	float numero1, numero2;
	
	printf("Digite o primeiro número: ");
	scanf("%f", &numero1);
	printf("Digite o segundo número: ");
	scanf("%f", &numero2);
	
	system("cls");
	
	menorValor(numero1, numero2);
}
