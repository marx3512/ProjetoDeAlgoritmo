#include <stdio.h>
#include <stdlib.h>
#include "ListaDeck.h"

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

Lista* criar(){
    Lista *nova;
    nova = (Lista *)malloc(sizeof(Lista));
    if(nova != NULL){
        nova->inicio = NULL;
        nova->fim = NULL;
        nova->qtd = 0;
    }
    return nova;
}

int tamanho(Lista *lista){
    if(lista == NULL) return -1;
    return lista->qtd;
}

int inserir(Lista *lista, struct carta nova){
    if( lista == NULL) return 0;
    Elemento *novo;
    novo = (Elemento *)malloc(sizeof(Elemento));
    novo->info = nova;
    novo->prox = NULL;
    if(lista->fim == NULL) lista->inicio = novo;
    else lista->fim->prox = novo;

    lista->fim = novo;
    lista->qtd++;
    return 1;
}

int removerInicio(Lista *lista){
    if( lista == NULL) return 0;
    if(lista->qtd == 0) return 0;
    Elemento *aux;
    aux = lista->inicio;
    lista->inicio = lista->inicio->prox;
    if(lista->inicio == NULL) lista->fim = NULL;
    lista->qtd--;
    free(aux);
    return 1;
}

int removerFim(Lista *lista){
    if(lista == NULL) return 0;
    if(lista->qtd == 0) return 0;
    else if(lista->qtd == 1){
        Elemento *aux;
        aux = lista->inicio;
        lista->inicio = aux->prox;
        free(aux);
        return 1;
    }
    else{
        Elemento *aux;
        Elemento *ant;
        aux = lista->inicio;
        ant = lista->inicio->prox;
        while(aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = aux->prox;
        free(aux);
        return 1;
    }
}

int acessarIndice(Lista *lista,int pos,struct carta *c){
    if(tamanho(lista) == 0) return 0;
    else if(pos < 0) return 0;
    else{
        int cont = 0;
        Elemento *aux = lista->inicio;
        while(aux != NULL && pos!=cont){
            aux = aux->prox;
            cont++;
        }
        if(aux == NULL) return 0;
        *c = aux->info;
        return 1;
    }
}

int acessarInicio(Lista *lista,struct carta *c){
    if(lista == NULL) return 0;
    if(lista->inicio == NULL) return 0;
    *c = lista->inicio->info;
}
