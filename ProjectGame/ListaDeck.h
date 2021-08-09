typedef struct noDescritor Lista;

struct carta{
    int num;
    char nome[10];
};

Lista* criar();
int tamanho(Lista *);
int inserirInicio(Lista *, struct carta);
int inserirFim(Lista *, struct carta);
int removerInicio(Lista *);
int removerFim(Lista *);
int removerIndice(Lista *, int);
int acessarIndice(Lista *, int,struct carta *);
int acessarInicio(Lista *,struct carta *);
int acessarFim(Lista *,struct carta *);
