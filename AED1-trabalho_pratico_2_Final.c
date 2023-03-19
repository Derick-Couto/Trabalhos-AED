#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minOperantions(char **logs, int logsSize);

int minOperations(char **logs, int logsSize) {
    int minOperacoes = 0;
    for (int i = 0; i < logsSize; i++) {
        if ( strstr ( logs [ i ], "x/")) {
            minOperacoes += 1;
            continue;
        } else {}
        if ( strstr ( logs [ i ], "../" ) ) {
            if ( minOperacoes == 0 ) {
                continue;
            } else {
                minOperacoes -= 1;
                continue;
            }
        } else {}
        if ( strstr ( logs [ i ], "./") ) {
            continue;
        } else {
            minOperacoes += 1;
        }
    }
    printf("Use esta operação de alteração de pasta ../ %d vezes e volte para a pasta principal.",
                                                                                     minOperacoes);
}

typedef struct pasta {
    char nome [11];
    struct pasta *anterior;
} pasta;

int main() {
    char *logs [104] = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    //char *logs[104]={"d1/", "d2/", "x/", "./", "d3/", "../", "d31/"};
    //char *logs[104]={"d1/", "../", "../", "../"};
    pasta *x = (pasta *) malloc( sizeof( pasta ) );
    pasta *ponteiro;
    int len;
    ponteiro = NULL;
    ponteiro->anterior == NULL;
    
    for (int i = 0; logs[i] != NULL; i++) {
        if (logs[i] == "../") //pop
        {
            if (ponteiro == NULL) {
                continue;
            } else {
                pasta *aux = ponteiro;
                ponteiro = ponteiro->anterior;
                free(aux);
                continue;
            }
        } else {}
        if (logs[i] == "./") // não fazer nada
        {
            continue;
        } else {}
        if (logs[i] == "x/") //ir para pasta x
        {
            pasta *aux = ponteiro;
            x->anterior = aux;
            strcpy(x->nome, logs[i]);
            ponteiro = x;
        } else {                         //push
            if (ponteiro == NULL) {
                pasta *nova_pasta = (pasta *) malloc(sizeof(pasta));
                nova_pasta->anterior = NULL;
                strcpy(nova_pasta->nome, logs[i]);
                ponteiro = nova_pasta;
            } else {
                pasta *nova_pasta = (pasta *) malloc(sizeof(pasta));
                pasta *aux = ponteiro;
                ponteiro = nova_pasta;
                ponteiro->anterior = aux;
                strcpy(nova_pasta->nome, logs[i]);
            }
        }
    }
    int cont = 0;
    pasta *aux = ponteiro;

    while (ponteiro != NULL) 
    {
        printf("%s\n", ponteiro->nome);
        aux = ponteiro;
        ponteiro = ponteiro->anterior;
        free(aux);
        cont = cont + 1;
    }

    printf("Atraves da pilha o resultado eh %d\n", cont);

    for (int i = 0; logs[i] != NULL; i++)
    {
    len+=1;
    }

minOperations( logs, len);
}