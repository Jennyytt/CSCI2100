#include <stdio.h>

int concatBinary(int a, int b){
    int len = 0;
    int temp = b;
    while (temp) {
        temp >>= 1; //temp = temp>>1
        len++;
    }
    a <<= len; //a = a<<len
    return a | b;
}

int main(void){
    int n; 
    scanf("%d", &n);

    int res[n];
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d",&a,&b);
        res[i] = concatBinary(a, b);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }
    
    return 0;
}