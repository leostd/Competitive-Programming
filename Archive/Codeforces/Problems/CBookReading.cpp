#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CBookReading {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;

        in >> q;

        while(q--){
            ll n, m;
            in >> n >> m;

            ll i = 2;
            set<ll> chk;

            ll sum = 0;
            ll x=m;
            while(chk.count(x) == 0){
                chk.insert(x%10);
                sum += x%10;
                x = (m%10)*(i%10)%10;
                i++;
            }

            ll ans = 0;
            ll d = n / m;
            ll r = d % chk.size();

            ans += d/chk.size() * sum;
            for (ll j = 1; j <= r; j++)
                ans += (m*j) % 10;

            out << ans << "\n";
        }

	}
};