#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ANearlyLuckyNumber {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll n;
		int l = 0;
		in >> n;
		while(n > 0){
			int x = n %10;
			if (x == 4 || x == 7)
				l++;
			n /= 10;
		}
		
		if (l == 4 || l == 7)
			out << "YES";
		else
			out << "NO";

	}
};