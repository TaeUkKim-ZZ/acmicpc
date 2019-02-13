#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i, n, temp;
    long long int fibo1[50];
    long long int fibo0[50];
    
    fibo1[0] = 0;
    fibo1[1] = 1;
    
    fibo0[0] = 1;
    fibo0[1] = 0;
    
    scanf("%d", &n);
    
    for(int i = 2; i <= 41; i++)
    {
        fibo0[i] = fibo0[i-1] + fibo0[i-2];
        fibo1[i] = fibo1[i-1] + fibo1[i-2];
    }
    
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        printf("%lld %lld\n", fibo0[temp], fibo1[temp]);
    }
    
    return 0;
}
