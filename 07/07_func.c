#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "07.h"

void inicializa_lista(Lista *l, int t) {
    l->cabeca = NULL;
    l->tamInfo = t;
    l->qtd = 0;
}

int lista_vazia(Lista *l) {
    return !l->qtd;
}

Elemento* aloca_ele(void *x, int t){
	Elemento *p = malloc(sizeof(Elemento));
	if (!p)
		return NULL; // falta memória
	p->info = malloc(t);
	if (!p->info){
		free(p);
		return NULL; // falta memória
	}
	memcpy(p->info, x, t);
	return p;
}

int insereNoInicio(Lista *l, void *info) {
    Elemento *p = aloca_ele(info, l->tamInfo);
    if (!p)
        return 0; // falta memória
    p->proximo = l->cabeca;
    l->cabeca = p;
    l->qtd++;
    return 1; // sucesso
}

int insereNoFim(Lista *l, void *info) {
    Elemento *p = aloca_ele(info, l->tamInfo);
    if (!p)
        return 0; // falta memória
    p->proximo = NULL;
    if (!l->cabeca) {
        return insereNoInicio(l, info);
    } else {
        Elemento *q = l->cabeca;
        while (q->proximo) {
            q = q->proximo;
        }
        q->proximo = p;
    }
    l->qtd++;
    return 1; // sucesso
}

int leNaPos(Lista *l, void *info, int pos) {
    if (lista_vazia(l))
        return ERROLISTA_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    Elemento *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++)
        p = p->proximo;
    memcpy(info, p->info, l->tamInfo);
    return 1; // sucesso
}

void mostra_lista(Lista l, void (*mostra) (void *)) {
    if (lista_vazia(&l))
        printf("\nLista vazia!\n");
    else {
        Elemento *p = l.cabeca;
        int count =0;
        while (p) {
            printf("%d\t", count);
            mostra(p->info);
            p = p->proximo;
            count++;
        }
    }
}

void limpa_lista(Lista *l) {
    Elemento *p = l->cabeca, *q;
    while (p) {
        q = p;
        p = p->proximo;
        free(q->info);
        free(q);
    }
    l->cabeca = NULL;
    l->qtd = 0;
}

int merge(Lista *l1, Lista *l2, int pos) {
    if (lista_vazia(l1))
        return ERROLISTA_VAZIA;
    if (pos < 0 || pos >= l1->qtd)
        return ERRO_POS_INVALIDA;
    Elemento *q = l2->cabeca;
    while (q->proximo) {
        q = q->proximo;
    }
    Elemento *p = l1->cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++) {
        p = p->proximo;
    }
    q->proximo = p;
    l2->qtd += l1->qtd - pos;
    return 1;
}