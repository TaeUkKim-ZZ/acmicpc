#include <stdio.h>

int a,b,c;
int main(void) {
    int temp;
    scanf("%d %d %d", &a, &b, &c);
    if(a > b) 
    {
        temp = a; 
        a = b; 
        b = temp;
    }
    if(a > c) 
    {
        temp = a; 
        a = c; 
        c = temp;
    }
    if(b > c) {
        temp = b; 
        b = c; 
        c = temp;
    }
    printf("%d", b);
    return 0;
}