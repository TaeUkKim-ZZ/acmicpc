#include <stdio.h>

int main(void)
{
    int n, x;
    int array[100001];
    scanf("%d %d", &n ,&x);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", &array[i]);
        if(array[i] < x) printf("%d ", array[i]);
    }
    
    return 0;
}