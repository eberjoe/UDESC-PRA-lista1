#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) { 
    return (*(int*) a - *(int*) b); 
}

int main() {
    int *v, *sub, n, k, i, j;
    printf("\nEntre o tamanho do vetor 'v': ");
    scanf("%d", &n);
    if (n < 3) {
        printf("O vetor deve ter pelo menos 3 elementos!\n");
        return 0;
    }
    printf("Entre um valor para 'k' (entre 1 e o tamanho do vetor): ");
    scanf("%d", &k);
    if (k < 1 || k > n) {
        printf("O valor de 'k' deve ser entre 1 e o tamanho do vetor!\n");
        return 0;
    }
    v = malloc(sizeof(int) * n);
    sub = malloc(sizeof(int) * k);
    for (i = 0; i < n; i++) {
        printf("Entre um valor para a posicao %d: ", i);
        scanf("%d", v + i);
    }
    printf("\nSeu vetor: [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n\n");
    for (i = 0; i <= n - k; i++) {
        printf("[ ");
        for (j = 0; j < k; j++) {
            sub[j] = v[i + j];
            printf("%d ", sub[j]);
        }
        qsort(sub, k, sizeof(int), compare);
        printf("]\tmax:\t%d\n", sub[k - 1]);
    }
    free(v);
    free(sub);
    return 0;
}
