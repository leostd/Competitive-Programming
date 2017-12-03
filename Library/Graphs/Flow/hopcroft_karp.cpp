/*
	Algoritmo Hopcroft-Karp
	Resuelve el Maximum Bipartite Matching en O(sqrt(V)*E)
	N vertices del lado izquierdo, enumerados de 1 a N
	M vertices del lado derecho, enumerados de N+1 a N + M
*/
#include <bits/stdc++.h>
#define pb push_back
#define VI vector<int>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000;
int match[2*MAXN+10], dist[2*MAXN+10];
int n, m, e;
VI g[2*MAXN+10];
bool Free[2*MAXN+10];
bool bfs(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!match[i]){
			q.push(i);
			dist[i] = 0;
		}else dist[i] = INF;
	}
	dist[0] = INF;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int i = 0; i < (int)g[cur].size(); i++){
			int next = g[cur][i];
			if(dist[match[next]] == INF){
				dist[match[next]] = dist[cur] + 1;
				q.push(match[next]);
			}
		}
	}
	return dist[0] != INF;
}
bool dfs(int cur){
	if(!cur) return true;
	for(int i = 0; i < (int)g[cur].size(); i++){
		int next = g[cur][i];
		if(dist[match[next]] == dist[cur] + 1 && dfs(match[next])){
			match[next] = cur;
			match[cur] = next;
			return true;
		}
	}
	dist[cur] = INF;
	return false;
}
int bpm(){
	int matching = 0;
	while(bfs()){
		for(int i = 1; i <= n; i++){
			if(!match[i] && dfs(i)){
				matching++;
			}
		}
	}
	return matching;
}
void init(){
	for(int i = 0; i <= n + m; i++){
		dist[i] = INF;
		Free[i] = false;
		match[i] = 0;
		g[i].clear();
	}
}
int main(){
	scanf("%d %d %d", &n, &m, &e);
	init();
	for(int i = 0; i < e; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].pb(y + n);
	}

	printf("%d\n", bpm());
	return 0;
}