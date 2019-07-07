#include <iostream>
#include <cmath>

class ABePositive {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		int a[1005], neg, pos, zero, target;
		neg = pos = zero = 0;
		in >> n;
		for (int i = 0; i < n; i++){
			in >> a[i];
			if (a[i] == 0)
				zero++;
			else if(a[i] > 0)
				pos++;
			else if(a[i] < 0)
				neg++;
		}
		target = ceil((double)n/(double)2);
		if ((n&1 && zero >= target) || !(n&1) && zero > target){
			out << 0;
		}else if(pos >= target){
			out << 1;
		}else if(neg >= target){
			out << -1;
		}else {
			out << 0;
		}
	}
};