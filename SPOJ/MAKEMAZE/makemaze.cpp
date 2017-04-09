#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int t; // test cases
int n, m; // dimensions
int ep; // entrypoints
ii eps[402]; // entrypoints vector
char g[25][25]; // grid
bool vis[25][25];
bool valid;
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

bool chk(ii p)
{
    return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);
}

void bfs(ii s){
    queue<ii> q;
    ii a, b;
    int sz;
    q.push(s);
    vis[s.first][s.second] = true;
    while(!q.empty())
    {
        sz = q.size();
        for (int k = 0; k < sz; k++)
        {
            a = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                b = ii(a.first + mx[i], a.second + my[i]);
                if (chk(b) && !vis[b.first][b.second] && g[b.first][b.second] == '.')
                {
                    if (b.first == 0 || b.first == n-1 || b.second == 0 || b.second == m-1) 
                        return;
                    vis[b.first][b.second] = true;
                    q.push(b);
                }
            }
        }
    }
    valid = false;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d\n", &n, &m);
        ep = 0;
        valid = true;
        memset(vis, false, sizeof(bool)*25*25);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%c", &g[i][j]);
                if ((i == 0 || j == 0 || j == m-1 || i == n-1) && g[i][j] == '.')
                    eps[ep++] = ii(i, j);
            }
            scanf("\n");
        }
        if (ep != 2)
            valid = false;
        if (valid)
            bfs(eps[0]);
        if (valid)
            printf("valid");
        else
            printf("invalid");
        printf("\n");
    }
    return 0;
}