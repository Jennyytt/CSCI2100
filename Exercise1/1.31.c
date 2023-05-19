#include <stdio.h>

int main() {
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        char s[256];
        char res[256];
        scanf("%[^\n]%*c", s);
        int x = 0;
        int y = 0;
        for (int i = 0; i < 256; i++) {
            char stack[50];
            if (s[i] == ' ' || s[i] == '\0') {
                for (int j = x-1; j >= 0; j--) {
                    res[y++] = stack[j];  //pop
                }
                x = 0;
                if (s[i] == '\0') {
                    res[y] = '\0';
                    break;
                }
                res[y++] = ' ';
            }
            else {
                stack[x++] = s[i];  //push
            }
        }
        printf("%s\n", res);
    }

    return 0;
}