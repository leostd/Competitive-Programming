/*
	LCA - Lowest Common Ancestor
	Input - Arbol de n nodos y Q Queries
	Output - Por cada Query (u,v) obtiene el LCA entre ambos nodos u,v
	(Raiz del arbol - Nodo 0)
	Complejidad - Preprocesamiento O(n log n), Query O(log n)
*/
#include <bits/stdc++.h>
#define pb push_back
#define VI vector<int>
using namespace std;
const int MAXN = 100010;
const int LOG = 17;
int PARENT[MAXN],
	depth[MAXN],
	p[LOG][MAXN];
VI g[MAXN];
int n, q;
void dfs(int node, int parent, int d){
	PARENT[node] = parent;
	depth[node] = d;
	for(int i=0; i<(int)g[node].size(); i++){
		int next = g[node][i];
		if(next==parent) continue;
		dfs(next,node,d+1);
	}
}
void pre(){
	for(int i=0; i<n; i++) p[0][i] = PARENT[i];
	for(int i=1; i<LOG; i++){
		for(int j=0; j<n; j++){
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}
}
int lca(int u, int v){
	if(depth[u] > depth[v]) swap(u,v);
	int logi = 0;
	for(logi=0; (1<<logi) <= depth[v]; logi++);
	logi--;
	for(int i=logi; i>=0; i--){
		if(depth[v] - (1<<i) >= depth[u]) v = p[i][v];
	}
	if(u==v) return u;
	for(int i=logi; i>=0; i--){
		if(p[i][u]!=p[i][v]){
			u = p[i][u];
			v = p[i][v];
		}
	}
	return PARENT[u];
}
int main(){
	int u, v;
	scanf("%d %d", &n, &q);
	for(int i=0; i<n-1; i++){
		scanf("%d %d", &u, &v);
		u--; v--;
		g[u].pb(v); g[v].pb(u);
	}
	dfs(0,0,0);
	pre();
	while(q--){
		scanf("%d %d", &u, &v);
		u--; v--;
		printf("%d\n", lca(u,v)+1);
	}
	return 0;
}