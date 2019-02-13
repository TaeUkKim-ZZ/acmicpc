#include <stdio.h>

int max(int a, int b)
{
    if(a >= b) return a;
    else if(a < b) return b;
    return 0;
}

int main(void) {
    char str1[1001], str2[1001];
    int dp[1001][1001];
    int i = 0,j = 0;
    int str1len = 0, str2len = 0;
    
    scanf("%s %s", &str1, &str2);
    
    //각각의 String 길이를 구한다.
    while(str1[i] != '\0') {
        str1len++;
        i++;
    }
    
    i = 0;
    while(str2[i] != '\0') {
        str2len++;
        i++;
    }
    
    for(i = str1len; i >= 1; i--)
    {
        str1[i] = str1[i - 1];
    }
    for(i = str2len; i >= 1; i--)
    {
        str2[i] = str2[i - 1];
    }
    
    str1[0] = '\0';
    str2[0] = '\0';
    
    //DP초기화 처리.
    for(i = 0; i <= str1len; i++)
    {
        dp[i][0] = 0;
    }
    for(i = 0; i <= str2len; i++)
    {
        dp[0][i] = 0;
    }
    
    for(i = 1; i <= str1len; i++)
    {
        for(j = 1; j <= str2len; j++)
        {
            if(str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else if(str1[i] != str2[j]) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    printf("%d", dp[str1len][str2len]);
}