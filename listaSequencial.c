#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 50

struct lista {
    int v[MAX];
    int n;
};

void criar(struct lista *L) {
    L->n = 0;
}

int listaVazia(struct lista L) {
    return (L.n == 0);
}

int cheia(struct lista L) {
    return (L.n == MAX);
}

int tamanho(struct lista L) {
    return (L.n);
}

int elemento(struct lista L, int pos, int *dado) {
    if ((pos > L.n) || (pos < 0)) {
        return 0;
    }
    
    *dado = L.v[pos-1]; 
    return 1; 
}

int posicao(struct lista L, int dado) {
    int i;
    
    for (i = 0; i < L.n; i++) {
        if (L.v[i] == dado) {
            return (i+1);
        }
    }
    
    return -1;
}

int inserir(struct lista *L, int pos, int dado) {
    int i;
    
    if ((L->n == MAX) || (pos < 1) || (pos > L->n + 1)) {
        return 0;
    }
    
    for (i = L->n; i >= pos; i--) {
        L->v[i] = L->v[i-1];
    }
    
    L->v[pos-1] = dado;
    (L->n)++;
    return 1;
}

int remover(struct lista *L, int pos, int *dado) {
    int i;
    
    if((pos > L->n) || (pos < 1)) {
        return 0;
    }
    
    *dado = L->v[pos-1];
    
    for(i = pos; i < L->n; i++) {
        L->v[i-1] = L->v[i];
    }
    
    (L->n)--;
    return 1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int encerrar = 0;
    int opcao;
    int pos;
    int dado;
    
    struct lista L;
    criar(&L);
    
    while (encerrar == 0) {
        
        printf("\n\nEDITOR DE LISTAS \n1 – VERIFICAR SE A LISTA ESTÁ VAZIA; \n2 – VERIFICAR SE A LISTA ESTÁ CHEIA; \n3 – INFORMAR O TAMANHO ATUAL DA LISTA; \n4 – INSERIR UM ELEMENTO EM UMA POSIÇÃO INFORMADA; \n5 – EXIBIR A LISTA COMPLETA; \n6 – ENCONTRAR O ELEMENTO DE UMA DETERMINADA POSIÇÃO DA LISTA; \n7 – ENCONTRAR A POSIÇÃO DE UM DETERMINADO ELEMENTO DA LISTA; \n8 – REMOVER UM ELEMENTO DE UMA DETERMINADA POSIÇÃO DA LISTA; \n0 – ENCERRAR EDITOR DE LISTAS.");
        printf("\nDigite a opção: ");
        scanf("%d", &opcao);
        system("cls");
        
        switch (opcao) {
            case 0:
                encerrar = 1;
                break;
                
            case 1:
                if (listaVazia(L) == 1) {
                    printf("\nA lista está vazia!");
                }
                else {
                    printf("\nA lista não está vazia!");
                }
                break;
                
            case 2:
                if (cheia(L) == 1) {
                    printf("\nA lista está cheia!");
                }
                else {
                    printf("\nA lista não está cheia!");
                }
                break;
                
            case 3:
                printf("\nTamanho da lista: %d", tamanho(L));
                break;
                    
            case 4:
                printf("\nDigite a posição que deseja inserir: ");
                scanf("%d", &pos);
                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &dado);
                
                inserir(&L, pos, dado);
                break;
                    
            case 5:
                printf("\nLista completa: ");
                int i = 0;
                for (i = 0; i < L.n; i++) {
                    printf("%d ", L.v[i]);
                }
                break;
                        
            case 6:
                printf("\nDigite a posição que deseja obter: ");
                scanf("%d", &pos);
                
                if (elemento(L, pos, &dado)) {
                    printf("\nElemento da posição informada: %d", dado);
                } else {
                    printf("\nPosição inválida!");
                }
                break;
            
            case 7:
                printf("\nDigite o elemento: ");
                scanf("%d", &dado);
                
                pos = posicao(L, dado);
                
                if (pos == -1) {
                    printf("\nElemento não encontrado!");
                }
                else {
                    printf("\nPosição do elemento: %d", pos);
                }
                
                break;
                        
            case 8:
                printf("\nDigite a posição que deseja remover: ");
                scanf("%d", &pos);
                
                if (remover(&L, pos, &dado)) {
                    printf("\nElemento removido: %d", dado);
                } else {
                    printf("\nPosição inválida!");
                }
                break;
        }
    }
    return 0;
}
