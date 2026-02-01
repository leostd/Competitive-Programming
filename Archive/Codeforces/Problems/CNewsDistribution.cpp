#include "../library/lib.hpp"
#include <iostream>
using namespace std;


const int MAXN = 500001;
int parent[MAXN];
int sz[MAXN];

int my_find(int x){
	if (parent[x] == x)
		return x;
	return parent[x] = my_find(parent[x]);
}

void my_union(int x, int y){
	int rootx = my_find(x);
	int rooty = my_find(y);
	if (rootx != rooty){
		parent[rooty] = rootx;
		sz[rootx] += sz[rooty];
	}
}

class CNewsDistribution {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		
		in >> n >> m;
		int x;
		for(int i = 1; i <= n; i++)
			parent[i] = i;
		fill(sz, sz+n+1, 1);
		for(int i = 0; i < m; i++){
			int k;
			in >> k;
			if (k > 0)
				in >> x;
			int y;
			for (int j = 1; j < k; j++){
				in >> y;
				my_union(x,y);
			}
		}
		for(int i = 1; i <= n; i++){
			out << sz[my_find(i)] << " ";
		}
	}
};