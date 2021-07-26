#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "ListaDeck.h"
#include "PilhaJoao.h"

struct carta ChecarCartaCriada(int num,int *Feijao,int *Ganso,int *Ovo,int *Harpa,int *Fii,int *Foo,int *Fuu,int *Faa){
    int cond = 0,numeroGerado = num;
    struct carta nova;
    while(cond != 1){
        if(numeroGerado >= 1 && numeroGerado <= 9 && *(Feijao) <= 35){
            strcpy(nova.nome,"F *");
            nova.num = numeroGerado;
            *Feijao += 1;
            cond = 1;
            return nova;
        }
        if(numeroGerado == 0 && *(Fii) <= 1){
            strcpy(nova.nome,"FII");
            nova.num = numeroGerado;
            *Fii += 1;
            cond = 1;
            return nova;
        }
        if(numeroGerado == 10 && *(Faa) <= 1){
            strcpy(nova.nome,"FAA");
            nova.num = numeroGerado;
            *Faa += 1;
            cond = 1;
            return nova;
        }
        if(numeroGerado == 11 && *(Foo) <= 1){
            strcpy(nova.nome,"FOO");
            nova.num = numeroGerado;
            *Foo += 1;
            cond = 1;
            return nova;
        }
        if(numeroGerado == 12 && *(Fuu) <= 1){
            strcpy(nova.nome,"FUU");
            nova.num = numeroGerado;
            *Fuu += 1;
            cond = 1;
            return nova;
        }
        if(numeroGerado == 13 && *(Ganso) <= 1){
            strcpy(nova.nome,"Ganso");
            nova.num = numeroGerado;
            *Ganso += 1;
            cond = 1;
            return nova;
        }
        if(numeroGerado == 14 && *(Harpa) <= 1){
            strcpy(nova.nome,"Harpa");
            nova.num = numeroGerado;
            *Harpa += 1;
            cond = 1;
            return nova;
        }
        if(numeroGerado == 15 && *(Ovo) <= 1){
            strcpy(nova.nome,"Ovo");
            nova.num = numeroGerado;
            *Ovo += 1;
            cond = 1;
            return nova;
        }
        numeroGerado = rand()%16;
    }

}

void CriarDeck(Lista *decks[]){
    int QuantFeijao = 0,QuantGanso = 0,QuantOvo = 0,QuantHarpa = 0;
    int QuantFii = 0, QuantFaa = 0, QuantFoo = 0, QuantFuu = 0;
    int *pontFei = &QuantFeijao;
    int *pontGan = &QuantGanso;
    int *pontOvo = &QuantOvo;
    int *pontHarp = &QuantHarpa;
    int *pontFii = &QuantFii;
    int *pontFaa = &QuantFaa;
    int *pontFoo = &QuantFoo;
    int *pontFuu = &QuantFuu;
    struct carta c;
    int i,y;
    for (i = 0; i < 10; i++){
        for(y = 0; y < 5; y++){
            c.num = rand()%16;
            c = ChecarCartaCriada(c.num,pontFei,pontGan,pontOvo,pontHarp,pontFii,pontFoo,pontFuu,pontFaa);
            inserir(decks[y],c);
        }
    }
}

void MostrarDeckPilha(Lista *decks[],Pilha *pilhaJ){

    int pos = 0;
    struct carta pegarCarta;
    printf("      A              B              C              D              E \n");
    while(pos < tamanho(decks[0]) || pos < tamanho(decks[1]) || pos < tamanho(decks[2])|| pos < tamanho(decks[3])|| pos < tamanho(decks[4])){
        int cond1 = acessarIndice(decks[0],pos,&pegarCarta);
        if (cond1 == 1) MostrarCard(pegarCarta);
        else if(cond1 == 0) printf("               ");
        int cond2 = acessarIndice(decks[1],pos,&pegarCarta);
        if (cond2 == 1) MostrarCard(pegarCarta);
        else if(cond2 == 0) printf("               ");
        int cond3 = acessarIndice(decks[2],pos,&pegarCarta);
        if (cond3 == 1) MostrarCard(pegarCarta);
        else if(cond3 == 0) printf("               ");
        int cond4 = acessarIndice(decks[3],pos,&pegarCarta);
        if (cond4 == 1) MostrarCard(pegarCarta);
        else if(cond4 == 0) printf("               ");
        int cond5 = acessarIndice(decks[4],pos,&pegarCarta);
        if (cond5 == 1) MostrarCard(pegarCarta);
        else if(cond5 == 0) printf("               ");
        MostrarPilhaJoao(pilhaJ,pos);
        printf("\n");
        pos++;
    }
}

