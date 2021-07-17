#include <stdio.h>
#include <stdlib.h>
#include "FilaDecks.h"

struct elemento{
    struct carta info;
    struct elemento *prox;
};

struct noDescritor{
    struct elemento *inicio;
    struct elemento *fim;
    int qtd;
};

typedef struct elemento Elemento;

Fila* criar(){
    Fila *nova;
    nova = (Fila *)malloc(sizeof(Fila));
    if(nova != NULL){
        nova->inicio = NULL;
        nova->fim = NULL;
        nova->qtd = 0;
    }
    return nova;
}

int tamanho(Fila *fila){
    if(fila == NULL) return -1;
    return fila->qtd;
}

int inserir(Fila *fila, struct carta nova){
    if( fila == NULL) return 0;
    Elemento *novo;
    novo = (Elemento *)malloc(sizeof(Elemento));
    novo->info = nova;
    novo->prox = NULL;
    if(fila->fim == NULL) fila->inicio = novo;
    else fila->fim->prox = novo;

    fila->fim = novo;
    fila->qtd++;
    return 1;
}

int removerInicio(Fila *fila){
    if( fila == NULL) return 0;
    if(fila->qtd == 0) return 0;
    Elemento *aux;
    aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if(fila->inicio == NULL) fila->fim = NULL;
    fila->qtd--;
    free(aux);
    return 1;
}

int removerFim(Fila *fila){
    if(fila == NULL) return 0;
    if(fila->qtd == 0) return 0;
    else if(fila->qtd == 1){
        Elemento *aux;
        aux = fila->inicio;
        fila->inicio = aux->prox;
        free(aux);
        return 1;
    }
    else{
        Elemento *aux;
        Elemento *ant;
        aux = fila->inicio;
        ant = fila->inicio->prox;
        while(aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = aux->prox;
        free(aux);
        return 1;
    }

}
