#include <stdio.h>

int network[201][201];
int visit2[201][201];
int visit[201];
int n, input;
int first, second;
int cnt = 0;
int before;

void DFS(int node)
{
        for(int j = 1; j <= n; j++)
        {
            if(network[node][j] == 1)
            {
                visit2[j][node] = 1;
                visit[j] = 1;
                if(visit2[node][j] != 1) DFS(j);
            }
        }
}

int main(void) {
    scanf("%d %d", &n, &input);
    for(int i = 1; i <= input; i++)
    {
        scanf("%d %d", &first, &second);
        network[first][second] = 1;
        network[second][first] = 1;
    }
    DFS(1);
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == 1) cnt++;
    }
    printf("%d", cnt-1);
    return 0;
}