/* Fa�a um programa que tenha uma fun��o que receba como par�metros um valor para base e um 
para o expoente e retorne o resultado (base elevada ao expoente). Fa�a tamb�m uma fun��o para 
mostrar o resultado na tela. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <math.h>

int calcular (int base, int expoente) {
	return pow(base, expoente);
}

int mostraResultado(int resultado) {
	printf("\nO resultado � %d", resultado);
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
