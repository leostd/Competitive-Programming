/*
	Implementación del Maximum Bipartite Matching con DFS
	Entrada:
		L, R, m => Grafo bipartito, L nodos en una partición y R nodos en la otra partición
		Nodos de la primera partición enumerados de 1 a L
		Nodos de la segunda partición enumerados de L + 1 a R
		m aristas x - y
	Salida:
		Bipartite Matching de máxima cardinalidad
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
vector<int> graph[MAXN];
int match[MAXN];
bool V[MAXN];
bool matching(int cur){
	if(cur == -1) return true;
	V[cur] = true;
	for(int i = 0; i < (int)graph[cur].size(); i++){
		int next = graph[cur][i];
		if(V[next]) continue;
		V[next] = true;
		if(matching(match[next])){
			match[next] = cur;
			match[cur] = next;
			return true;
		}
	}
	return false;
}
int maximum_bipartite_matching(int L, int R){
	memset(match, -1, sizeof(match));
	int flow = 0;
	for(int i = 1; i <= L; i++){
		for(int j = 1; j <= L + R; j++) V[j] = false;
		flow += matching(i);
	}	
	return flow;
}
int main(){
	int L, R, m;
	scanf("%d %d %d", &L, &R, &m);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	printf("%d\n", maximum_bipartite_matching(L, R));
	return 0;
}