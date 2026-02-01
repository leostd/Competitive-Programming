#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BJzzhuAndSequences {
public:
	void solve(std::istream& in, std::ostream& out) {
	    vector<ll> v;
	    ll x;
	    const ll MOD = 1000000007;
	    v.pb(-1);
	    in >> x, v.pb((x%MOD + MOD)%MOD);
	    in >> x, v.pb((x%MOD + MOD)%MOD);
        FOR(i,3,6){
            x = (v[i-1]%MOD - v[i-2]%MOD + MOD) % MOD;
            v.pb(x);
        }
        ll n;
        in >> n;
        out << v[(n%6) + (n%6 == 0 ? 6 : 0)];
	}
};