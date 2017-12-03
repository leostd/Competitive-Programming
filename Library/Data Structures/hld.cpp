/*
	HLD - Heavy Light Decomposition
	Realiza la Heavy Light Decomposition de un arbol dado.
	En esta implementacion se toman en cuenta valores en nodos.
	Caso de ejemplo, Range Minimum Query
	Input - Arbol de n nodos, cada nodo con un valor asociado. Q queries (qi,u,v)
		Query qi = 0, obtener valor minimo en el camino de u a v
		Query qi = 1, cambiar el valor asociado al nodo u por v
	Output - Respuestas para qi = 0
	Utiliza LCA y Segment Tree
	Complejidad: Preprocesamiento O(n log n), Query O(log n)
*/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
#define VI vector<int>
using namespace std;
const int MAXN = 100010;
const int LOG = 17;
int PARENT[MAXN],
	depth[MAXN],
	sz[MAXN],
	head[MAXN],
	belongs[MAXN],
	schild[MAXN],
	A[MAXN],
	id[MAXN],
	p[LOG][MAXN],
	tag[MAXN];
VI g[MAXN];
int st[4*MAXN]; //Segment Tree
void init(int node, int li, int ls){
	if(li==ls){
		st[node] = A[li];
	}else{
		int mid = (li+ls)/2;
		init(2*node, li, mid);
		init(2*node+1, mid+1, ls);
		st[node] = min(st[2*node], st[2*node+1]);
	}
}
int query(int node, int li, int ls, int i, int j){
	if(i>ls || j<li) return INF;
	if(li>=i && ls<=j) return st[node];
	int mid = (li+ls)/2;
	int left = query(2*node, li, mid, i, j),
		right = query(2*node+1, mid+1, ls, i, j);
	return min(left, right);
}
void update(int node, int li, int ls, int i, int j, int v){
	if(i>ls || j<li) return;
	if(li>=i && ls<=j){
		st[node] = v;
		return;
	}
	int mid = (li+ls)/2;
	update(2*node, li, mid, i, j, v);
	update(2*node+1, mid+1, ls, i, j, v);
	st[node] = min(st[2*node], st[2*node+1]);
}
int chains, n, q, ind;
void dfs(int node, int parent, int d){
	PARENT[node] = parent;
	depth[node] = d;
	sz[node] = 1;
	schild[node] = -1;
	for(int i=0; i<(int)g[node].size(); i++){
		int next = g[node][i];
		if(next==parent) continue;
		dfs(next,node,d+1);
		sz[node]+=sz[next];
		if(schild[node]==-1 || sz[schild[node]] < sz[next]) schild[node] = next;
	}
}
void hld(int node, int parent, int curchain){
	if(head[curchain]==-1) head[curchain] = node;
	belongs[node] = curchain;
	id[node] = ind;
	A[ind] = tag[node];
	ind++;
	if(schild[node]!=-1) hld(schild[node], node, curchain);
	for(int i=0; i<(int)g[node].size(); i++){
		int next = g[node][i];
		if(next==schild[node] || next==parent) continue;
		hld(next, node, ++chains);
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
int query2(int u, int v){
	int ans = INF;
	while(true){
		if(belongs[u]==belongs[v]){
			ans = min(ans, query(1, 0, ind-1, id[u], id[v]));
			return ans;
		}else{
			int H = head[belongs[v]];
			ans = min(ans, query(1, 0, ind-1, id[H], id[v]));
			v = PARENT[H];
		}
	}
}
int query1(int u, int v){
	int LCA = lca(u,v);
	return min(query2(LCA,u), query2(LCA,v));
}
int main(){
	scanf("%d %d", &n, &q);
	for(int i=0; i<n; i++) scanf("%d", &tag[i]);
	for(int i=0; i<n-1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		g[x].pb(y); g[y].pb(x);
	}
	dfs(0,0,0);
	ind = chains = 0;
	memset(head, -1, sizeof(head));
	hld(0,-1,0);
	init(1, 0, ind-1);
	pre();
	while(q--){
		int qi, u, v;
		scanf("%d %d %d", &qi, &u, &v);
		if(qi==0) printf("%d\n", query1(u-1, v-1));
		else update(1, 0, ind-1, id[u-1], id[u-1], v);
	}
	return 0;
}