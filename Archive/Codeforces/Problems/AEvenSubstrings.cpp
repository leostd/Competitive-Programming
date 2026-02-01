#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 65006

class AEvenSubstrings {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, a[N];
		string str;
		in >> n >> str;
		REP(i,n)
			a[i] = str[i] - '0';
		ll ans = 0;
		REP(i, n){
			if (a[i] % 2 == 0){
				ans += i+1;
			}
		}
		out << ans;

	}
};