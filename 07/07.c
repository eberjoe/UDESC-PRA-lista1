#include <stdio.h>
#include "07.h"

void mostra_int(void *x) {
    printf("%d\n", *(int*) x);
}

int compara_int(void *x, void *y) {
    int *a = x, *b = y;
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    return 0;
}

int main() {
    Lista lista[2];
    static int l, x, p;
    inicializa_lista(&lista[0], sizeof(int));
    inicializa_lista(&lista[1], sizeof(int));
    for (l = 0; l < 2; l++) {
        while (1) {
            printf("Entre um inteiro para a lista %d, ou uma letra para terminar a lista: ", l + 1);
            if (scanf("%d", &x))
                insereNoFim(&lista[l], &x);
            else
                break;
        }
        printf("\nLISTA %d\n", l + 1);
        mostra_lista(lista[l], mostra_int);
        printf("\n");
        while (getchar() != '\n'); // consome o retorno de linha em excesso da entrada do usuário
    }
    printf("\nDigite a posição em que a lista 1 será interceptada pela lista 2 (de 0 a %d): ", lista[0].qtd - 1);
    scanf("%d", &p);
    merge(&lista[0], &lista[1], p);
    for (l = 0; l < 2; l++) {
        printf("\nLISTA %d\n", l + 1);
        mostra_lista(lista[l], mostra_int);
    }
    leNaPos(&lista[0], &x, p);
    printf("\nO valor no ponto de interseção é %d.\n", x);
    limpa_lista(&lista[1]);
    return 0;
}