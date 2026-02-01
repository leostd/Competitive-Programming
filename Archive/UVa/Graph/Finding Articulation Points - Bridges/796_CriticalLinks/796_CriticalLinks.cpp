#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 10000;
int n, k, counter, a, b;
int dfs_low[MAXN], dfs_num[MAXN], parent[MAXN];
vector<ii> bridges;
vi g[100];

void brs(int s){
    dfs_low[s] = dfs_num[s] = counter++;
    vi al = g[s];
    for (int i = 0; i < al.size(); i++){
        if (dfs_num[al[i]] == -1){
            parent[al[i]] = s;
            brs(al[i]);
            if (dfs_low[al[i]] > dfs_num[s])
                bridges.push_back(ii(min(al[i], s), max(al[i], s)));
            dfs_low[s] = min(dfs_low[al[i]], dfs_low[s]);
        }
        else if (al[i] != parent[s])
            dfs_low[s] = min(dfs_num[al[i]], dfs_low[s]);
    }
}

int main()
{
    while(scanf("%d", &n) != EOF){
        counter = 0;
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(parent, 0, sizeof(parent));
        bridges.clear();
        fill(g, g+n, vi());
        for (int i = 0; i < n; i++){
            scanf("%d (%d)", &a, &k);
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &b);
                g[a].push_back(b);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (dfs_num[i] == -1)
                brs(i);
        }
        sort(bridges.begin(), bridges.end());
        printf("%d critical links\n", (int)bridges.size());
        for(int i = 0; i < bridges.size(); i++){
            printf("%d - %d\n", bridges[i].first, bridges[i].second);
        }
        printf("\n");
    }
    return 0;
}