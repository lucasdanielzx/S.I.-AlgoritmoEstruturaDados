/* Crie uma fun��o que receba um valor e informe se ele � positivo ou negativo. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int positivoNegativo (float valor) {
	if (valor >= 0) {
		printf("\nO valor %.1f � positivo.", valor);
	}
	else {
		printf("\nO valor %.1f � negativo.", valor);
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	float valor;
	
	printf("Digite um valor: ");
	scanf("%f", &valor);
	
	positivoNegativo(valor);
}
