#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
map<string,int> M;
pii D[4510];
int n, m, id;
char buf[1100];
int T[110];
VI g[100010];
VI cost[100010];
class node{
public:
	int cur, steps, cost;
	node(){}
	node(int a, int b, int c){
		cur = a; steps = b;cost = c;
	}
	bool operator<(const node& other) const{
		if(other.steps != steps) return other.steps < steps;
		return other.cost < cost;
	}
};
void dijkstra(int start){
	priority_queue<node> pq;
	pq.push(node(start, 0, 0));
	for(int i = 0; i < id; i++) D[i] = mp(INF,INF);
	D[0] = mp(0,0);
	while(!pq.empty()){
		node aux = pq.top(); pq.pop();
		int cur = aux.cur, c = aux.cost, s = aux.steps;
		for(int i = 0; i < (int)g[cur].size(); i++){
			int next = g[cur][i], nc = cost[cur][i];
			if(D[next] <= mp(s+1, nc)) continue;
			D[next] = mp(s+1, nc);
			pq.push(node(next, s+1, nc));
		}
	}
}
int main(){
	M["English"] = 0;
	id = 1;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", buf);
		string str = buf;
		if(M.count(str) == 0) M[str] = id++;
		T[i] = M[str];
	}
	for(int i = 0; i < m; i++){
		int u, v, c;
		string A, B;
		scanf("%s", buf); A = buf;
		if(M.count(A) == 0) M[A] = id++;
		scanf("%s", buf); B = buf;
		if(M.count(B) == 0) M[B] = id++;
		u = M[A]; v = M[B];
		scanf("%d", &c);
		g[u].pb(v); cost[u].pb(c);
		g[v].pb(u); cost[v].pb(c);
	}
	dijkstra(0);
	int total = 0;
	for(int i = 0; i < n; i++){
		if(D[T[i]].first == INF){
			printf("Impossible\n");
			return 0;
		}
		total += D[T[i]].second;
	}
	printf("%d\n", total);
	return 0;
}