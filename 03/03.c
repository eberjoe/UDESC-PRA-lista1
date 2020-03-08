#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v, n, i, encontrado, p = 0;
    printf("\nEntre o tamanho do vetor 'v': ");
    scanf("%d", &n);
    v = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        printf("Entre um valor para a posicao %d: ", i);
        scanf("%d", v + i);
    }
    printf("\n\nSeu vetor: [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
    do {
        encontrado = 0;
        p++;
        for (i = 0; i < n; i++) {
            if (v[i] == p) {
                encontrado = 1;
                break;
            }
        }
    } while (encontrado);
    printf("O primeiro positivo faltante é: %d\n", p);
    free(v);
    return 0;
}
