#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int v, e; // vertices and edges
int s, d; // edge
vvi g; // graph
bool visited[10000];

bool dfs(int s, int p)
{
    int e;
    visited[s] = true;
    vi al = g[s];
    for (int i = 0; i < al.size(); i++)
    {
        e = al[i];
        if (visited[e] && e != p)
            return false;
        else if (!visited[e])
            dfs(e, s);
    }
    return true;
}

int main()
{
    scanf("%d %d", &v, &e);
    g = vvi(v, vi());
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &s, &d);
        g[s-1].push_back(d-1);
        g[d-1].push_back(s-1);
    }
    bool tree = dfs(0, 0);
    for (int i = 0; i < v; i++)
        if (!visited[i]) tree = false;
    if (tree)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}