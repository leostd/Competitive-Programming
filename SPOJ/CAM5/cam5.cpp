#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi visited;

void dfs(int s)
{
    visited[s] = 1;
    vi l = g[s];
    for (int i = 0; i < l.size(); i++)
    {
        if (!visited[l[i]])
            dfs(l[i]);
    }
}

int main()
{   
    int t;
    int v, e;
    int a, b;
    int ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &v, &e);
        g = vvi(v, vi());
        visited = vi(v, 0);
        ans = 0;
        for (int i = 0; i < e; i++)
        {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int i = 0;
        while(i < v)
        {
            if (!visited[i])
            {
                dfs(i);
                ans++;
            }
            i++;
        }
        printf("%d\n", ans);
    }
    return 0;
}