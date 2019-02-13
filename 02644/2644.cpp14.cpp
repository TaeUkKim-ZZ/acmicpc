#include <stdio.h>
#include <queue>

using namespace std;

int first, tofind;
int n, m;
int map[105][105];
int visit[105];
int a,b;
int cnt;
int result;
struct point
{
    int obj;
    int cnt;
};
queue<point> q;

int bfs()
{
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 1; i <= size; i++)
        {
            int now = q.front().obj;
            int cnt = q.front().cnt;
            q.pop();
            
            if(now == tofind)
            {
                return cnt;
            }
            
            for(int j = 1; j <= n; j++)
            {
                if(visit[j] == 0 && map[now][j] == 1)
                {
                    visit[j] = 1;
                    q.push({j, cnt+1});
                    //printf("%d 에서 %d를 큐에 추가합니다. %d촌째. \n", now, j, cnt+1);
                }
            }
        }
        cnt++;
    }
    
    if(!visit[tofind]) return -1;
    return -1;
}

int main(void)
{
    scanf("%d", &n);
    scanf("%d %d", &first, &tofind);
    scanf("%d", &m);
    
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    if(first == tofind)
    {
        printf("0");
        return 0;
    }
    
    visit[first] = 1;
    q.push({first, 0});
    result = bfs();
    printf("%d\n", result);
}