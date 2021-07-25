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

void CriarDeck(Lista *deck1, Lista *deck2, Lista *deck3, Lista *deck4, Lista *deck5){
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
    int i;
    for (i = 0; i < 10; i++){
        c.num = rand()%16;
        c = ChecarCartaCriada(c.num,pontFei,pontGan,pontOvo,pontHarp,pontFii,pontFoo,pontFuu,pontFaa);
        inserir(deck1,c);
        c.num = rand()%16;
        c = ChecarCartaCriada(c.num,pontFei,pontGan,pontOvo,pontHarp,pontFii,pontFoo,pontFuu,pontFaa);
        inserir(deck2,c);
        c.num = rand()%16;
        c = ChecarCartaCriada(c.num,pontFei,pontGan,pontOvo,pontHarp,pontFii,pontFoo,pontFuu,pontFaa);
        inserir(deck3,c);
        c.num = rand()%16;
        c = ChecarCartaCriada(c.num,pontFei,pontGan,pontOvo,pontHarp,pontFii,pontFoo,pontFuu,pontFaa);
        inserir(deck4,c);
        c.num = rand()%16;
        c = ChecarCartaCriada(c.num,pontFei,pontGan,pontOvo,pontHarp,pontFii,pontFoo,pontFuu,pontFaa);
        inserir(deck5,c);
    }
}

void MostrarDeckPilha(Lista *deck1, Lista *deck2, Lista *deck3, Lista *deck4, Lista *deck5,Pilha *pilhaJ){

    int pos = 0;
    struct carta pegarCarta;
    printf("      A              B              C              D              E \n");
    while(pos < tamanho(deck1) || pos < tamanho(deck2) || pos < tamanho(deck3)|| pos < tamanho(deck4)|| pos < tamanho(deck5)){
        int cond1 = acessarIndice(deck1,pos,&pegarCarta);
        if (cond1 == 1) MostrarCard(pegarCarta);
        else if(cond1 == 0) printf("               ");
        int cond2 = acessarIndice(deck2,pos,&pegarCarta);
        if (cond2 == 1) MostrarCard(pegarCarta);
        else if(cond2 == 0) printf("               ");
        int cond3 = acessarIndice(deck3,pos,&pegarCarta);
        if (cond3 == 1) MostrarCard(pegarCarta);
        else if(cond3 == 0) printf("               ");
        int cond4 = acessarIndice(deck4,pos,&pegarCarta);
        if (cond4 == 1) MostrarCard(pegarCarta);
        else if(cond4 == 0) printf("               ");
        int cond5 = acessarIndice(deck5,pos,&pegarCarta);
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

void ChecarAcao(Lista *deck1,Lista *deck2,Lista *deck3,Lista *deck4,Lista *deck5,int acao,int *vez){
    char coluna1[5],coluna2[5];
    Lista *acesso1,*acesso2;
    struct carta cartaPegada;
    if(*vez == 0){
        if(acao == 1){
            acessarInicio(deck1,&cartaPegada);
            printf("Carta pegada: %d", cartaPegada.num);
            printf("Escolha uma coluna: ");
            scanf("%s", coluna1);
            printf("\n");
            acesso1 = listaEscolhida(deck1,deck2,deck3,deck4,deck5,coluna1);
            printf("Esolha outra coluna: ");
            scanf(" %s", coluna2);

            removerFim(deck5);
        }
    }
}

void TurnoJoao(Lista *deck1,Lista *deck2,Lista *deck3,Lista *deck4, Lista *deck5,Pilha *pilhaJ,int *vez){
    int acao,quantAcao = 3,turno = 1;
    while(turno <= 3){
        MostrarDeckPilha(deck1,deck2,deck3,deck4,deck5,pilhaJ);
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
            ChecarAcao(deck1,deck2,deck3,deck4,deck5,acao,vez);
            turno++;
            quantAcao--;
        }

        system("cls");
    }
    *vez = 1;
}

void TurnoGigante(Lista *deck1,Lista *deck2,Lista *deck3,Lista *deck4,Lista *deck5,Pilha *pilhaJ,int *vez){
    int acao,turno = 1;
    while(turno <= 1){
        MostrarDeckPilha(deck1,deck2,deck3,deck4,deck5,pilhaJ);

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

    Lista *deck1;
    Lista *deck2;
    Lista *deck3;
    Lista *deck4;
    Lista *deck5;

    deck1 = NULL;
    deck1 = criar();
    deck2 = NULL;
    deck2 = criar();
    deck3 = NULL;
    deck3 = criar();
    deck4 = NULL;
    deck4 = criar();
    deck5 = NULL;
    deck5 = criar();

    CriarDeck(deck1, deck2, deck3, deck4,deck5);

    Pilha *pilhaJoao;
    pilhaJoao = criarPilha();

    while(FimDeJogo != 1){
        if(vez == 0) TurnoJoao(deck1,deck2,deck3,deck4,deck5,pilhaJoao,pontVez);
        if(vez == 1) TurnoGigante(deck1,deck2,deck3,deck4,deck5,pilhaJoao,pontVez);
    }

    return 0;
}
