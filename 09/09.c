#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LIMIT 100

int main() {
    int i, r = 1;
    char s[MAX_LIMIT], a[MAX_LIMIT], n[2], p;
    printf("Entre uma sequência de caracteres: ");
    fgets(s, MAX_LIMIT, stdin);
    p = s[0];
    for (i = 1; i < strlen(s); i++) {
        if (s[i] == p)
            r++;
        else {
            sprintf(n, "%d", r);
            strncat(a, n, 2);
            strncat(a, &p, 1);
            p = s[i];
            r = 1;
        }
    }
    printf("\nCompressão RLE:\n\n%s\n", a);
    return 0;
}
