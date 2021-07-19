#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "ListaDeck.h"

void CriarDeck(int quant){

}

void MostrarDeck(Lista *deck1,Lista *deck2){
    int pos = 0,tamanhoMax = tamanho(deck1) + tamanho(deck2);
    struct carta retorno1,retorno2;
    while(pos < tamanho(deck1) || pos < tamanho(deck2)){
        int cond1 = acessarIndice(deck1,pos,&retorno1);
        int cond2 = acessarIndice(deck2,pos,&retorno2);
        if(cond1 == 1)printf("Deck1: %d || ", retorno1.num);
        if(cond2 == 1)printf("Deck2: %d", retorno2.num);
        printf("\n");
        pos++;
    }
}

void TurnoJoao(Lista *deck1,Lista *deck2,int *vez){
    int acao,quantAcao = 3,turno = 1;
    while(turno <= 3){

        MostrarDeck(deck1,deck2);
        printf("\n");
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

void TurnoGigante(Lista *deck1,Lista *deck2,int *vez){
    int acao,turno = 1;
    while(turno <= 1){

        MostrarDeck(deck1,deck2);
        printf("\n");
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
    int vez = 0,FimDeJogo = 0,contador = 0;
    int *pontVez,*pontFim;
    pontVez = &vez;
    pontFim = &FimDeJogo;

    Lista *deck1,*deck2,*deck3,*deck4,*deck5;
    struct carta c,c1,c2,c3,c4,c5,c6,c7,c8,c9,acessar;
    struct carta c10,c11,c12,c13,c14,c15,c16,c17,c18,c19;
    deck1 = NULL;
    deck1 = criar();
    deck2 = NULL;
    deck2 = criar();

    c.num = 8;
    c1.num = 9;
    c2.num = 6;
    c3.num = 2;
    c4.num = 4;
    c5.num = 1;
    c6.num = 3;
    c7.num = 9;
    c8.num = 7;
    c9.num = 5;
    inserir(deck1,c);
    inserir(deck1,c1);
    inserir(deck1,c2);
    inserir(deck1,c3);
    inserir(deck1,c4);
    inserir(deck1,c5);
    inserir(deck1,c6);
    inserir(deck1,c7);
    inserir(deck1,c8);
    inserir(deck1,c9);

    c10.num = 2;
    c11.num = 3;
    c12.num = 4;
    c13.num = 5;
    c14.num = 3;
    c15.num = 8;
    c16.num = 4;
    c17.num = 2;
    c18.num = 0;
    c19.num = 5;
    inserir(deck1,c10);
    inserir(deck1,c11);
    inserir(deck1,c12);
    inserir(deck1,c13);
    inserir(deck1,c14);
    inserir(deck2,c15);
    inserir(deck2,c16);
    inserir(deck2,c17);
    inserir(deck2,c18);
    inserir(deck2,c19);


    while(FimDeJogo != 1){

        if(vez == 0) TurnoJoao(deck1,deck2,pontVez);
        if(*pontVez == 1) TurnoGigante(deck1,deck2,pontVez);
    }
    return 0;
}
