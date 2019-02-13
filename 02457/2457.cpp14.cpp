#include <stdio.h>

int startday[100001];
int endday[100001];
int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int flowerchk[100001];
int i,j,n;
int nowday;
int tot;
int locate;
int chk;
int big;
int a,b,c,d,e,f;

int main(void)
{
	scanf("%d", &n);
	
	for(i=1;i<=n;i++)	{
		scanf("%d %d %d %d", &a, &b, &c, &d);

		// 날짜수 구하기 루틴.
		for(j=1;j<=a-1;j++)
		{
			e=e+monthday[j];
		}
		e=e+b;

		// 끝나는 날짜수 구하기 루틴.
		for(j=1;j<=c-1;j++)
		{
			f=f+monthday[j];
		}
		f=f+d-1;

		startday[i]=e;
		endday[i]=f;

		e=f=0;
	}

	nowday=60;
	while(1)
	{
		for(i=1;i<=n;i++)
		{
             if(startday[i]<=nowday)
			 {
				 if(endday[i] > big)
				 {
					 if(flowerchk[i]==0)
					 {
					      big=endday[i];
					      locate=i;
					      chk=1;
					 }
				 }
			 }
		}
		if(chk==0) break;
		else tot++;
		nowday=endday[locate]+1;
		flowerchk[locate]=1;
		if(nowday>334) break;
		big=0; locate=0; chk=0;
	}

	if(chk==0) printf("0");
	else printf("%d", tot);

	return 0;
}
		
