#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ATL {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m, x;
		in >> n >> m;
		vector<int> w, c, pv;
		REP(i,n)
			in >> x, c.pb(x), pv.pb(2*x);
		REP(i,m)
			in >> x, w.pb(x);
		sort(c.begin(), c.end());
		sort(w.begin(), w.end());
		pv.pb(c.back());
		sort(pv.begin(), pv.end());
		REP(i, pv.size()){
            int v = pv[i];
            if (v < c.back())
                continue;
            if (w[0] <= v){
                out << -1;
                return;
            }
            bool flag = false;
            REP(i, n){
                if (2*c[i] <= v){
                    flag = true;
                    break;
                }
            }
            if(flag){
                out << v;
                return;
            }
		}

	}
};