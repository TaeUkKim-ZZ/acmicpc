#include <stdio.h>
#include <queue>
using namespace std;

int map[1001][1001];
int dfsvisit[1001];
int bfsvisit[1001];
int n, m, start;
int a, b;
queue<int> q;

int dfs(int cursur)
{
    //재귀함수로 구현.
    dfsvisit[cursur] = 1;
    
    for(int i = 1; i <= n; i++)
    {
        if(map[cursur][i] == 1 && dfsvisit[i] == 0)
        {
            printf("%d ", i);
            dfsvisit[i] = 1;
            dfs(i);
        }
    }
    
    return 0;
}

int bfs()
{
    q.push(start);
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 1; i <= size; i++)
        {
            int c1 = q.front();
            q.pop();
            bfsvisit[c1] = 1;
            for(int i = 1; i <= n; i++)
            {
                 if(map[c1][i] == 1 && bfsvisit[i] == 0)
                 {
                     q.push(i);
                     bfsvisit[i] = 1;
                     printf("%d ", i);
                 }
            }
        }
    }
    return 0;
}

int main(void)
{
    scanf("%d %d %d", &n, &m, &start);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }
    printf("%d ", start);
    dfs(start);
    printf("\n");
    printf("%d ", start);
    bfs();
    return 0;
}