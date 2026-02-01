#include <iostream>
#include "../library/lib.hpp"
using namespace std;

class AYoungPhysicist {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, x, i, j;
		int a[3] = {0};
		in >> n;
		REP(i,n){
			REP(j,3){
				in >> x;
				a[j] += x;
			}
		}
		bool flag = true;
		REP(i,3)
			flag = flag && a[i]==0;
		out << (flag? "YES" : "NO");
	}
		
};