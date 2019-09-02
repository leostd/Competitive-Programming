#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CMaximumMedian {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll n, x, k;
		vector<int> ns;

		in >> n >> k;

		for (int i = 0; i < n; i++){
		    in >> x, ns.pb(x);
		}

		sort(ns.begin(), ns.end());
		priority_queue<int, vector<int>, greater<int>> pq;
		ll aux = 0;
		ll ans = ns[n/2];

        for (int i = (int)n/2, j = 1; i < n-1; i++, j++) {
            ll diff = ns[i+1] - ns[i];
            ll steps = diff * j;
            if (k >= steps){
                ans += diff;
                k -= steps;
            } else {
            	ans += k/j;
            	k = 0;
            	break;
            }
        }

        ans += k/ (n/2 + 1);

		out << ans;

	}
};