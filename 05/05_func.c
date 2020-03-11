#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "05.h"

int Fatorial(int n) {
    if (n < 2)
        return 1;
    return n * Fatorial(n - 1);
}

int compare(const void* a, const void* b) { 
    return (*(int*)a - *(int*)b); 
}

void Swap(int* a, int* b) { 
    char t = *a; 
    *a = *b; 
    *b = t; 
}
  
int FindCeil(int *v, int first, int l, int h) { 
    int ceilIndex = l; 
    for (int i = l + 1; i <= h; i++) 
        if (v[i] > first && v[i] < v[ceilIndex]) 
            ceilIndex = i; 
    return ceilIndex; 
}

void Permutations(int *v, int size) {
    qsort(v, size, sizeof(v[0]), compare); 
    bool isFinished = false; 
    while (!isFinished) { 
        int j;
        printf("[ ");
        for (j = 0; j < size; j++) {
            printf("%d ", v[j]);
        }
        printf("]\n");
        int i; 
        for (i = size - 2; i >= 0; --i) 
            if (v[i] < v[i + 1]) 
                break; 
        if (i == -1) 
            isFinished = true; 
        else { 
            int ceilIndex = FindCeil(v, v[i], i + 1, size - 1); 
            Swap(&v[i], &v[ceilIndex]); 
            qsort(v + i + 1, size - i - 1, sizeof(v[0]), compare); 
        } 
    }
}