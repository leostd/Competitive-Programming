#include "../library/lib.hpp"
#include <iostream>
using namespace std;

ll ans;

ll pp(ll a, ll b){
	ll ans = 1;
	RE(i, b)
		ans *= a;
	return ans;
}

void bt(string s, ll left){
	if (s.size() == 0)
		return;
	else{
		ll digit = s[0] - '0';
		ll prod = pp(9, s.size()-1);
		if (digit > 1)
			prod *= (digit-1);
		if (left != 0)
			prod *= left;
		if (s.size() == 1)
			prod = digit * left;
		ans = max(ans, prod);
		s.erase(s.begin());
		left = (left == 0? digit : left*digit);
		bt(s, left);
	}
}
class BNirvana {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll n;
		ll prod = 1;
		string str;
		in >> n;
		str = to_string(n);
		ans = -1;
//		ll firstd = str[0] - '0';
//		ll left = 0;
//		ll ans = -1;
//		REP(i,str.size()){
//			int digit = str[i] - '0';
//			prod = pp(9, str.size()-i-1) * (left != 0? left : 1) * (digit > 1? digit-1 : 1);
//			ans = max(prod, max(prod/9*digit*left));
//			prod = 1;
//			left = (left == 0? digit : left*digit);
//		}
//		REP(i,str.size()-1)
//			prod *= 9;
//		if(str.size() == 1){
//			ans = n;
//		}
		bt(str, 0);
		if (str.size() == 1)
			ans = n;
		out << ans;

	}
};