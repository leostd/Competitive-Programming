#include "../library/lib.hpp"
#include <iostream>
using namespace std;

#define MAXN 100005

class BMakeProductEqualOne {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		int a[MAXN];
		
		in >> n;
		int zeroes, negatives;
		zeroes = negatives = 0;
		for (int i = 0; i < n; i++)
			in >> a[i], (a[i] == 0 ? zeroes++ : zeroes += 0), a[i] < 0 ? negatives++ : negatives += 0;
		
		ll ans = 0;
		for (int i = 0; i < n; i++){
			if (a[i] < 0)
				ans += -(a[i]) - 1;
			else if (a[i] > 0)
				ans += a[i] - 1;
			else
				ans += 1;
		}
		
		if (negatives % 2 && zeroes == 0)
			ans += 2;
		
		out << ans;
	}
};