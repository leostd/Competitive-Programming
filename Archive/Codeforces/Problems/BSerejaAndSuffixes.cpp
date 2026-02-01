#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BSerejaAndSuffixes {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		vector<int> v, ans;
		map<int, int> cnt;
		int x;
		REP(i, n){
		    in >> x;
		    v.pb(x);
		    cnt[x]++;
		}
		REP(i,n){
		    ans.pb((int)cnt.size());
		    cnt[v[i]]--;
		    if (cnt[v[i]] == 0)
		        cnt.erase(v[i]);
		}
		REP(i,m){
		    in >> x;
		    out << ans[x-1] << "\n";
		}

	}
};