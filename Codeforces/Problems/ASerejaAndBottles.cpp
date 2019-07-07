#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ASerejaAndBottles {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, x, y, cnt[1001];
		memset(cnt, 0, sizeof(cnt));
		in >> n;
		vector<pii> s;
		REP(i, n)
			in >> x >> y, cnt[x]++, s.pb(mp(x,y));
		int ans = 0;
		REP(i, n){
			REP(j, n){
				if (j == i || s[j].fst == -1)
					continue;
				
				if (s[i].snd == s[j].fst)
					ans++, s[j].fst = -1;
			}
		}
		out << n-ans;

	}
};