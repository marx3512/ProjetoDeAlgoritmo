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
