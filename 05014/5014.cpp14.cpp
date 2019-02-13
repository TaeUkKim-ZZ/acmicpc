#include <stdio.h>
#include <queue>
using namespace std;

int f, s, g, u, d;
int visit[1000001];
int ans, result;
queue<int> q;

int bfs(void)
{
    while(!q.empty())
    {
        //큐의 현재 사이즈를 구해준다.
        int size = q.size();
        for(int i = 1; i <= size; i++)
        {
            //현재 큐의 프론트를 구해준다.
            int aa = q.front();
            q.pop();
            //printf("%d ", aa);
            
            if(aa + u > 0 && aa + u <= f && visit[aa + u] == 0)
            {
                q.push(aa + u);
                visit[aa + u] = 1;
            }
            if(aa - d > 0 && aa - d <= f && visit[aa - d] == 0)
            {
                q.push(aa - d);
                visit[aa - d] = 1;
            }
            if(aa - d == g || aa + u == g)
            {
                return ans + 1;
            }
        }
        ans++;
    }
    return 0;
}

int main(void)
{
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    q.push(s);
    
    if(g == s)
    {
        printf("0");
        return 0;
    }
    else result = bfs();
    
    if(result == 0) printf("use the stairs");
    else printf("%d", result);
    
    return 0;
}