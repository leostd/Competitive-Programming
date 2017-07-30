#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
bool visited[10004];
int n, a, b, t, maxdepth, maxdepthidx;

void dfs(int s, int d){
	visited[s] = true;
	if (d > maxdepth){
		maxdepth = d;
		maxdepthidx = s;
	}
	for (int i = 0; i < g[s].size(); i++){
		if (!visited[g[s][i]]){
			dfs(g[s][i],d+1);
		}
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		g.clear();
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
			g.push_back(vi());
		for (int i=0; i < n-1; i++){
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		maxdepth = 1;
		maxdepthidx = 1;
		memset(visited, 0, sizeof(visited));
		dfs(1, 1);
		maxdepth = 1;
		memset(visited, 0, sizeof(visited));
		dfs(maxdepthidx,1);
		printf("%d\n", maxdepth);
	}
	return 0;
}