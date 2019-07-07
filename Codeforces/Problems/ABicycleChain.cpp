#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ABicycleChain {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n;
		int a[60], b[60];
		map<int,int> mp;
		REP(i,n)
			in >> a[i];
		in >> m;
		REP(i,m)
			in >> b[i];
		int ans = -1;
		REP(i,n){
			REP(j, m){
				if (b[j] % a[i] == 0){
					if (ans < b[j]/a[i]){
						ans = b[j]/a[i];
						mp[ans]++;	
					}
					else if (ans == b[j]/a[i])
						mp[ans]++;
				}
			}
		}
		out << mp[ans];

	}
};