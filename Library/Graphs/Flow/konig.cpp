/*
	König's Theorem
	Una vez encontrado el Bipartite Matching, se encuentra el MVC
	|MVC| = |MCBM|
	Recibe el arreglo Match, Match[i] = matching de i en el MCBM
	Obtiene los nodos pertenecientes al MVC mediante DFS
	MVC = (L ^ ~Z) U (R ^ Z)
*/
#include <bits/stdc++.h>
#define VI vector<int>
using namespace std;
const int MAXN = 10000;
int match[2*MAXN+10];
VI g[MAXN+10];
bool v[MAXN+10];
int n, m;
void dfs_konig(int cur){
	v[cur] = true;
	for(int i = 0; i < (int)g[cur].size(); i++){
		int next = g[cur][i];
		if(match[next] && !v[match[next]]){
			v[next] = true;
			dfs_konig(match[next]);
		}
	}
}
void solve(){
	for(int i = 1; i <= n; i++){
		if(!match[i] && !v[i]) dfs_konig(i);
	}
	for(int i = 1; i <= n; i++) v[i]^=1;
}