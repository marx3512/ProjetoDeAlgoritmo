typedef struct elemento *Pilha;

Pilha *criarPilha();
int inserirPilha(Pilha*, struct carta);
int tamanhoPilha(Pilha*);
int acessarPilha(Pilha*, struct carta *);
