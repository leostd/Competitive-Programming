#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, k;
int x, y;
int mx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int my[8] = {1, -1, 0, 0, 1, -1, 1, -1};
vvi vis; // visited;
vvi xps; // power on the zones
vector<string> g; // grid

bool check(ii pos)
{
    return (pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < n);
}

void bfs(ii s, int xp)
{
    int sz;
    ii a;
    queue<ii> q, p;
    q.push(s);
    vis[s.first][s.second] = 1;
    if (xp > xps[s.first][s.second])
    {
        xps[s.first][s.second] = xp;
    }
    xp--;
    while(!q.empty())
    {
        sz = q.size();
        for (int b = 0; b < sz; b++)
        {
            s = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                a = ii(s.first + mx[i], s.second + my[i]);
                if (check(a) && !vis[a.first][a.second] && xp > xps[a.first][a.second])
                {
                    vis[a.first][a.second] = 1;
                    xps[a.first][a.second] = xp;
                    q.push(a);
                }
            }
        }
        if (xp - 1 > 0) xp--;
    }
}

int main()
{
    char ch;
    scanf("%d %d\n", &n, &k);
    g = vector<string>(n, "");
    xps = vvi(n, vi(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c ", &ch);
            g[i].push_back(ch);
        }
        scanf("\n");
    }
    for (int i = 0; i < k; i++)
    {
        vis = vvi(n, vi(n,0));
        scanf("%d %d", &x, &y);
        bfs(ii(x-1,y-1), 5);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c ", (g[i][j] * xps[i][j]) % 93 + 33);
        printf("\n");
    }
    return 0;
}