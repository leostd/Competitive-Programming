#include <bits/stdc++.h>
#define N 100000
using namespace std;

typedef pair<int, int> ii;


int p[N], dsu_size;
vector<int, ii> g, ans; // edges

int dsu_find(int x){
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}

void dsu_union(int x, int y){
    int rootx = dsu_find(x);
    int rooty = dsu_find(y);
    if (rootx != rooty){
        p[rooty] = rootx;
        dsu_size++;
    }
}

void dsu_init(int n){
    dsu_size = n;
    for(int i = 0; i < n; i++)
        p[i] = i;
}

int main(){
    int n;
    scanf("%d", &n);
    dsu_init(n);
    g.assign(n+1);
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &g[i].second.first, &g[i].second.second, &g[i].first) // x y weight
    }
    sort(g.begin(), g.end());
    int mst_weight = 0;
    for (int i = 0; i < n; i++){
        int a = g[i].second.first, b = g[i].second.second, c = g[i].first;
        if (dsu_find(a) != dsu_find(b)){
            ans.push_back(c,ii(a,b));
            mst_weight += c;
        }
        if (ans.size() == n-1) break; //
    }
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d %d\n", ans[i].second.first, ans[i].second.second, ans[i].first);
    return 0;
}