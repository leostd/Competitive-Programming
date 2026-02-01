#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, it, src, dst;
int tsv[105]; // topological sort
bool vis[105]; // visited array
vi g[105]; // DAG

void ts(int s){
    vis[s] = true;
    for (int i = 0; i < (int)g[s].size(); i++){
        if (!vis[g[s][i]])
            ts(g[s][i]);
    }
    tsv[it++] = s;
}

int main()
{
    while(scanf("%d %d", &n, &m), n || m){
        memset(tsv, -1, sizeof(tsv));
        memset(vis, false, sizeof(vis));
        fill(g, g+105, vi());
        it = 0;
        for (int i = 0; i < m; i++){
            scanf("%d %d", &src, &dst);
            g[src].push_back(dst);
        }
        for (int i = 1; i <= n; i++){
            if (!vis[i])
                ts(i);
        }
        for (int i = n-1; i >= 0; i--){
            printf("%d ", tsv[i]);
        }
        printf("\n");
    }
    return 0;
}