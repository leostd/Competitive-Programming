#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BOddSumSegments {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		const int MAXN = 2e5+5;
		in >> q;
		int a[MAXN], odds[MAXN], odd_count, odd_sum[MAXN];
		while (q--){
			int n, k;
			in >> n >> k;
			odd_count = 0;
			for (int i = 0; i < n; i++)
				in >> a[i], odds[i] = a[i] % 2, odd_count += odds[i];
			odd_sum[0] = odds[0];
			for (int i=1; i < n; i++)
				odd_sum[i] = odds[i] + odd_sum[i-1];
			if (odd_count >= k){
				if ((odd_count - k - 1) % 2 == 1 || odd_count == k){
					out << "YES\n";
					for (int i = 0; i < n && k > 1; i++){
						if (odds[i])
							out << i+1 << " ", k--;
					}
					out << n << "\n";
				}
				else{
					out << "NO\n";
				}
			}
			else
				out << "NO" << "\n";
		}

	}
};