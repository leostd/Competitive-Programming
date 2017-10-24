#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vii js[200001];
int m, n;

int main(){
	while(scanf("%d %d", &m, &n), m || n){
		int x,y,z;
		for (int i = 0; i < n; i++){
			scanf("%d %d %d", &x, &y, &z);
			js[x].push_back(ii(y, z));
			js[y].push_back(ii(x, z));
		}
		
	}
}