#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v, *r, produto = 1, n, i, j;
    printf("\nEntre o tamanho do vetor 'v': ");
    scanf("%d", &n);
    v = malloc(sizeof(int) * n);
    r = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        printf("Entre um valor para a posicao %d: ", i);
        scanf("%d", v + i);
    }
    printf("\n\nSeu vetor: [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            produto *= (i != j)? v[j] : 1;
        r[i] = produto;
        produto = 1;
    }
    printf("\n\nVetor resultante: [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }
    printf("]\n");
    free(v);
    free(r);
    return 0;
}