#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 3
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi color;

bool bipartiteCheck(vvi g, int s)
{
    bool isBip = true;
    int u, v;
    queue<int> q;
    q.push(s);
    color[s] = 0;
    while(!q.empty() && isBip)
    {
        v = q.front();
        q.pop();
        vi al = g[v];
        for (int i = 0; i < (int)al.size(); i++)
        {
            u = al[i];
            if (color[u] == INF)
            {
                color[u] = 1 - color[v];
                q.push(u);
            }
            else if (color[u] == color[v])
            {
                isBip = false;
                break;
            }

        }
    }
    return isBip;
}

int main()
{
    int t; // test cases
    int v, e; // vertices and edges
    int a, b; // edge
    int sc = 1;
    bool ans;
    scanf("%d", &t);
    while(t--)
    {
        printf("Scenario #%d:\n", sc++);
        scanf("%d %d", &v, &e);
        vvi g(v, vi());
        color = vi(v, INF);
        ans = true;
        for (int i = 0; i < e; i++)
        {
            scanf("%d %d", &a, &b);
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        int i = 0;
        while(ans == true && i < v)
        {
            if (color[i] == INF)
                ans = bipartiteCheck(g, i);
            i++;
        }
        if (ans)
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
    }
    return 0;
}