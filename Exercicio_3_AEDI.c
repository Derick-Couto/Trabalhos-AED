#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *direita;
    struct no *esquerda;
} No;

No* inserir_novo_no(int conteudo) {
    No* novo = (No*)malloc(sizeof(No));
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->valor = conteudo;
    return novo;
}

No* inserir_no(No *raiz, int conteudo) {    
    No* nodo = inserir_novo_no(conteudo);    
    if (raiz == NULL) {
        return nodo;
    } else {
        if (conteudo < raiz->valor) {
            raiz->esquerda = inserir_no(raiz->esquerda, conteudo);
        } else if (conteudo > raiz->valor) {
            raiz->direita = inserir_no(raiz->direita, conteudo);
        }
        return raiz;
    }
}

No* elemento_de_troca(No* raiz) {
    No* aux = raiz;
    while (raiz->direita != NULL) {
        aux = raiz->direita;
    }
    return aux;
}

void imprimir(No* raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d ",  raiz->valor);
        imprimir(raiz->direita);
    }
}

void separar_folhas(No *raiz, int *vetor, int *cont) {   
    if (raiz != NULL) {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            vetor[(*cont)] = raiz->valor;
            *cont += 1;
            return;
        } else {}
        separar_folhas(raiz->esquerda, vetor, cont);
        separar_folhas(raiz->direita, vetor, cont);
    } else {
        return;
    }
}

int leafSimilar(No* raiz1, No* raiz2) {
    int vetor1[11] = {0}, vetor2[11] = {0}, cont1 = 0, cont2 = 0;
    separar_folhas(raiz1, vetor1, &cont1);
    separar_folhas(raiz2, vetor2, &cont2);

    for (int i = 0; i < 10; i++) {
        if (vetor1[i] != vetor2[i]) {
            return 0;
        }
    }
    return 1;
}

void sair(No* raiz) {
    if (raiz != NULL) {
        sair(raiz->esquerda);
        sair(raiz->direita);
        free (raiz);
    }
}

int main() {
    No* raiz = NULL;
    No* raiz2 = NULL;
    int numero_novo = 0, opcao = 0;

    
    raiz = inserir_no(raiz,3);
    raiz = inserir_no(raiz,5);
    raiz = inserir_no(raiz,1);
    raiz = inserir_no(raiz,6);
    raiz = inserir_no(raiz,2);
    raiz = inserir_no(raiz,9);
    raiz = inserir_no(raiz,8);
    raiz = inserir_no(raiz,7);
    raiz = inserir_no(raiz,4);

    raiz2 = inserir_no(raiz2,3);
    raiz2 = inserir_no(raiz2,5);
    raiz2 = inserir_no(raiz2, 1);
    raiz2 = inserir_no(raiz2, 6);
    raiz2 = inserir_no(raiz2, 7);
    raiz2 = inserir_no(raiz2, 4);
    raiz2 = inserir_no(raiz2, 2);
    raiz2 = inserir_no(raiz2, 9);
    raiz2 = inserir_no(raiz2, 8);
    
    /*
    raiz = inserir_no(raiz, 10);
    raiz = inserir_no(raiz, 5);
    raiz = inserir_no(raiz, 20);
    raiz = inserir_no(raiz, 3);
    raiz = inserir_no(raiz, 7);
    raiz = inserir_no(raiz, 29);
    raiz = inserir_no(raiz, 24);
    raiz = inserir_no(raiz, 32);

    raiz2 = inserir_no(raiz, 15);
    raiz2 = inserir_no(raiz, 27);
    raiz2 = inserir_no(raiz, 24);
    raiz2 = inserir_no(raiz, 6);
    raiz2 = inserir_no(raiz, 31);
    raiz2 = inserir_no(raiz, 32);
    raiz2 = inserir_no(raiz, 7);
    raiz2 = inserir_no(raiz, 3);
    */
    /*
    raiz = inserir_no(raiz, 3);
    raiz = inserir_no(raiz, 1);
    raiz = inserir_no(raiz, 4);
    raiz = inserir_no(raiz, 2);

    raiz2 = inserir_no(raiz2, 3);
    raiz2 = inserir_no(raiz2, 1);
    raiz2 = inserir_no(raiz2, 7);
    raiz2 = inserir_no(raiz2, 4);
    */
while (opcao < 10)
{
    printf("\n1-InserirArv1\n2-imprimir\n3-InserirArv2\n4-comparar\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        printf("\nQue numero quer inserir:");
        scanf("%d", &numero_novo);
        raiz = inserir_no(raiz, numero_novo);
        break;
    case 2:
        printf("Qual arvore deseja imprimir:");
        scanf("%d", &numero_novo);
        if (numero_novo == 1)
        {
            imprimir(raiz);
        }
        else imprimir(raiz2);
        break;
    case 3:
        printf("\nQue numero quer inserir:");
        scanf("%d", &numero_novo);
        raiz2 = inserir_no(raiz2, numero_novo);
        break;
    case 4:
        numero_novo = leafSimilar(raiz, raiz2);
        if (numero_novo == 0)
            printf("As arvores sao diferentes");
        else printf("As arvores tem folhas similares");
        break;
    default:
    sair(raiz);
    sair(raiz2);
        break;
    }
}
}