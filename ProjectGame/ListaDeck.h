typedef struct noDescritor Lista;

struct carta{
    int num;
    char nome[10];
};

Lista* criar();
Lista* listaEscolhida(Lista *,Lista *,Lista *,Lista *,Lista *,char letra);
int tamanho(Lista *);
int inserir(Lista *, struct carta);
int removerInicio(Lista *);
int removerFim(Lista *);
int acessarIndice(Lista *, int,struct carta *);
int acessarInicio(Lista *,struct carta *);
