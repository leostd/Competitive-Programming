#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define sqr(x) ((x)*(x))
using namespace std;

typedef pair<int,int> ii;

int xmov[4] = {1,-1,0, 0};
int ymov[4] = {0, 0, -1, 1};


class CConnect {
public:
    bool bfs(ii src, ii tgt, int (&g)[60][60], vector<ii> &rs, int n){
        ii s = src;
        rs.push_back(src);
        bool visited[60][60];
        queue<ii> q;
        memset(visited, 0, sizeof(visited));
        q.push(s);
        visited[src.first][src.second] = 1;
        while(!q.empty()){
            ii a = q.front();
            q.pop();
            for (int i = 0; i < 4; i++){
                int r = xmov[i] + a.first;
                int c = ymov[i] + a.second;
                if (r > 0 && r <= n && c > 0 && c <= n && !visited[r][c] && g[r][c] == 0){
                    q.push(ii(r, c));
                    rs.push_back(ii(r,c));
                    visited[r][c] = 1;
                    if (r == tgt.first && c == tgt.second)
                        return true;
                }
            }
        }
        return false;
    }
	void solve(std::istream& in, std::ostream& out) {
		int n;
		int g[60][60];
		string s;
		in >> n;
		ii src, tgt;
		in >> src.first >> src.second >> tgt.first >> tgt.second;
		for(int i = 1; i <= n; i++){
		    in >> s;
		    for (int j = 0; j < n;j++){
		        g[i][j+1] = (s[j]) - '0';
		    }
		};
        // see if it's reacheable
        vector<ii> rs;
        bool reach = bfs(src, tgt, g, rs, n);
        if (reach){
            out << 0;
            return;
        }

        // if not, get the minimum cost
        vector<ii> ts;
        bfs(tgt, src, g, ts, n);

        long long ans = 0x3f3f3f3f;
        for (int i = 0; i < rs.size(); i++){
            for (int j = 0; j < ts.size(); j++){
                ans = min(ans, (long long)(sqr(rs[i].first - ts[j].first) + sqr(rs[i].second - ts[j].second)));
            }
        }
        out << ans;
	}
};