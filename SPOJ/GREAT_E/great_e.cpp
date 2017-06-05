#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
int ans;
bool visited[1001];
int g[1000], k, n;

void bfs(int k) {
    pair<int, ii> s;
    s.first = 0;
    s.second = ii(k, 0); 
    queue<pair<int, ii>> q;
    q.push(s);
    while(!q.empty()) {
        int sz = (int)q.size();
        for (int i = 0; i < sz; ++i) {
            pair<int, ii> a = q.front();
            visited[a.first] = true;
            q.pop();
            if (g[a.first] == 0)
            {
                ans = a.second.second;
                return;
            }
            int next1, next2;
            ii aux = a.second;
            if (aux.first && a.first + g[a.first] < n && !visited[a.first+g[a.first]]){
                pair<int, ii> b;
                b.first = a.first + g[a.first];
                b.second = ii(aux.first-1, aux.second);
                q.push(b);
            }
            else if (!visited[a.first+1])
            {
                pair<int, ii> b;
                b.first = a.first+1;
                b.second = ii(aux.first, aux.second+1);
                q.push(b);
            }
        }
        sz = q.size();
    }
}

int main() {
    int t, sc=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) 
            scanf("%d", &g[i]);
        ans = 0;
        memset(visited, 0, sizeof(visited));
        bfs(k);
        printf("Scenario #%d:\n", sc++);
        if (ans == n-1)
            printf("Teresa will skip all the strawberries");
        else
            printf("Teresa will skip %d strawberries\n", ans);
    }
    return 0;
}