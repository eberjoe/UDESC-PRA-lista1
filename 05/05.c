#include <stdio.h>
#include <stdlib.h>
#include "05.h"

int main() {
    int n, i, *v, uns, nResutados, passos;
    printf("Entre o numero de degraus maior que 1: ");
    scanf("%d", &n);
    passos = n / 2 + n % 2;
    nResutados = n % 2 ? passos + 1 : 2;
    for (i = passos + 1; i < n; i++) {
        uns = n % 2 + 2 * (i - passos);
        nResutados += Fatorial(i) / (Fatorial(uns) * Fatorial(i - uns));
    }
    printf("\nO número de combinações possíveis é %d\n\n", nResutados);
    v = malloc(sizeof(int) * passos);
    for (i = 0; i < passos; i++)
        v[i] = n % 2 && i == passos - 1 ? 1 : 2;
    while (passos <= n) {
        Permutations(v, passos);
        passos++;
        v = realloc(v, sizeof(int) * passos);
        for (i = 0; i < passos; i++)
            v[i] = n - i > passos ? 2 : 1;
    }
    free(v);
    return 0;
}