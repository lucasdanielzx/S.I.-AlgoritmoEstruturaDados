/* Crie uma função que receba um valor e informe se ele é positivo ou negativo. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int positivoNegativo (float valor) {
	if (valor >= 0) {
		printf("\nO valor %.1f é positivo.", valor);
	}
	else {
		printf("\nO valor %.1f é negativo.", valor);
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	float valor;
	
	printf("Digite um valor: ");
	scanf("%f", &valor);
	
	positivoNegativo(valor);
}
