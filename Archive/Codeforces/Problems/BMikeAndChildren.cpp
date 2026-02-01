#include "../library/lib.hpp"
#include <iostream>
#define N 1005
using namespace std;

class BMikeAndChildren {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		int a[N];
		vector<pii> p;
		vector<int> sums;
		map<int, vector<pii>> m;
		in >> n;
		REP(i,n)
			in >> a[i];
		REP(i,n){
			FOR(j,i+1,n-1){
				sums.pb(a[i]+a[j]);
				m[*sums.rbegin()].pb(pii(i,j));
			}
		}
		int ans = 0;
		for(auto it = m.begin(); it != m.end(); ++it){
		    int uniques = 0;
		    set<int> s;
		    vector<pii> &v = it->second;
		    REP(i,v.size()){
		        if (s.count(v[i].first) == 0 && s.count(v[i].second) == 0){
		            uniques++;
		            s.insert(v[i].first);
		            s.insert(v[i].second);
		        }
		    }
		    ans = max(ans, uniques);
		}
		out << ans;
	}
};