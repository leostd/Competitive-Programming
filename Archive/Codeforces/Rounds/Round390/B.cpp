#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

char g[4][4];
int vis[4][4];
int mx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int my[8] = {1, -1, 0, 0, -1, 1, -1, 1};
vii xs;

bool check(ii p)
{
    return (p.first >= 0 && p.first < 4 && p.second >= 0 && p.second < 4);
}

bool dfs(ii s)
{
    ii a;
    vvi vs(4, vi(4,0));
    vs[s.first][s.second] = 1;
    for (int i = 0; i < 8; i++)
    {
        a = ii(s.first + mx[i], s.second + my[i]);
        if (check(a) && g[a.first][a.second] == 'x' && !vs[a.first][a.second])
        {
            a = ii(a.first + mx[i], a.second + my[i]);
            if (check(a) && g[a.first][a.second] == '.')
                return true;
        }
        else if (check(a) && g[a.first][a.second] == '.' && !vs[a.first][a.second])
        {
            a = ii(a.first + mx[i], a.second + my[i]);
            if (check(a) && g[a.first][a.second] == 'x')
                return true;
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%c", &g[i][j]);
            if (g[i][j] == 'x')
                xs.push_back(ii(i,j));
        }
        scanf("\n");
    }
    bool flag = false;
    for (int i = 0; i < xs.size(); i++)
    {
        if (dfs(xs[i]))
        {
            flag = true;
            break;
        }
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}