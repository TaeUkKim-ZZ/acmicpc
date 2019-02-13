#include <stdio.h>
#include <queue>
using namespace std;

int subin, catchto;
int result, ans;
int visit[20000001];
queue<int> q;

int bfs() {
    int ans = 1;
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0; i < size; ++i)
        {
            int c1 = q.front();
            q.pop();
            int aa = c1 + 1; int bb = c1 - 1; int cc = c1 * 2;
            
            
            if(visit[aa] == 0 && aa < 100001 && aa >= 0)
            {
                visit[aa] = 1;
                q.push(aa);
            }
            if(visit[bb] == 0 && bb < 100001 && bb >= 0)
            {
                visit[bb] = 1;
                q.push(bb);
            }
            if(visit[cc] == 0 && cc < 100001 && cc >= 0)
            {
                visit[cc] = 1;
                q.push(cc);
            }
            
            if(aa == catchto || bb == catchto || cc == catchto) return ans;
        }
        ans++;
    }
    return 0;
}

int main(void)
{
    scanf("%d %d", &subin, &catchto);
    q.push(subin);
    
    if(subin == catchto)
    {
        printf("0");
        return 0;
    }
    else result = bfs();
    
    printf("%d\n", result);
    return 0;
}