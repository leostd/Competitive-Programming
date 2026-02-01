#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BMakeThemEqual {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		int a[101], b[101];
		set<int> ds;
		in >> n;
		REP(i,n)
			in >> a[i], ds.insert(a[i]);
		if (ds.size() > 3){

		}
		sort(a, a+n);
		int d;
		FOR(x,1,100){
			REP(i,n)
				b[i] = a[i];
			d = -1;
			REP(i, n){
				d = abs(x - b[i]);
				REP(j, n){

				}
			}
		}

	}
};