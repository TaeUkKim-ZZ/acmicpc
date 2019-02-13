#include <stdio.h>

int main()
{
  int n,k,i,j,MAX=-1000000,sum=0,m;
  int d[100000];
  scanf("%d %d",&n,&k);
  for (i=0;i<n;i++) scanf("%d",&d[i]);
    
   for (m=0;m<k;m++) sum +=d[m];
    
   for (j=0;j<=n-k;j++){
     if (MAX<sum) MAX=sum;
     sum +=d[m++]-d[j];
   }
    
  printf("%d",MAX);
  return 0;
}
