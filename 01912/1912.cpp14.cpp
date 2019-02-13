#include <stdio.h>

int max(int a, int b)
{
    if(a>=b) return a;
    if(a<b) return b;
    return 0;
}

int main(void)
{
    int i, n;
    int arr[1000001];
    
    scanf("%d", &n);
    for(i = 1; i <=n ; i++) scanf("%d", &arr[i]);
    
    int ret = -1234;
    int psum = 0;
    
    for(i = 1; i <=n; i++)
    {
        psum = max(psum, 0) + arr[i];
        ret = max(psum, ret);
    }
    
    printf("%d", ret);
}