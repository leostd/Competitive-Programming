#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AReconnaissance2 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, x;
		in >> n;
		vector<int> ns;
		REP(i,n){
			in >> x;
			ns.pb(x);
		}
		int a, b, diff = 0x3f3f3f3f;
		REP(i,n-1){
			if (abs(ns[i] - ns[i+1]) < diff){
				diff = abs(ns[i] - ns[i+1]);
				a = i+1, b = i+2;
			}
		}
		if (diff > abs(ns[0] - ns[n-1])){
			diff = abs(ns[0] - ns[n-1]);
			a = n;
			b = 1;
		}
		out << a << " " << b;
	}
};