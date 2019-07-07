#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BEffectiveApproach {
public:
	void solve(std::istream& in, std::ostream& out) {
		pii p[100005];
		int n, m, x, q, a[100005];
		memset(a, -1, sizeof(a));
		in >> n;
		REP(i,n){
			in >> x;
			if (a[x] == -1){
				p[x].first = p[x].second = i+1;
				a[x] = 1;
			}
			else{
				p[x].second = i+1;
			}
		}
		in >> x;
		ll y,z;
		y = z = 0;
		memset(a, -1, sizeof(a));
		REP(i, x){
			in >> q;
			y += p[q].first;
			z += n - p[q].second + 1;
		}
		out << y << " " << z;
	}
};