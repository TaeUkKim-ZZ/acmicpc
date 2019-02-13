#include <stdio.h>

int main(void)
{
    long long dp[101];
    int print[101];
    int n;
    scanf("%d", &n);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 67; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &print[i]);
        printf("%lld\n", dp[print[i]]);
    }
    return 0;
}