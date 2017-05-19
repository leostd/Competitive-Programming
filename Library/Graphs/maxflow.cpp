/*
	Implementación sencilla del algoritmo Edmonds-Karp para hallar el maximo flujo
	En un grafo dirigido
	Entrada:
		n, m, src, snk => n nodos, m aristas, fuente src, pozo snk
		x, y, c => arista de x a y con capacidad c
		Nodos enumerados de 1 a n
	Salida:
		Máximo flujo posible enviado desde la fuente src hasta el pozo snk

	NOTA: Maximo 100 nodos
	      Si hay una arista x -> y, no debe haber una arista y -> x
	      (Puede ser modificado para aceptar esto)
*/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 110;
vector<int> graph[MAXN]; //Grafo de la red de flujo
int cap[MAXN][MAXN]; //Capacidad de cada arista en la red residual
int p[MAXN]; //Padre de un nodo x en un camino
bool V[MAXN]; 
int mf_bfs(int src, int snk){
	memset(p, -1, sizeof(p));
	memset(V, false, sizeof(V));
	queue<int> q;
	q.push(src); V[src] = true;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(cur == snk) break;
		for(int i = 0; i < (int)graph[cur].size(); i++){
			int next = graph[cur][i];
			if(V[next]) continue;
			if(cap[cur][next] == 0) continue;
			V[next] = true;
			p[next] = cur;
			q.push(next);
		}
	}

	int cur = snk, prev;
	if(p[cur] == -1) return 0;
	int flow = INF;
	/* Augmenting Path encontrado */
	while(p[cur] != -1){
		prev = p[cur];
		flow = min(flow, cap[prev][cur]);
		cur = prev;
	}
	cur = snk;
	while(p[cur] != -1){
		prev = p[cur];
		cap[prev][cur] -= flow;
		cap[cur][prev] += flow;
		cur = prev;
	}
	return flow;
}
int maxflow(int src, int snk){
	int flow = 0, f;
	while(true){
		f = mf_bfs(src, snk);
		if(f == 0) break;
		flow += f;
	}
	return flow;
}
void addEdge(int x, int y, int c){
	graph[x].push_back(y); graph[y].push_back(x);
	cap[x][y] = c; cap[y][x] = 0;
}
int main(){
	int n, m, src, snk;
	scanf("%d %d %d %d", &n, &m, &src, &snk);
	for(int i = 0; i < m; i++){
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		addEdge(x, y, c);
	}
	printf("%d\n", maxflow(src, snk));
	return 0;
}