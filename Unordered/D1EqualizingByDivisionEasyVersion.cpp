#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class D1EqualizingByDivisionEasyVersion {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k;
		in >> n >> k;

		int x;
		vector<int> a;
		map<int, map<int,int>> m;
		map<int, int> cnt;
		for (int i = 0;i < n; i++) {
			in >> x, a.pb(x);
			int aux = x;
			int j = 0;
			while(x > 0){
				if(m[aux].count(x) == 0)
					m[aux][x] = j++;
				cnt[x]++;
				x /= 2;
			}
		}
	}
};