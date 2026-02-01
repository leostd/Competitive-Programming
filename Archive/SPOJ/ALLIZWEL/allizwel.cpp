#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;


vs g; // graph
vvi vis; // visited
vii as; // initial positions
int t, r, c; // tc, rows, cols
int mx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int my[8] = {1, -1, 1, -1, 0, 0, 1, -1};
string cm = "ALLIZZWELL";

bool chk(int x, int y)
{
    return (x >= 0 && x < r && y >= 0 && y < c);
}

bool dfs(ii s, int idx)
{
    if (idx == cm.size())
        return true;
    ii e;
    vis[s.first][s.second] = 1;
    for (int i = 0; i < 8; i++)
    {
        e = ii(s.first + mx[i], s.second + my[i]);
        if (chk(e.first, e.second) && vis[e.first][e.second] == -1 && g[e.first][e.second] == cm[idx])
            if (dfs(e, idx+1))
                return true;
    }
    vis[s.first][s.second] = -1;
    return false;
}

int main()
{
    scanf("%d", &t);
    char ch;
    bool flag;
    while(t--)
    {
        scanf("%d %d\n", &r, &c);
        g = vs(r, "");
        vis = vvi(r, vi(c, -1));
        as.clear();
        flag = false;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%c", &ch);
                g[i].push_back(ch);
                if (ch == 'A')
                    as.push_back(ii(i, j));
            }
            scanf("\n");
        }
        for (int i = 0; i < as.size(); i++)
        {
            if (dfs(as[i], 1))
            {
                flag = true;
                break;
            }
            vis = vvi(r, vi(c, -1)); // reset the visited
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}