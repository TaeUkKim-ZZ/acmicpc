//
//  main.c
//  Algotest2
//
//  Created by 김태욱 on 2018. 7. 3..
//  Copyright © 2018년 anolabs. All rights reserved.
//

#include <stdio.h>

int a,b,c;
int main(void) {
    int numbers[501][501];
    int dp[501][501];
    int n,i,j;
    int max = 0;
    
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            scanf("%d", &numbers[i][j]);
        }
    }
    
    dp[1][1] = numbers[1][1];
    
    for(i = 2; i <=n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            if(j == 1) {
                dp[i][j] = dp[i-1][j] + numbers[i][j];
            }
            else if(j == i) {
                dp[i][j] = dp[i-1][j-1] + numbers[i][j];
            }
            else {
                if(dp[i-1][j-1] >= dp[i-1][j])
                {
                    dp[i][j] = dp[i-1][j-1] + numbers[i][j];
                }
                else if(dp[i-1][j-1] < dp[i-1][j])
                {
                    dp[i][j] = dp[i-1][j] + numbers[i][j];
                }
            }
        }
    }
    
    for(i = 1; i <= n; i++)
    {
        if(max < dp[n][i]) max = dp[n][i];
    }
    
    printf("%d", max);
    return 0;
}
