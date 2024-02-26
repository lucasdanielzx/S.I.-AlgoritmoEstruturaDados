#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

float maiorNota(float nota1, float nota2, float nota3) {
    float maior;
    if(nota1 > nota2 && nota1 > nota3) {
        maior = nota1;
    } 
    else if (nota2 > nota1 && nota2 > nota3) {
        maior = nota2;
    }
    else {
        maior = nota3;
    }
    return maior;
}

float menorNota(float nota1, float nota2, float nota3) {
    float menor;
    if(nota1 < nota2 && nota1 < nota3) {
        menor = nota1;
    } 
    else if (nota2 < nota1 && nota2 < nota3) {
        menor = nota2;
    }
    else {
        menor = nota3;
    }
    return menor;
}

float calcularMedia(float nota1, float nota2, float nota3) {
    float mediaGeral, media, maior, segundaMaior;
    
    mediaGeral = (nota1 + nota2 + nota3) / 3;
    printf("Média com as três notas: %.1f\n", mediaGeral);
    
    maior = maiorNota(nota1, nota2, nota3);
    
    if(nota1 < nota2 && nota1 > nota3) {
		segundaMaior = nota1;
	} 
	else if (nota2 < nota1 && nota2 > nota3) {
		segundaMaior = nota2;
	}
	else {
		segundaMaior = nota3;
	}
    
    media = (maior + segundaMaior) / 2;
    
    return media;
}

int main () {
    setlocale(LC_ALL, "Portuguese");
    float nota1, nota2, nota3, maior, menor, media;
    printf("Nota 1: ");
    scanf("%f", &nota1);
    printf("Nota 2: ");
    scanf("%f", &nota2);
    printf("Nota 3: ");
    scanf("%f", &nota3);
    
    media = calcularMedia(nota1, nota2, nota3);
    maior = maiorNota(nota1, nota2, nota3);
    menor = menorNota(nota1, nota2, nota3);
    
    printf("Média com as 2 maiores notas: %.1f\n", media);
    printf("Maior nota: %.1f\n", maior);
    printf("Menor nota: %.1f", menor);
    return 0;
}

