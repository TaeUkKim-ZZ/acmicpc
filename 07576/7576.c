#include <stdio.h>

int cnt[1001][1001];
int fx[1000001], fy[1000001];
int nx[5]={0,0,-1,0,1};
int ny[5]={0,-1,0,1,0};

int main(void)
{
    int map[1005][1005];
    int chk[1005][1005];
    int i, j;
    int f, s;
    int m, n;
    int max = 0;
    int pluscount = 0;
    scanf("%d %d", &m, &n);
    f=s=0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            scanf("%d", &map[i][j]);
            cnt[i][j] = 0;
            chk[i][j] = 0;
            if(map[i][j] == 1)
            {
                f++;
                s++;
                pluscount++;
                fx[f] = i;
                fy[f] = j;
                chk[i][j] = 1;
                cnt[i][j] = 1;
            }
        }
    }
    if(pluscount == 1) pluscount = 0;
    f=s=1;
    while(f <= s + pluscount)
    {
        for(i = 1; i <= 4; i++)
        {
            if(map[fx[f] + nx[i]][fy[f] + ny[i]] == 0 && chk[fx[f] + nx[i]][fy[f] + ny[i]] == 0 && fx[f] <= n && fy[f] <= m && fx[f] + nx[i] <=n && fy[f] + ny[i] <= m && fx[f] + nx[i] != 0 && fy[f] + ny[i] != 0)
            {
                s++;
                fx[s + pluscount] = fx[f] + nx[i];
                fy[s + pluscount] = fy[f] + ny[i];
                map[fx[f] + nx[i]][fy[f] + ny[i]] = 1;
                chk[fx[f]+ nx[i]][fy[f] + ny[i]] = 1;
                cnt[fx[f] + nx[i]][fy[f] + ny[i]] = cnt[fx[f]][fy[f]] + 1;
            }
        }
        f++;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(map[i][j] == 0)
            {
                printf("-1");
                return 0;
            }
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
         //   printf("%d ", cnt[i][j]);
            if(cnt[i][j] > max)
            {
                max = cnt[i][j];
            }
        }
    //    printf("\n");
    }
    if(max == 0) printf("0");
    else printf("%d", max-1);
    return 0;
}