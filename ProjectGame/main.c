#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "FilaDecks.h"

void TurnoJoao(int *vez){
    int acao,quantAcao = 3,turno = 1;
    while(turno <= 3){
        printf("Vez de João, você tem %d. Escolha uma opção: \n", quantAcao);
        printf("1: Mover entre colunas( cartas da frente) \n");
        printf("2: Mover de trás para frente( mesma coluna ) \n");
        printf("3: Pegar de trás ( objetivo ) \n");
        printf("4: Pegar de frente ( objetivo ) \n");
        printf("-> ");
        scanf("%d", &acao);
        if(acao > 4 || acao < 1){
            printf("Escolha uma opção valida... \n");
            system("pause");
        }
        else{
            turno++;
            quantAcao--;
        }

        system("cls");
    }
    *vez = 1;
}

void TurnoGigante(int *vez){
    int acao,turno = 1;
    while(turno <= 1){
        printf("Vez do Gigante, você tem 1 ação. Escolha uma opção... \n");
        printf("1: Destruir qualquer Carta de Feijão \n");
        printf("2: Mover entre colunas ( 4 cartas de uma vez ) \n");
        printf("3: Mover entre colunas duas vezes ( Cartas da frente )\n");
        printf("-> ");
        scanf("%d", &acao);
        if(acao > 3){
            printf("Escolha uma opção valida... \n");
            system("pause");
        }
        else turno++;

        system("cls");
    }
    *vez = 0;
}

int main(){
    setlocale(LC_ALL,"");
    int vez = 0,FimDeJogo = 0;
    int *pontVez,*pontFim;
    pontVez = &vez;
    pontFim = &FimDeJogo;

    Fila *deck;
    struct carta c,c1;
    deck = NULL;
    deck = criar();

    c.num = 8;
    c1.num = 10;
    inserir(deck,c);
    inserir(deck,c1);
    int teste = removerFim(deck);
    printf("Teste: %d", teste);
    /*while(FimDeJogo != 1){
        if(vez == 0) TurnoJoao(pontVez);
        if(*pontVez == 1) TurnoGigante(pontVez);
    }*/
    return 0;
}
