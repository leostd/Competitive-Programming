#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ASupercentralPoint {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		vector<pii> xs, ys;
		pii a;
		in >> n;
		REP(i,n){
			in >> a.first >> a.second;
			xs.pb(a), ys.pb(mp(a.second, a.first));
		}
		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());
		int ans = 0;
		REP(i,n){
			int x = xs[i].first;
			int y = xs[i].second;
			bool left, right, up, down;
			left = right = up = down = false;
			REP(j,n){
				if (j == i)
					continue;
				if (x == xs[j].first && y < xs[j].second)
					up = true;
				else if (x == xs[j].first && y > xs[j].second)
					down = true;
				else if (y == xs[j].second && x > xs[j].first)
					left = true;
				else if (y == xs[j].second && x < xs[j].first)
					right = true;
			}
			ans += (right && left && up && down);

		}
		out << ans;
	}
};