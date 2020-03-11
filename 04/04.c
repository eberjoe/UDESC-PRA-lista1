#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int *v, n, i, j, imax, jmax, soma = INT_MIN, total = 0, tamanho;
    printf("\nEntre o tamanho do vetor 'v': ");
    scanf("%d", &n);
    if (n < 3) {
        printf("O vetor deve ter pelo menos 3 elementos!\n");
        return 0;
    }
    v = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        printf("Entre um valor para a posicao %d: ", i);
        scanf("%d", v + i);
    }
    printf("\nSeu vetor: [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
    tamanho = n;
    while (tamanho > 1) {
        for (i = 0; i < tamanho - 1; i++) {
            for (j = i + 2; j < tamanho; j++) {
                if (v[i] + v[j] > soma) {
                    soma = v[i] + v[j];
                    imax = i;
                    jmax = j;
                }
            }
        }
        total += soma > 0 ? soma : 0;
        soma = INT_MIN;
        v[imax] = INT_MIN;
        v[jmax] = INT_MIN;
        tamanho -= 2;
        if (jmax > imax + 2) {
            v[imax + 1] = INT_MIN;
            v[jmax - 1] = INT_MIN;
            tamanho -= 2;
        } else {
            v[jmax - 1] = INT_MIN;
            tamanho--;
        }
        if (imax > 0) {
            v[imax - 1] = INT_MIN;
            tamanho--;
        }
        if (jmax < n - 1) {
            v[jmax + 1] = INT_MIN;
            tamanho--;
        }
    }
    for (i = 0; i < n; i++) {
        if (v[i] > INT_MIN)
            total += v[i];
    }
    printf("\nA maior soma entre elementos não adjacentes: %d\n", total);
    free(v);
    return 0;
}
