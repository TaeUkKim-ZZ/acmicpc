#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
vector<int> dfsmap[10001];
int visit[10001];
int tmp[10001];
int othercnt = 0;

int dfs(int number)
{
    if(visit[number] == 1) return 0;
    visit[number] = 1;
    for(int i = 0; i < dfsmap[number].size(); i++)
    {
        tmp[number] = tmp[number] + dfs(dfsmap[number][i]);
    }
    return tmp[number] + 1;
}

int main(void)
{
    int cntarray[10001];
    int front, end;
    int cnt = 0;
    int max = 0;
    
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &front, &end);
        dfsmap[end].push_back(front);
    }
    
    for(int i = 1; i <= n; i++)
    {
        memset(visit, 0, sizeof(visit));
        memset(tmp, 0, sizeof(tmp));
        cnt = dfs(i);
        cntarray[i] = cnt;
        if(cnt > max) max = cnt;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(cntarray[i] == max)
        {
            printf("%d ", i);
        }
    }
    return 0;
}