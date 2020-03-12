#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void Binary(int decimal, bool *binary) {
    int r, i = 0;
    while(decimal > 0){
        r = decimal % 2;
        decimal /= 2;
        binary[i] = r ? true : false;
        i++;
    }
}

int main() {
    int *v, n, i, j, p;
    bool *b;
    printf("\nEntre o tamanho do conjunto 'v' de inteiros: ");
    scanf("%d", &n);
    v = malloc(sizeof(int) * n);
    b = malloc(sizeof(bool) * n);
    p = (int) pow(2, n);
    for (i = 0; i < n; i++) {
        printf("Entre um valor para a posição %d: ", i);
        scanf("%d", v + i);
    }
    printf("\nO power set de [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("] é\n[ []");
    for (i = 1; i < p; i++) {
        Binary(i, b);
        printf(" [ ");
        for (j = 0; j < n; j++) {
            if (b[j])
                printf("%d ", v[j]);
        }
        printf("]");
    }
    printf(" ]\n");
    free(v);
    free(b);
    return 0;
}