#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "ListaDeck.h"

struct carta ChecarCartaCriada(int num){
    struct carta nova;
    if(num >= 1 && num <= 9){
        nova.nome[10] = "F *";
        nova.num = num;
        return nova;
    }

};

void CriarDeck(Lista *deck1, Lista *deck2, Lista *deck3, Lista *deck4){
    struct carta c;
    int i;
    for (i = 0; i < 10; i++){
        c.num = rand()%12;
        c = ChecarCartaCriada(c.num);
        inserir(deck1,c);
        c.num = rand()%12;
        c = ChecarCartaCriada(c.num);
        inserir(deck2,c);
        c.num = rand()%12;
        c = ChecarCartaCriada(c.num);
        inserir(deck3,c);
        c.num = rand()%12;
        c = ChecarCartaCriada(c.num);
        inserir(deck4,c);
    }
}

void MostrarDeck(Lista *deck1, Lista *deck2, Lista *deck3, Lista *deck4){
    int pos = 0;
    struct carta pegarCarta;
    while(pos < tamanho(deck1) || pos < tamanho(deck2)){
        int cond1 = acessarIndice(deck1,pos,&pegarCarta);
        if (cond1 == 1) printf("|   %s %d   |  ", pegarCarta.nome,pegarCarta.num);
        int cond2 = acessarIndice(deck2,pos,&pegarCarta);
        if (cond2 == 1) printf("|   %s %d   |  ", pegarCarta.nome,pegarCarta.num);
        int cond3 = acessarIndice(deck3,pos,&pegarCarta);
        if (cond3 == 1) printf("|   %s %d   |  ", pegarCarta.nome,pegarCarta.num);
        int cond4 = acessarIndice(deck4,pos,&pegarCarta);
        if (cond4 == 1) printf("|   %s %d   |  \n", pegarCarta.nome,pegarCarta.num);
        pos++;
    }
}

void TurnoJoao(Lista *deck1,Lista *deck2,Lista *deck3,Lista *deck4,int *vez){
    int acao,quantAcao = 3,turno = 1;
    while(turno <= 3){
        MostrarDeck(deck1,deck2,deck3,deck4);

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

void TurnoGigante(Lista *deck1,Lista *deck2,Lista *deck3,Lista *deck4,int *vez){
    int acao,turno = 1;
    while(turno <= 1){
        MostrarDeck(deck1,deck2,deck3,deck4);

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
    srand(time(NULL));
    int vez = 0,FimDeJogo = 0;
    int *pontVez,*pontFim;
    pontVez = &vez;
    pontFim = &FimDeJogo;

    Lista *deck1,*deck2,*deck3,*deck4;
    struct carta c,acessar;
    c.nome[10] = "Teste";
    c.num = 50;
    deck1 = NULL;
    deck1 = criar();
    deck2 = NULL;
    deck2 = criar();
    deck3 = NULL;
    deck3 = criar();
    deck4 = NULL;
    deck4 = criar();

    inserir(deck1,c);
    acessarIndice(deck1,0,&acessar);
    printf("Nome: %s \n", acessar.nome);
    printf("Numero: %d \n", acessar.num);
    /*CriarDeck(deck1, deck2, deck3, deck4);

    while(FimDeJogo != 1){
        if(vez == 0) TurnoJoao(deck1,deck2,deck3,deck4,pontVez);
        if(*pontVez == 1) TurnoGigante(deck1,deck2,deck3,deck4,pontVez);
    }*/

    return 0;
}
