/* Fa�a uma fun��o que receba como argumento os valores dos lados de um tri�ngulo, a fun��o dever� 
retornar 0 se tri�ngulo for equil�tero, 1 se for is�sceles ou 2 se for escaleno.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

float cond_existencia_triangulo (float l1, float l2, float l3) {
	if ((l1 + l2) > l3 && (l1 + l3) > l2 && (l2 + l3) > l1) {
		return 1;
	}
	else {
		return 0;
	}
}

int triangulo (float l1, float l2, float l3) {
	if (cond_existencia_triangulo(l1, l2, l3) == 1) {
		if (l1 == l2 && l1 == l3 && l2 == l3) {
			return 0;
		}
		else if (l1 != l2 && l1 != l3 && l2 != l3) {
			return 2;
		}
		else {
			return 1;
		}
	}
	else {
		printf("Os valores informados n�o formam um tri�ngulo.");
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	float l1, l2, l3;
	int tipoTriangulo;
	
	printf("Informe o valor do primeiro lado: ");
	scanf("%f", &l1);
	printf("Informe o valor do segundo lado: ");
	scanf("%f", &l2);
	printf("Informe o valor do terceiro lado: ");
	scanf("%f", &l3);
	
	system("cls");
	
	tipoTriangulo = triangulo(l1, l2, l3);
	
	if(tipoTriangulo == 0) {
		printf("O tri�ngulo � equil�tero");
	}
	else if (tipoTriangulo == 1) {
		printf("O tri�ngulo � isosceles");
	}
	else {
		printf("O tri�ngulo � escaleno");
	}
	
	return 0;
}
