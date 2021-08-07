#include <stdio.h>
#include <stdlib.h>
#include "ListaDeck.h"
#include "PilhaJoao.h"

struct elemento {
    struct carta info;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Pilha *criarPilha(){
    Pilha *novo;
    novo = (Pilha*)malloc(sizeof(Pilha));
    if(novo != NULL) *novo = NULL;
    return novo;
}

int inserirPilha(Pilha *pilha,struct carta nova){
    if( pilha == NULL) return 0;
    Elemento *novo;
    novo = (Elemento*)malloc(sizeof(Elemento));
    if( novo == NULL) return 0;
    novo->info = nova;
    novo->prox = *pilha;
    *pilha = novo;
    return 1;
}

int tamanhoPilha(Pilha *pilha){
    if(pilha == NULL) return 0;
    if(*pilha == NULL) return 0;
    int tam = 0;
    Elemento *aux;
    aux = *pilha;
    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

int acessarPilha(Pilha *pilha,struct carta *c){
    if (pilha == NULL) return 0;
    if (*pilha == NULL) return 0;
    *c = (*pilha)->info;
    return 1;
}

int removerPilha(Pilha *pilha){
    if(pilha == NULL) return 0;
    if(*pilha == NULL) return 0;
    Elemento *aux;
    aux = *pilha;
    *pilha = aux->prox;
    free(aux);
    return 1;
}
