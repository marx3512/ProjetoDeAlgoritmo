typedef struct noDescritor Fila;

struct carta{
    int num;
    char nome[10];
};

Fila* criar();
int tamanho(Fila *);
int inserir(Fila *, struct carta);
int removerInicio(Fila *);
int removerFim(Fila *);
int acessar(Fila *, struct carta *);
