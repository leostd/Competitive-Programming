#include "../library/lib.hpp"
#include <iostream>
using namespace std;

struct t {
	int a,b,c;
};

int ans[1010];

bool nope(t x){
	for(int i = x.b; i < x.c; i++){
		if (ans[i] > ans[i+1])
			return false;
	}
	return true;
}

class CVasyaAndArray {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m, a[1010];
		in >> n >> m;
		vector<t> ts;
		memset(a, 0,sizeof(a));
		REP(i, m){
			t x;
			in >> x.a >> x.b >> x.c;
			if (x.a){
				a[x.b]++;
				a[x.c]--;
			}
			else
			 ts.pb(x);
		}

		for(int i = 1; i <=n; i++)
			a[i] += a[i-1];
		int v = 1, k = 2*n;
		memset(ans, 0, sizeof(ans));
		while(v <= n){
			int w = 0;
			while(a[w+v]){
				w++;
			}
			k--;
			for(int i = 0; i <= w; i++)
				ans[v+i] = k;
			v += w+1;
		}
		REP(i, ts.size()){
			if (nope(ts[i])){
				out << "NO";
				return;
			}

		}
		out << "YES\n";
		RE(i, n)
			out << ans[i] << " ";
	}
};