#include <bits/stdc++.h>
#define N 10011
using namespace std;

typedef vector<int> vi;

vi graph[N];
int match[N];
int t,n, idx, jdx;
bool V[N];
int L[200], R[200], l[200], r[200];

bool matching(int cur){
    if (cur == -1) return true;
    V[cur] = true;
    for (int i = 0; i < (int)graph[cur].size(); ++i){
        int next = graph[cur][i];
        if (V[next] == true) continue;
        V[next] = true;
        if (matching(match[next])){
            match[next] = cur;
            match[cur] = next;
            return true;
        }
    }
    return false;
}

int max_bipartite_matching() {
    memset(match, -1, sizeof(match));
    int flow = 0;
    for (int i = 0; i < idx; ++i) {
        memset(V, 0, sizeof(V));
        flow += matching(L[i]);
    }
    return flow;
}

int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int a, b, nodes;
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        idx = jdx = nodes = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            if (l[a]==-1) {
                l[a] = nodes;
                L[idx++] = nodes++;
            }
            if(r[b]==-1){
                r[b] = nodes;
                R[jdx++] = nodes++;
            }
            graph[l[a]].push_back(r[b]);
            graph[r[b]].push_back(l[a]);
        }
        int ans = max_bipartite_matching();
        printf("%d\n", ans);
        for (int i = 0; i < 10010; ++i)
            graph[i].clear();
    }
    return 0;
}