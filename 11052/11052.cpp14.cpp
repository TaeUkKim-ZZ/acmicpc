#include <stdio.h>

int main(void)
{
    int n;
    int array[1001];
    int dp[1001];
    int max = 0;
    int pivot;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &array[i]);
    
    array[0] = 0;
    dp[0] = 0;
    dp[1] = array[1];
    
    for(int i = 2; i <= n; i++) {
        max = array[i];
        dp[i] = max;
        for(int j = 0; j <= i / 2; j++)
        {
            pivot = j;
            if(dp[pivot] + dp[i - pivot] > max) {
                max = dp[pivot] + dp[i - pivot];
                dp[i] = max;
            }
        }
    }
    printf("%d", dp[n]);
}