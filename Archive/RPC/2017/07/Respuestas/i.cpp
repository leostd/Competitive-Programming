#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL long long
#define pb push_back
#define pii pair<LL,LL>
#define mp make_pair
using namespace std;
int cap[500][500];
VI g[500];
void addEdge(int u, int v, int c){
	g[u].pb(v);
	g[v].pb(u);
	cap[u][v] = c;
	cap[v][u] = 0;
}
int n, m, p;
int cat[5010];
int r[5010];
bool v[510];
int P[510];
int mf(int src, int snk){
	memset(P, -1, sizeof(P));
	memset(v, false, sizeof(v));
	queue<int> q;
	q.push(src);
	v[src] = true;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(cur == snk) break;
		for(int i = 0; i < (int)g[cur].size(); i++){
			int next = g[cur][i];
			if(v[next]) continue;
			if(cap[cur][next] == 0) continue;
			v[next] = true;
			q.push(next);
			P[next] = cur;
		}
	}
	if(!v[snk]) return 0;
	int flow = INF;
	int cur = snk, prev;
	while(P[cur] != -1){
		prev = P[cur];
		flow = min(flow, cap[prev][cur]);
		cur = prev;
	}
	cur = snk;
	while(P[cur] != -1){
		prev = P[cur];
		cap[prev][cur] -= flow;
		cap[cur][prev] += flow;
		cur = prev;
	}
	return flow;
}
int maxflow(int src, int snk){
	int flow = 0, f;
	while((f = mf(src,snk))) flow += f;
	return flow;
}
int main(){
	scanf("%d %d %d", &n, &m, &p);
	int src = 0, snk = n + m + p + 2;
	for(int i = 1; i <= n; i++){
		int t;
		scanf("%d", &t);
		for(int j = 0; j < t; j++){
			int ti;
			scanf("%d", &ti);
			addEdge(i, ti+n, 1);
		}
	}
	for(int i = 1; i <= p; i++){
		int l;
		scanf("%d", &l);
		for(int j = 0; j < l; j++){
			scanf("%d", &cat[j]);
			r[cat[j]] = i;
		}
		int c;
		scanf("%d", &c);
		for(int j = 0; j < l; j++) addEdge(cat[j]+n, i+n+m, 1);
		addEdge(i+n+m, snk, c);
	}
	for(int i = 1; i <= n; i++) addEdge(src, i, 1);
	for(int i = 1; i <= m; i++){
		if(!r[i]) addEdge(i+n,n+m+p+1, 1);
	}
	addEdge(n+m+p+1, snk, INF);
	printf("%d\n", maxflow(src,snk));
	return 0;
}