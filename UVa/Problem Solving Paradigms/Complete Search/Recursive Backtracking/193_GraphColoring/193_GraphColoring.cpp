#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#define BLACK 1
#define WHITE 2
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
bitset<102> colored;
int color[102], ans, n;
vi ansl;
vvi g;

void bt(int i)
{
    if (i == n)
    {
        vi bl; // List of the Black Nodes
        for (int j = 0; j < n; j++)
            if (color[j] == BLACK)
                bl.push_back(j);
        if (bl.size() > ans)
        {
            ans = bl.size();
            ansl = bl;
        }
        return;
    }

    bool flag = true; // can this node be a black one?
    int it;
    for (int j = 0; j < g[i].size(); j++)
    {
        it = g[i][j];
        if (colored[it] && color[it] == BLACK)
        {
            flag = false;
            break;
        }
    }
    colored[i] = 1;
    if (flag)
    {
        color[i] = BLACK;
        bt(i+1);
    }
    color[i] = WHITE;
    bt(i+1);
    colored.reset(i);
}

int main()
{
    int m;
    int k;
    int s, d;
    scanf("%d", &m);
    while(m--)
    {

        scanf("%d %d", &n, &k);
        colored.reset();
        ans = 0;
        g = vvi(n+1, vi());
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &s, &d);
            s--;
            d--;
            g[s].push_back(d);
            g[d].push_back(s);
        }
        bt(0);
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++)
        {
            printf("%d", ansl[i]+1);
            if (i < ans-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}