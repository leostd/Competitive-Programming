#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ALittleElephantAndRozdil {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll n, x, y, mn = 0x3f3f3f3f, ans;
		map<int,int> a;
		in >> n;
		REP(i,n){
			in >> x;
			if (x < mn){
				mn = x;
				ans = i+1;
			}
			a[x]++;
		}
		if (a[mn] > 1){
			out << "Still Rozdil";
		}
		else
			out << ans;

	}
};