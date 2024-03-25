#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef int telem; /* definindo o tipo de elemento*/

struct no {
    telem dado; /* campo da informa��o */
    struct no *prox; /* campo do ponteiro para o pr�ximo n� */
};

typedef struct no tno; /* definindo um novo tipo chamado tno */
typedef tno *lista;

void criar(lista *L) {
    *L = NULL;
}

int listaVazia(lista L) {
    return (L == NULL);
}

int tamanho(lista L) {
    lista p = L;
    int n = 0;
    while (p != NULL) {
        p = p->prox;
        n++;
    }
    return n;
}

int elemento(lista L, int pos, telem *elem) {
    /* O par�metro elem ir� receber o elemento encontrado */
    /* Retorna 0 se a posi��o for inv�lida. Caso contr�rio, retorna 1 */

    lista p = L;
    int n = 1;

    if (L == NULL || pos <= 0) return 0; /* erro: lista vazia ou posi��o inv�lida */

    while (p != NULL && n < pos) {
        p = p->prox;
        n++;
    }

    if (p == NULL) return 0; /* erro: posi��o inv�lida */

    *elem = p->dado;
    return 1;
}

int posicao(lista L, telem valor) {
    /* Retorna a posi��o do elemento ou 0 caso n�o seja encontrado */
    lista p = L;
    int n = 1;

    while (p != NULL) {
        if (p->dado == valor) return n;
        p = p->prox;
        n++;
    }

    return 0;
}

int inserir(lista *L, int pos, telem valor) {
    /* Retorna 0 se a posi��o for inv�lida ou se a lista estiver cheia */
    /* Caso contr�rio, retorna 1 */
    lista novo, p;
    int n = 1;

    if (pos < 1) return 0; /* erro: posi��o inv�lida */

    novo = (lista)malloc(sizeof(tno));
    if (novo == NULL) return 0; /* erro: mem�ria insuficiente */

    novo->dado = valor;

    if (pos == 1) {
        novo->prox = *L;
        *L = novo;
        return 1;
    }

    p = *L;
    while (p != NULL && n < pos - 1) {
        p = p->prox;
        n++;
    }

    if (p == NULL) return 0; /* erro: posi��o inv�lida */

    novo->prox = p->prox;
    p->prox = novo;

    return 1;
}

int remover(lista *L, int pos, telem *elem) {
    /* O par�metro elem ir� receber o elemento encontrado */
    /* Retorna 0 se a posi��o for inv�lida. Caso contr�rio, retorna 1 */
    lista p, ant;
    int n = 1;

    if (listaVazia(*L) || pos < 1) return 0; /* erro: lista vazia ou posi��o inv�lida */

    p = *L;

    if (pos == 1) {
        *L = p->prox;
        *elem = p->dado;
        free(p);
        return 1;
    }

    while (p != NULL && n < pos) {
        ant = p;
        p = p->prox;
        n++;
    }

    if (p == NULL) return 0; /* erro: posi��o inv�lida */

    ant->prox = p->prox;
    *elem = p->dado;
    free(p);
    return 1;
}

void exibirLista(lista L) {
    lista p = L;
    while (p != NULL) {
        printf("%d ", p->dado);
        p = p->prox;
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int encerrar = 0;
    int opcao;
    int pos;
    int dado;

    lista L;
    criar(&L);

    while (!encerrar) {

        printf("\n\nEDITOR DE LISTAS \n1 � VERIFICAR SE A LISTA EST� VAZIA; \n2 � INFORMAR O TAMANHO ATUAL DA LISTA; \n3 � INSERIR UM ELEMENTO EM UMA POSI��O INFORMADA; \n4 � EXIBIR A LISTA COMPLETA; \n5 � ENCONTRAR O ELEMENTO DE UMA DETERMINADA POSI��O DA LISTA; \n6 � ENCONTRAR A POSI��O DE UM DETERMINADO ELEMENTO DA LISTA; \n7 � REMOVER UM ELEMENTO DE UMA DETERMINADA POSI��O DA LISTA; \n0 � ENCERRAR EDITOR DE LISTAS.\n");
        printf("Digite a op��o: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 0:
                encerrar = 1;
                break;

            case 1:
                if (listaVazia(L) == 1) {
                    printf("\nA lista est� vazia!\n");
                } else {
                    printf("\nA lista n�o est� vazia!\n");
                }
                break;

            case 2:
                printf("\nTamanho da lista: %d\n", tamanho(L));
                break;

            case 3:
                printf("\nDigite a posi��o que deseja inserir: ");
                scanf("%d", &pos);
                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &dado);

                if (inserir(&L, pos, dado)) {
                    printf("\nElemento inserido com sucesso!\n");
                } else {
                    printf("\nFalha ao inserir elemento!\n");
                }
                break;

            case 4:
                printf("\nLista completa: ");
                exibirLista(L);
                break;

            case 5:
                printf("\nDigite a posi��o que deseja obter: ");
                scanf("%d", &pos);

                if (elemento(L, pos, &dado)) {
                    printf("\nElemento da posi��o informada: %d\n", dado);
                } else {
                    printf("\nPosi��o inv�lida!\n");
                }
                break;

            case 6:
                printf("\nDigite o elemento: ");
                scanf("%d", &dado);

                pos = posicao(L, dado);

                if (pos == 0) {
                    printf("\nElemento n�o encontrado!\n");
                } else {
                    printf("\nPosi��o do elemento: %d\n", pos);
                }
                break;

            case 7:
                printf("\nDigite a posi��o que deseja remover: ");
                scanf("%d", &pos);

                if (remover(&L, pos, &dado)) {
                    printf("\nElemento removido: %d\n", dado);
                } else {
                    printf("\nPosi��o inv�lida!\n");
                }
                break;

            default:
                printf("\nOp��o inv�lida!\n");
        }
    }
    
    // Liberar mem�ria ocupada pela lista
    lista p = L;
    while (p != NULL) {
        lista temp = p;
        p = p->prox;
        free(temp);
    }
    return 0;
}


