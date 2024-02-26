/* Crie uma fun��o que converta graus de Celsius para Farenheit e Kelvin. Primeiro o usu�rio deve 
informar a temperatura em Celsius. As f�rmulas de convers�o s�o: K= C + 273 e F= (9.C/5) + 32. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int conversor(float grausCelsius) {
	float k, f;
	
	k = grausCelsius + 273;
	f = (9 * grausCelsius/5) + 32;
	
	printf("\nFarenheit: %.2f", f);
	printf("\nKelvin: %.2f", k);
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	float grausCelsius;
	
	printf("Digite a temperatura em graus celsius: ");
	scanf("%f", &grausCelsius);
	
	conversor(grausCelsius);
}
