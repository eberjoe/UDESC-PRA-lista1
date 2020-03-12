#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LIMIT 100

int main() {
    char s[MAX_LIMIT], a[MAX_LIMIT];
    int i, *count = calloc(MAX_LIMIT, sizeof(int)), c;
    printf("Entre uma sequência de caracteres: ");
    fgets(s, MAX_LIMIT, stdin);
    for (i = 0; i < strlen(s) - 1; i++){ 
        a[i] = i == 0 ? s[i] : s[i] == a[i - 1] ? NULL : s[i];
    }
    printf("%s", a);
    return 0;
}
