#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BPreparationForInternationalWomensDay {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k, x, ans = 0;
		in >> n >> k;
		vector<int> ms(101, 0), s;
		REP(i,n){
			in >> x;
			ms[x%k]++;
		}
		REP(i, k){
			FOR(j, i, k-1){
				int q;
				if ((i+j) % k == 0 && ms[i] > 0 && ms[j] > 0){
					if (i == j){
						q = ms[i] / 2;
						ms[i] = ms[i] % 2;
						ans += q * 2;
					}else{
						q = min(ms[j], ms[i]);
						ms[j] -= q;
						ans += q * 2;
					}
				}
			}
		}
		out << ans;

	}
};