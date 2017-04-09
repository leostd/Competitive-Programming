//UVa Tourist Guide solution
// Articulation points needed to solve and I added the bridge part
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int t, n, m, root, tc = 1;
map<string, int> indices;
map<int, string> cities;
string city, src, dst;
int parent[105], dfs_low[105], dfs_num[105], childs[105];
vi g[105];
vector<string> ap;

void dfs(int s){
    dfs_num[s] = dfs_low[s] = t++;
    vi al = g[s];
    bool flag = false;
    for (int i = 0; i < (int)al.size(); i++){
        if (dfs_num[al[i]] == -1){ // unvisited
            parent[al[i]] = s;
            childs[s]++;
            dfs(al[i]);
            if (dfs_num[s] <= dfs_low[al[i]]) // is an articulation point
                flag = true;
            dfs_low[s] = min(dfs_low[s], dfs_low[al[i]]);
        }
        else if (al[i] != parent[s])
            dfs_low[s] = min(dfs_low[s], dfs_num[al[i]]);
    }

    if ((root == s && childs[s] >= 2) || (root != s && flag))
        ap.push_back(cities[s]);
}

int main(){
    while(scanf("%d", &n), n){
        t = 0;
        fill(g, g+105, vi());
        memset(parent, 0, sizeof(parent));
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(childs, 0, sizeof(childs));
        ap.clear();
        indices.clear();
        for (int i = 0; i < n; i++){
            cin >> city;
            indices[city] = i;
            cities[i] = city;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            cin >> src >> dst;
            g[indices[src]].push_back(indices[dst]);
            g[indices[dst]].push_back(indices[src]);
        }
        for (int i = 0; i < n; i++){
            if (dfs_num[i] == -1)
            root = i;
            t=0;
            dfs(i);
        }
        if (tc > 1)
            printf("\n");
        printf("City map #%d: %lu camera(s) found\n", tc++, ap.size());
        sort(ap.begin(), ap.end());
        for (int i = 0; i < ap.size(); i++)
            cout << ap[i] << "\n";
        
    }
    return 0;
}