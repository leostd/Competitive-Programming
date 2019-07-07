#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CPlaylist {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k;
		in >> n >> k;
		vector<pii> a;
		pii x;
		REP(i,n)
			in >> x.snd >> x.fst, a.pb(x);
		sort(a.begin(), a.end(), greater<pii>());
		set<pii> s;
		ll sum, ans;
		sum = ans = 0;
		REP(i, n){
			int b = a[i].fst;
			int l = a[i].snd;
			s.insert(pii(l,i));
			sum += l;
			while(s.size() > k){
				auto it = s.begin();
				sum -= it->fst;
				s.erase(it);
			}
			ans = max(ans, sum*b);
		}
		out << ans;
	}
};