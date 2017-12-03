/*
	Algoritmo de Dinic
	Obtiene el Max Flow de una red con complejidad O(n^2 m)
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int INF = 0x3f3f3f3f;	
const int MAXN = 1000;
class edge{
public:
	int u, v, flow, cap, rev;
	edge(){}
	edge(int a, int b, int c, int d, int e){
		u = a; v = b; flow = c; cap = d; rev = e;
	}
};
vector<edge> g[MAXN+10];
int n, m, s, t;
void addEdge(int u, int v, int c){
	g[u].pb(edge(u, v, 0, c, (int)g[v].size()));
	g[v].pb(edge(v, u, 0, 0, (int)g[u].size()-1));
}
int p[MAXN+10];
int d[MAXN+10];
bool bfs(){
	queue<int> q;
	q.push(s);
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[s] = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int i = 0; i < (int)g[cur].size(); i++){
			int next = g[cur][i].v;
			if(d[next] != INF || g[cur][i].flow == g[cur][i].cap) continue;
			d[next] = d[cur] + 1;
			q.push(next);
		}
	}
	return d[t] != INF;
}
int dfs(int cur, int pushed){
	if(!pushed) return 0;
	if(cur == t) return pushed;
	for(; p[cur] < (int)g[cur].size(); p[cur]++){
		int next = g[cur][p[cur]].v;
		if(d[next] != d[cur] + 1) continue;
		int psh = dfs(next, min(pushed, g[cur][p[cur]].cap - g[cur][p[cur]].flow));
		if(psh){
			g[cur][p[cur]].flow += psh;
			g[next][g[cur][p[cur]].rev].flow -= psh;
			return psh;
		}
	}
	return 0;
}
int dinic(){
	int flow = 0;
	while(bfs()){
		for(int i = 1; i <= n; i++) p[i] = 0;
		while(int pushed = dfs(s, INF)) flow += pushed;
	}
	return flow;
}
int main(){
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i = 0; i < m; i++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		addEdge(u, v, c);
	}
	printf("%d\n", dinic());
	return 0;
}