#include "../library/lib.hpp"
#include <iostream>
using namespace std;

const int MAXN = 1e5+2;
ll ts[MAXN][2], memo[MAXN][2];

ll dp(int idx, int team){
	if (idx < 0)
		return 0;

	if (idx == 0)
		return ts[idx][team];

	if (memo[idx][team] != -1)
		return memo[idx][team];

	ll a,b,c,d, ans;
	a = dp(idx-1, !team) + ts[idx][team];
	b = dp(idx-1, team);
	c = dp(idx-2, !team) + ts[idx][team];
	d = dp(idx-2, team) + ts[idx][team];

	ans = max(a,max(b, max(c,d)));	
	return memo[idx][team] = ans;
}

class CBasketballExercise {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		for (int i = 0; i < n; i++)
			in >> ts[i][0];
		for (int i = 0; i < n; i++)
			in >> ts[i][1];
		memset(memo, -1, sizeof(memo));
		ll ans = max(dp(n-1, 0), dp(n-1, 1));
		out << ans << "\n";

	}
};