#include <stdio.h>

int main(void)
{
    int su[10001], i, ii, temp, n;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &su[i]);
    }
    
    for(i = 0; i < n-1; i++)
    {
        for(ii = 0; (ii + i) < n-1; ii++)
        {
            if(su[ii] > su[ii + 1])
            {
                temp = su[ii];
                su[ii] = su[ii + 1];
                su[ii + 1] = temp;
            }
        }
    }
    
    for(i = 0; i < n; i++) printf("%d\n", su[i]);
    return 0;
}