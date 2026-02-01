#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BBadPrices {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		in >> q;

		while(q--){
			int n;
			int a[200005], b[200005];

			in >> n;
			REP(i, n)
				in >> a[i];
			
			priority_queue<int> pq;
			pq.push(a[0]);
			int ans = 0;
			RE(i,n-1){
				while(!pq.empty() && pq.top() > a[i]){
					pq.pop();
					ans++;
				}
				pq.push(a[i]);
			}
			out << ans << "\n";
		}

	}
};