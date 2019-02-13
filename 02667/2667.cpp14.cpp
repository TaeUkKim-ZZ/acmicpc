//
//  main.c
//  Algotest2
//
//  Created by 김태욱 on 2018. 7. 3..
//  Copyright © 2018년 anolabs. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, j, k, n;
    char map[1001][1001];
    int chk[1001][1001];
    int nx[5] = {0,0,-1,0,1};
    int ny[5] = {0,-1,0,1,0};
    int fx[500], fy[500];
    int f,s;
    int cnt, cnt2;
    int cntsave[500];
    int change;
    
    scanf("%d", &n);
    
    cnt = 1;
    cnt2 = 0;
    
    for(int i = 0; i < n; i++)
    {
            scanf("%s", &map[i]);
    }
    
    f=s=1;
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n ; j++)
        {
            if(map[i][j] == '1' && chk [i][j] == 0)
            {
                chk[i][j] = 1;
                fx[f] = i;
                fy[f] = j;
                
                while(f <= s)
                {
                    for(k = 1; k <= 4; k++)
                    {
                        if(map[fx[f] + nx[k]][fy[f] + ny[k]] == '1' && chk[fx[f] + nx[k]][fy[f] + ny[k]] == 0 && fx[f] < n && fy[f] < n && fx[f] + nx[k] < n && fy[f] + ny[k] < n && fx[f] + nx[k] >= 0 && fy[f] + ny[k] >= 0)
                        {
                            chk[fx[f] + nx[k]][fy[f] + ny[k]] = 1;
                            cnt++;
                            s++;
                            fx[s] = fx[f] + nx[k];
                            fy[s] = fy[f] + ny[k];
                        }
                    }
                    f++;
                }
                
                cntsave[cnt2] = cnt;
                cnt2++;
                f = s = 1;
                cnt = 1;
            }
        }
    }
    
    printf("%d\n", cnt2);
    
    for(i = 0; i < cnt2; i++)
    {
        for(j = i + 1; j < cnt2; j++)
        {
            if(cntsave[i] > cntsave[j] && cntsave[i] != 0 && cntsave[j] != 0) {
                change = cntsave[i];
                cntsave[i] = cntsave[j];
                cntsave[j] = change;
            }
        }
    }
    
    for(i = 0; i < cnt2; i++)
    {
        printf("%d\n", cntsave[i]);
    }


    //printf("Hello, World!\n");
    //printf("%d", n);
    return 0;
}