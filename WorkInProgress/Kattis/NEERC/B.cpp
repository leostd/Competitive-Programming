#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(2,1));

    auto dfs = [&](auto && self, int u, int p)->void{
        if(adj[u].size() == 1)
            return;

        vector<pair<int,int>> baj;

        for(auto v : adj[u]){
            if(v != p){
                self(self, v, u);
                dp[u][1] *= (dp[v][0] + dp[v][1]);
                dp[u][1] %= MOD;
                baj.push_back({dp[v][0], dp[v][1]});
                if(baj.size() > 1)
                    baj[baj.size()-1] *= baj[(baj.size()-2)], baj[(baj.size()-1)] %= MOD;
            }
        }
        for(int i = 0; i < adj[u].size()-1; i++){
            dp[u][0] *= (i ? baj[i-1].first + baj[i-1].second : 1) * (i == n-1 ? 1 : baj[i+1].first + baj[i+1].second);
            dp[u][0] %= MOD;
            dp[u][0] *= dp[i][0];
            dp[u][0] %= MOD;
        }
    };

    dfs(dfs, 0, -1);
    cout << dp[0][1] << endl;
}
