#include "../library/lib.hpp"
#include <iostream>
using namespace std;

int bt(ll n, ll m, int ans){
	if (n == m)
		return ans;
	else if (n > m){
		return -1;
	}
	else{
		int a = bt(n*2, m, ans+1);
		int b = bt(n*3, m, ans+1);
		if (a != -1)
			return a;
		else if (b != -1)
			return b;
		else 
			return -1;
	}
}

class AGame23 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		int ans = 0;
		ans = bt(n, m, 0);
		out << ans;
	}
};