#include <stdio.h>
int main(void)
{
    int number;
    int cnt = 0;
    int chk;
    int i;
    scanf("%d", &number);
    for(i = 1; i<=5; i++)
    {
        scanf("%d", &chk);
        if(chk == number) cnt++;
        chk = 0;
    }
    printf("%d", cnt);
    return 0;
}