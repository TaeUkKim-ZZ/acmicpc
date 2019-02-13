#include <stdio.h>

int main(void)
{
    int ascore[11];
    int bscore[11];
    int acnt = 0, bcnt = 0;
    
    for(int i = 1; i <= 10; i++)
    {
        scanf("%d", &ascore[i]);
    }
    for(int i = 1; i <= 10; i++)
    {
        scanf("%d", &bscore[i]);
    }
    
    for(int i = 1; i <= 10; i++)
    {
        if(ascore[i] == bscore[i])
        {
            acnt++;
            bcnt++;
        }
        else if(ascore[i] > bscore[i])
        {
            acnt++;
        }
        else if(ascore[i] < bscore[i])
        {
            bcnt++;
        }
    }
    
    if(acnt == bcnt) printf("D");
    else if(acnt > bcnt) printf("A");
    else if(acnt < bcnt) printf("B");
    
    return 0;
}