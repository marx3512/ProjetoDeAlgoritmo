#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "ListaDeck.h"
#include "PilhaJoao.h"
#include "Codigos.h"


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
    /*quantTesouros[0] = Harpa,quantTesouros[1] = Ovo,quantTesouros[2] = Ganso*/
    int quantTesouros[] = {0,0,0};
    int *pontQuantTesouros = quantTesouros;

    while(FimDeJogo != 1){
        if(vez == 0) TurnoJoao(decks,pilhaJoao,pontVez,pontQuantTesouros,pontFim);
        if(vez == 1) TurnoGigante(decks,pilhaJoao,pontVez,pontQuantTesouros,pontFim);
    }

    return 0;
}
