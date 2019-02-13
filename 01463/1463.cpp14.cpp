//
//  main.c
//  AlgoTest
//
//  Created by 김태욱 on 2018. 7. 3..
//  Copyright © 2018년 anolabs. All rights reserved.
//

#include <stdio.h>

int min(int a, int b) {
    if(a >= b) return b;
    else if(a < b) return a;
    return 0;
}

int min3(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else if(c <= a && c <= b) return c;
    return 0;
}

int main(void) {
    int n;
    int dp[1000001];
    
    scanf("%d", &n);
    
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(i % 6 == 0) {
            dp[i] = min3(dp[i / 3], dp[i / 2], dp[i - 1]) + 1;
        }
        else if(i % 3 == 0) {
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        }
        else if(i % 2 == 0) {
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        }
        else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    
    printf("%d", dp[n]);
    return 0;
}
