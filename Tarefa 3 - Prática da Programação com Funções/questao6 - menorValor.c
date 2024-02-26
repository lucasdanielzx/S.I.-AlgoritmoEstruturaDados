/* Crie uma função em linguagem C que receba 3 números e retorne o menor valor, use a função da questão 4. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int menorValor (float numero1, float numero2, float numero3) {
	if (numero1 == numero2 && numero1 == numero3) {
		printf("Os números digitados (%.1f) são iguais.", numero1);
	} 
	else if (numero1 < numero2 && numero1 < numero3) {
		printf("O menor número digitado foi %.1f.", numero1);
	}
	else if (numero2 < numero1 && numero2 < numero3){
		printf("O menor número digitado foi %.1f.", numero2);
	}
	else {
		printf("O menor número digitado foi %.1f.", numero3);
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");

	float numero1, numero2, numero3;
	
	printf("Digite o primeiro número: ");
	scanf("%f", &numero1);
	printf("Digite o segundo número: ");
	scanf("%f", &numero2);
	printf("Digite o terceiro número: ");
	scanf("%f", &numero3);
	
	system("cls");
	
	menorValor(numero1, numero2, numero3);
}
