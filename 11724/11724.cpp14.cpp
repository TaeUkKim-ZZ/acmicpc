#include <stdio.h>

int map[1001][1001];
int visit[1001];
int n, m;
int cnt, finalcnt;

int dfs(int cursur)
{
    visit[cursur] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == 0 && map[cursur][i] == 1)
        {
            //printf("%d에서 %d로 이동\n", cursur, i);
            dfs(i);
        }
    }
    return 0;
}

int main(void)
{
    int a, b;
    
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!visit[i])
        {
            finalcnt++;
            dfs(i);
        }
        //printf("\n");
        /*if(cnt != 0)
        {
            finalcnt = finalcnt + cnt;
        }
        cnt = 0;*/
    }
    
    printf("%d", finalcnt);
    
    return 0;
}