void MostrarCard(struct carta card){
    if(card.num == 0  || card.num == 10 || card.num == 11 || card.num == 12 || card.num == 15) printf("|   %s     |  ", card.nome);
    else if(card.num == 13 || card.num == 14) printf("|   %s   |  ", card.nome);
    else if(card.num >= 1 && card.num <= 9) printf("|   %s %d   |  ", card.nome,card.num);
}

void MostrarPilhaJoao(Pilha *pilhaJoao,int linha){
    struct carta pegarPilha;
    int Ganso,Harpa,Ovo;
    int condi = acessarPilha(pilhaJoao,&pegarPilha);
    if(condi == 0 && linha == 0) printf("    Topo   [ ] ");
    else if(condi != 0 && linha == 0) printf("    Topo   [%d] ", pegarPilha.num);
    else if(linha == 1) printf("    Altura [%d] ", tamanhoPilha(pilhaJoao));
    else if(linha == 2) printf("    Ganso  [%d] ", Ganso);
    else if(linha == 3) printf("    Ovo    [%d] ", Ovo);
    else if(linha == 4) printf("    Harpa  [%d] ", Harpa);
}

int ChecarListaEscolhida(char coluna){
    if(coluna == 'A') return 0;
    else if(coluna == 'B') return 1;
    else if(coluna == 'C') return 2;
    else if(coluna == 'D') return 3;
    else if(coluna == 'E') return 4;
    return 10;
}

void ChecarAcao(Lista *decks[],int acao,int *vez){
    char coluna1,coluna2;
    struct carta cartaPegada;
    if(*vez == 0){
        if(acao == 1){
            printf("Escolha uma coluna: ");
            scanf(" %c", &coluna1);
            printf("Coluna: %d", ChecarListaEscolhida(coluna1));
            printf("\n");
            printf("Escolha outra coluna: ");
            scanf(" %c", &coluna2);
            /*acessarFim(decks[ChecarListaEscolhida(coluna1)],&cartaPegada);
            removerFim(decks[ChecarListaEscolhida(coluna1)]);
            inserir(decks[ChecarListaEscolhida(coluna2)],cartaPegada);*/
        }
    }
}

void TurnoJoao(Lista *decks[],Pilha *pilhaJ,int *vez){
    int acao,quantAcao = 3,turno = 1;
    while(turno <= 3){
        MostrarDeckPilha(decks,pilhaJ);
        struct carta acessar;

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
            ChecarAcao(decks,acao,vez);
            turno++;
            quantAcao--;
        }

        system("cls");
    }
    *vez = 1;
}

void TurnoGigante(Lista *decks[],Pilha *pilhaJ,int *vez){
    int acao,turno = 1;
    while(turno <= 1){
        MostrarDeckPilha(decks,pilhaJ);

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
    int vez = 0,FimDeJogo = 0,i = 0;
    int *pontVez,*pontFim;
    pontVez = &vez;
    pontFim = &FimDeJogo;

    Lista *decks[5];
    for(i = 0; i < 5;i++){
        decks[i] = criar();
    }

    CriarDeck(decks);

    Pilha *pilhaJoao;
    pilhaJoao = criarPilha();

    while(FimDeJogo != 1){
        if(vez == 0) TurnoJoao(decks,pilhaJoao,pontVez);
        if(vez == 1) TurnoGigante(decks,pilhaJoao,pontVez);
    }

    return 0;
}
