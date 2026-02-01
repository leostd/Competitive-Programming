#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi g[201];
int n, l, color[201];
bool flag; // black = 1



void dfs(int s, bool c){
	color[s] = c;
	for (int i = 0; i < g[s].size(); i++){
		if (color[g[s][i]] == c){
			flag = false;
			return;
		}
		if (color[g[s][i]] == -1)
			dfs(g[s][i], !c);
	}
}

void init(){
	for (int i = 0; i < 201; i++)
		g[i] = vi();
}
int main(){
	int a, b;
	while(scanf("%d", &n), n){
		scanf("%d", &l);
		init();
		memset(color, -1, sizeof(color));
		for (int i = 0; i < l; i++){
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		flag = true;
		dfs(0, 1);
		printf("%s\n", flag ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}
	return 0;
}