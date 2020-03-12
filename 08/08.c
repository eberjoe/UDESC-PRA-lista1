#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 100

int main() {
    char s[MAX_LIMIT], c;
    int i, count = 0;
    printf("Entre uma sequência de chaves, colchetes e parênteses: ");
    fgets(s, MAX_LIMIT, stdin);
    for (i = 0; i < strlen(s) - 1; i++){ 
        switch (s[i]) {
            case '{':
                c = '}';
                count++;
            case '[':
                c = ']';
                count++;
            case '(':
                c = ')';
                count++;
        }
        if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            count--;
        }
        if (s[i] != c)
            break;
        printf("%d ", s[i]);
    }
    printf("\n%s\n", s);
    printf("%s\n", count == 0 ? "true" : "false");
    return 0;
}