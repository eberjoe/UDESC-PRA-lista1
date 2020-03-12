#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 100

int main() {
    char s[MAX_LIMIT], a[MAX_LIMIT];
    int i;
    printf("Entre uma sequência de chaves, colchetes e parênteses: ");
    fgets(s, MAX_LIMIT, stdin);
    for (i = 0; i < strlen(s) - 1; i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            strncat(a, &s[i], 1);
        } else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if (a[strlen(a) - 1] != s[i] - 1 && a[strlen(a) - 1] != s[i] - 2) {
                strncat(a, &s[i], 1);
            } else {
                a[strlen(a) - 1] = 0;
            }
        }
    }
    printf("\n%s\n", s);
    printf("%s\n", !strlen(a) ? "true" : "false");
    return 0;
}