#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define FOR(i, j, k, inc) for(int i = j; i < k; i += inc)
#define SCD1(a) scanf("%d", &a)
#define SCD2(a, b) scanf("%d %d", &a, &b)
#define SCD3(a, b, c) scanf("%d %d %d", &a, &b, &c)
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi g[2005], tg[2005], ordering;
int dfs_num[2005];
int n, m, src, dst, way, scc;
void kosaraju(int s, int pass){
    dfs_num[s] = 1;
    vi al = (pass == 1) ? g[s] : tg[s];
    for(int i = 0; i < al.size(); i++){
        if (dfs_num[al[i]] == -1)
            kosaraju(al[i], pass);
    }
    ordering.push_back(s);
}

int main(){
    while(SCD2(n, m), n || m){
        fill(g, g+2005, vi());
        fill(tg, tg+2005, vi());
        scc = 0;
        for (int i = 0; i < m; i++){
            SCD3(src, dst, way);
            g[src].push_back(dst);
            tg[dst].push_back(src);
            if (way == 2){
                g[dst].push_back(src);
                tg[src].push_back(dst);
            }
        }
        ordering.clear();
        memset(dfs_num, -1, sizeof(dfs_num));
        for(int i = 1; i <= n; i++){
            if (dfs_num[i] == -1)
                kosaraju(i, 1);
        }
        memset(dfs_num, -1, sizeof(dfs_num));
        for(int i = n-1; i > 0; i--){
            if (dfs_num[ordering[i]] == -1)
            {
                scc++;
                kosaraju(ordering[i], 2);
            }
        }
        printf("%d\n", scc == 1? 1 : 0);
    }
    
    return 0;
}