#include <stdio.h>
#include <stdlib.h>
const char* FALSO_OU_VERDADEIRO[] = {"falso", "verdadeiro"}; 

int main() {
    int *v, n, k, soma, i, j;
    printf("Entre um valor para 'k': ");
    scanf("%d", &k);
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
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            soma = v[i] + v[j];
            printf("%d\t+\t%d\t=\t%d\t%s\n", v[i], v[j], soma, FALSO_OU_VERDADEIRO[soma == k]);
        }
    }
    return 0;
}