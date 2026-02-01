#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CArraySplitting {
public:
	void solve(std::istream& in, std::ostream& out) {
		const int MAXN = 300005;
		int n, k, a[MAXN];
		priority_queue<int> pq;
		ll ans = 0;
		in >> n >> k;
		for (int i = 0; i < n; i++){
			in >> a[i];
			if (i > 0){
				pq.push(a[i]-a[i-1]);
			}
		}
		ans = a[n-1] - a[0];
		for (int i = 0; i < k-1; i++){
			ans -= pq.top();
			pq.pop();
		}
		out << ans;
	}
};