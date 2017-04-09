#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi vis;
int d;
int n;
int idmax;
int dmax = 0;

void dfs(int f, int dist){
    vis[f] = 1;
    if (dist > dmax)
    {
        dmax = dist;
        idmax = f;
    }
    for (int i = 0; i < g[f].size(); i++)
    {
        if (!vis[g[f][i]])
            dfs(g[f][i], dist+1);
    }
}

int main ()
{
    int s, d;
    scanf("%d", &n);
    g = vvi(n+1, vi());
    vis = vi(n+1, 0);
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d %d", &s, &d);
        g[s].push_back(d);
        g[d].push_back(s);
    }
    dfs(1, 0);
    vis = vi(n+1, 0);
    dmax = 0;
    dfs(idmax, 0);
    printf("%d\n", dmax);
    return 0;
}