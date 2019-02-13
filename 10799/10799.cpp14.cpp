#include <stdio.h>

int main(void)
{
    char datas1[100001];
    int nowstick = 0;
    int total = 0;
    int firstcount = 0;
    int secondcount = 0;
    
    scanf("%s", &datas1);
    
    int size = 0;
    while(datas1[size] != '\0')
    {
        size++;
    }
    
    for(int i = 0; i < size; i++)
    {
        if(datas1[i] == '(')
        {
            while(datas1[i] != ')' && i < size)
            {
                if(firstcount == 1)
                {
                    nowstick++;
                }
                else
                {
                    firstcount = 1;
                }
                i++;
            }
            i--;
        }
        else if(datas1[i] == ')')
        {
            while(datas1[i] != '(' && i < size)
            {
                if(secondcount == 1)
                {
                    nowstick--;
                    total++;
                    //printf("%d 조각이 끝남. 총 %d조각. \n", i, total);
                }
                else
                {
                    total = total + nowstick;
                    secondcount = 1;
                    //printf("%d 번째에서 레이저 작동! %d 조각임.\n", i, total);
                }
                i++;
            }
            i--;
        }
        firstcount = 0;
        secondcount = 0;
    }
    
    printf("%d", total);
    
    return 0;
    
}