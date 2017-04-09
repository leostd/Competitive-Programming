#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
int m,n;
int xmov[8] = {0, 0, 1, -1};
int ymov[8] = {1, -1, 0, 0};
queue<int> x, y, dist;
vvi matrix, ds;

void bfs()
{
    int a, b, aux, md;
    vvi chk(m, vi(n, 0));
    while(!x.empty() && !y.empty())
    {
        a = x.front(); b = y.front(); md = dist.front();
        x.pop(); y.pop(); dist.pop();
        if(chk[a][b])
            continue;
        chk[a][b] = 1;
        ds[a][b] = md;
        for (int it = 0; it < 4; it++)
        {
            if (a + xmov[it] >= 0 && a + xmov[it] < m && b + ymov[it] >= 0 && b + ymov[it] < n && !chk[a + xmov[it]][b + ymov[it]] && !matrix[a+xmov[it]][b+ymov[it]])
            {
                x.push(a+xmov[it]);
                y.push(b+ymov[it]);
                dist.push(md+1);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        matrix = vvi(m, vi(n, 0));
        ds = vvi(m, vi(n, 1e8));
        x = queue<int>();
        y = queue<int>();
        dist = queue<int>();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%1d", &matrix[i][j]);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                {
                    x.push(i);
                    y.push(j);
                    dist.push(0);
                    ds[i][j] = 0;
                }
        bfs();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", ds[i][j]);
            printf("\n");
        }
    }
    return 0;
}