#include "../library/lib.hpp"
#include <iostream>
using namespace std;

ll a;

void get_best(ll x, ll ans){
	while(x % 2 == 0){
		x /= 2;
		ans++;
	}
	while(x % 3 == 0){
		x /= 3;
		ans += 2;
	}
	while(x % 5 == 0){
		x /= 5;
		ans += 3;
	}
	if (x != 1)
		a = -1;
	else
		a = ans;
}

class ADivideIt {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll n, q;
		
		in >> q;
		for (int i = 0; i < q; i++){
			in >> n;
			a = INFINITY;
			get_best(n, 0);
			out << a << "\n";
		}
	}
};