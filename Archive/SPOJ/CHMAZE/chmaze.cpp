#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAXP=10, MAXR = 21, MAXC = 21; 
int maze[MAXP][MAXR][MAXC];
int p, r, c;
int mx[5] = {0, 0, 0, 1, -1};
int my[5] = {0, 1, -1, 0, 0};
int ds[MAXP][MAXR][MAXC];

bool valid(int x, int y)
{
    return (x >= 0 && x < r && y >= 0 && y < c);
}

int bfs()
{
    iii s = iii(0, ii(0, 0));
    queue<iii> q;
    int p1, r1, c1;
    int p2, r2, c2;
    p1 = s.first;
    r1 = s.second.first;
    c1 = s.second.second;
    if (r1 == r-1 && c1 == c-1)
        return 0;
    ds[p1][r1][c1] = 0;
    maze[p1][r1][c1] = 1;
    q.push(s);
    while(!q.empty())
    {
        s = q.front();
        p1 = s.first;
        r1 = s.second.first;
        c1 = s.second.second;
        q.pop();
        for (int i = 0; i < 5; i++)
        {
            p2 = (p1 + 1) % p;
            r2 = (r1 + mx[i]);
            c2 = (c1 + my[i]);
            if (valid(r2, c2) && maze[p2][r2][c2] == 0)
            {
                maze[p2][r2][c2] = 1;
                ds[p2][r2][c2] = ds[p1][r1][c1] + 1;
                if (r2 == r - 1 && c2 == c - 1)
                    return ds[p2][r2][c2];
                q.push(iii(p2,ii(r2,c2)));
            }
        }
    }
    return -1;
}

int main()
{
    int cs = 1;
    while(scanf("%d %d %d", &r, &c, &p), (p+r+c))
    {
        for(int i = 0; i < p; i++)
            for (int j = 0; j < r; j++)
                for (int k = 0; k < c; k++)
                {
                    scanf("%1d", &maze[i][j][k]);
                    ds[i][j][k] = 0;
                }
        int ans = bfs();
        if (ans >= 0)
            printf("Case %d: Luke and Leia can escape in %d steps.\n", cs++, ans);
        else
            printf("Case %d: Luke and Leia cannot escape.\n", cs++);
    }
    return 0;
}