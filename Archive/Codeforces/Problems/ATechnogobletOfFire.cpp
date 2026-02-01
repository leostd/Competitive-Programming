#include "../library/lib.hpp"
#include <iostream>
#define N 200
using namespace std;



class ATechnogobletOfFire {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n,m,k, x;
		int s[N], sch[N];
		vector<int> sc[N], co;
		in >> n >> m >> k;
		REP(i,n){
			in >> s[i];
		}
		REP(i,n){
			in >> x;
			sc[x].pb(s[i]);
			sch[i] = x;
		}
		REP(i,k){
			in >> x;
			co.pb(x);
		}
		int ans = 0;
		REP(i,k){
			int id = co[i]-1;
			int csch = sch[id];
			REP(j,n){
				if (sch[j] == csch && s[j] > s[id]){
					ans++;
					break;
				}
			}
		}
		out << ans;
	}
};