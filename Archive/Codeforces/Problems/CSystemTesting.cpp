#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CSystemTesting {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k, x, m = 0;
		in >> n >> k;
		queue<int> q;
		REP(i,n)
			in >> x, q.push(x);
		int d;
		vector<int> rs,ts;
		int t = 0, ans = 0;
		do{
			if (!q.empty()){
				int aux = k - rs.size();
				REP(i,aux){
					x = q.front();
					q.pop();
					rs.pb(x);
					ts.pb(t);
				}
			}
			sort(rs.begin(), rs.end());
			d = round(100*(float)m/(float)n);
			REP(i,rs.size()){
				if (d == rs[i]+1)
					ans++;
			}
			t += rs[0];
			REP(i,rs.size()){
			    rs[i] = (rs[i] - (rs[i] - (t - ts[i])));
			}
			m++;
			rs.erase(rs.begin());
			ts.erase(ts.begin());
		}while(!q.empty() || !rs.empty());
		out << ans;
	}
};