#define ERROLISTA_VAZIA -1
#define ERRO_POS_INVALIDA -2

typedef struct ele {
    void *info;
    struct ele *proximo;
}Elemento;

typedef struct {
    Elemento *cabeca;
    int tamInfo, qtd;
}Lista;

void inicializa_lista(Lista *l, int t);
int insereNoInicio(Lista *l, void *info);
int insereNoFim(Lista *l, void *info);
int leNaPos(Lista *l, void *info, int pos);
void mostra_lista(Lista l, void (*mostra) (void *));
void limpa_lista(Lista *l);
int merge(Lista *l1, Lista *l2, int pos);