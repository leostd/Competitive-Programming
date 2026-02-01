#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CEnergyDrinkCollector {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		int x, y;
		vector<pll> b;
		REP(i, n)
			in >> x >> y, b.pb(mp(x,y));
		sort(b.begin(), b.end());
		int i = 0;
		ll ans = 0;
		while(m){
			if (b[i].snd <= m){
				ans += b[i].fst * b[i].snd, m-=b[i].snd;
			}
			else
				ans += b[i].fst * m, m = 0;
			i++;
		}
		out << ans;
	}
};