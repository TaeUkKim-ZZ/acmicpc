#include <stdio.h>
#include <queue>
using namespace std;

int m, n, h, cnt;
int tomato[100][100][100];
int visit[100][100][100];
int dir[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };

struct col {
    int x, y, z;
};
queue<col> q;

int bfs()
{
    int ans = 1;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i)
        {
            col c1 = q.front();
            q.pop();
            int x = c1.x; int y = c1.y; int z = c1.z;
            
            if(visit[x][y][z] == 1) continue;
            else visit[x][y][z] = 1;
    
            for(int j = 0; j < 6; ++j)
            {
                int xx = x + dir[j][0];
                int yy = y + dir[j][1];
                int zz = z + dir[j][2];
                
                if(xx < 0 || xx >= h) continue;
                if(yy < 0 || yy >= n) continue;
                if(zz < 0 || zz >= m) continue;
                if(tomato[xx][yy][zz] == -1) continue;
                
                if(tomato[xx][yy][zz] == 0)
                {
                    q.push({xx, yy, zz});
                    tomato[xx][yy][zz] = 1;
                    cnt--;
                }
                
                if(cnt == 0)
                {
                    if(ans == 1) return ans-1;
                    else return ans;
                    
                }
            }
        }
        ans++;
    }
    return -1;
}

int main(void)
{
    scanf("%d %d %d", &m, &n, &h);
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < m; ++k)
            {
                scanf("%d", &tomato[i][j][k]);
                if(tomato[i][j][k] == 0) cnt++;
                else if(tomato[i][j][k] == 1)
                {
                    q.push({i, j ,k});
                }
            }
        }
    }
    
    printf("%d\n", bfs());
}