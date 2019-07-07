#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AShooshunsAndSequence {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k;
		in >> n >> k;
		vector<int> a;
		map<int, int> mp;
		int x;
		REP(i,n)
		    in >> x, a.pb(x), mp[x]++;
		k--;
		int ans = -1, first=0;
        REP(i, n){
            int cur = a[k+i];
            if(mp[cur] == n){
                ans = i;
                break;
            }
            mp[cur]++;
            int firstelem = a[first++];
            mp[firstelem]--;
            a.pb(cur);
        }
        out << ans;
	}
};