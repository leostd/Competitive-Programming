#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class APerfectPermutation {
public:
	void solve(std::istream& in, std::ostream& out) {
		vector<int> a;
		int n;
		in >> n;
		if (n % 2 != 0){
		    out << -1;
		    return;
		}
		for(int i = 1; i<=n; i+=2){
			a.pb(i+1);
			a.pb(i);
		}
		REP(i, a.size()){
		    out << a[i] << " ";
		}
	}
};