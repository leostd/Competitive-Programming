#include "../library/lib.hpp"
#include <iostream>
using namespace std;

int g[6][6];
ll ans;

ll f(vector<ll> v){
	ll a, b, c, d;
	a = (g[v[0]][v[1]] + g[v[1]][v[0]] + g[v[2]][v[3]] + g[v[3]][v[2]]);
	b = (g[v[1]][v[2]] + g[v[2]][v[1]] + g[v[3]][v[4]] + g[v[4]][v[3]]);
	c = g[v[2]][v[3]] + g[v[3]][v[2]];
	d = g[v[3]][v[4]] + g[v[4]][v[3]];
	return  a + b + c + d;
}

void bt(vector<ll> &s, bool *mark){
	if (s.size() == 5)
		ans = max(ans, f(s));
	else{
		REP(i,5){
			if(mark[i])
				continue;
			mark[i] = true;
			s.pb(i+1);
			bt(s, mark);
			s.pop_back();
			mark[i] = false;
		}
	}
}

class BShowerLine {
public:
	void solve(std::istream& in, std::ostream& out) {
		RE(i,5){
			RE(j,5){
				in >> g[i][j];
			}
		}
		ans = 0;
		vector<ll> s;
		bool mark[6];
		memset(mark, 0, sizeof(mark));
		bt(s, mark);
		out << ans;

	}
};