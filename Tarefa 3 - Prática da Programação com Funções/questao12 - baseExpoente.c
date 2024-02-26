/* Faça um programa que tenha uma função que receba como parâmetros um valor para base e um 
para o expoente e retorne o resultado (base elevada ao expoente). Faça também uma função para 
mostrar o resultado na tela. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <math.h>

int calcular (int base, int expoente) {
	return pow(base, expoente);
}

int mostraResultado(int resultado) {
	printf("\nO resultado é %d", resultado);
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int base, expoente, resultado;
	
	printf("Digite o valor da base: ");
	scanf("%d", &base);
	printf("Digite o valor do expoente: ");
	scanf("%d", &expoente);
	
	mostraResultado(calcular(base, expoente));
}
