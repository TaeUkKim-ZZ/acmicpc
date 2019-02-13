//
//  main.c
//  AlgoTest
//
//  Created by 김태욱 on 2018. 7. 3..
//  Copyright © 2018년 anolabs. All rights reserved.
//

#include <stdio.h>
#define NUM_STEP 301
int anScore[NUM_STEP];
int anSumOfScore[NUM_STEP];
int max(int a, int b) { return (a > b) ? a : b; }

int get_sum(int index)
{
    if (index < 0)
        return 0;
    else
        return anSumOfScore[index];
}

void cal_maxsum(int max_index)
{
    int i;
    for (i = 1; i <= max_index; i++)
    {
        anSumOfScore[i] = max( (get_sum(i-3) + anScore[i] + anScore[i-1]),
                              (get_sum(i-2) + anScore[i]) );
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", anScore + i);
    
    cal_maxsum(n);
    
    printf("%d", anSumOfScore[n]);
    return 0;
}
