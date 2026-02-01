#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 100005

class ASushiForTwo {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, a, cur = -1, cm = 0;
		vector<int> s(N, -1), c;
		in >> n;
		REP(i, n)
			in >> s[i];
		REP(i, n){
			if (cur == -1){
				cur = s[i];
				c.pb(1);
			}
			else if (cur == s[i]){
				c[cm]++;
			}
			else if (cur != s[i]){
				c.pb(1);
				cm++;
				cur = s[i];
			}
		}
		int ans = -1;
		for(int i = 0; i < c.size()-1; i++){
			ans = max(ans, min(c[i], c[i+1]));
		}
		out << ans * 2;
	}
};