#include <iostream>
#include <algorithm>
#define sqr(x) ((x)*(x))
typedef long long ll;

class CLunarNewYearAndNumberDivision {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		ll sum = 0;
		ll a[300005];
		in >> n;
		for (int i = 0; i < n; i++)
			in >> a[i];
		std::sort(a, a+n);
		int l = 0, r = n-1;
		while(l < r){
		    sum += sqr(a[l]+a[r]);
		    l++;
		    r--;
		}
		out << sum;
	}
};