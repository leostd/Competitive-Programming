#include <iostream>

typedef long long ll;

class ASeaBattle {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll w1, w2, h1, h2;
		in >> w1 >> h1 >> w2 >> h2;
		ll ans = 0;
		ans += 2*h1 + w1 + 2;
		ans += 2*h2 + w2 + 2;
		if (w1 > w2){
			ans++;
			ans += (w1 - w2 -1);
		}
		out << ans;
	}
};