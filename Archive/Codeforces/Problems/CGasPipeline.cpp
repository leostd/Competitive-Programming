#include "../library/lib.hpp"
#include <iostream>
using namespace std;

#define MAXN 200005

int n, a,b;
string s;
ll memo[MAXN][2];

ll dp(int idx, int previousWasUp){
    if (idx == 0)
        return b;

    if (memo[idx][previousWasUp] != -1)
        return memo[idx][previousWasUp];

    ll ans;
    
    if (previousWasUp){
        if (idx - 1 >= 0 && s[idx-1] == '1'){
            ans = dp(idx-1, 1) + a + 2*b;
        }
        else if (idx - 1 >= 0){
            ans = min(dp(idx-1, 0) + 2*a + b, dp(idx-1, 1) + a + 2*b);
        }
    }else {
        if (idx-1 >= 0 && s[idx-1] == '1'){
            ans = dp(idx-1, 1) + 2*a + 2*b;
        }
        else if (idx-1 >= 0){
            ans = min(dp(idx-1, 1) + 2*a + 2*b, dp(idx-1, 0) + a + b);
        }
    }
    return memo[idx][previousWasUp] = ans;
}

class CGasPipeline {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in >> t;

		while(t--){
			in >> n >> a >> b;
			in >> s;

			memset(memo, -1, sizeof(memo));

            ll ans = dp(n, 0) + b;
            out << ans << "\n";
		}

	}
};