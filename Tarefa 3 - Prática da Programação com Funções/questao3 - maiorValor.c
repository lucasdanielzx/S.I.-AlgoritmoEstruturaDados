/* Crie uma fun��o em linguagem C que receba 2 n�meros e retorne o maior valor */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int maiorValor (float numero1, float numero2) {
	if (numero1 == numero2) {
		printf("Os n�meros digitados (%.1f) s�o iguais.", numero1);
	} 
	else if (numero1 > numero2) {
		printf("O maior n�mero digitado foi %.1f.", numero1);
	}
	else {
		printf("O maior n�mero digitado foi %.1f.", numero2);
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");

	float numero1, numero2;
	
	printf("Digite o primeiro n�mero: ");
	scanf("%f", &numero1);
	printf("Digite o segundo n�mero: ");
	scanf("%f", &numero2);
	
	system("cls");
	
	maiorValor(numero1, numero2);
}
