#include <stdio.h>
int main(void)
{
    int fibo[60];
    int n;
    fibo[1] = 0; 
    fibo[2] = 1;
    for(int i = 3; i <= 50; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    scanf("%d", &n);
    printf("%d", fibo[n+1]);
    return 0;
}