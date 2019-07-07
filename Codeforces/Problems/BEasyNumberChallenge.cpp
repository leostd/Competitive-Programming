#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BEasyNumberChallenge {
public:
	void solve(std::istream& in, std::ostream& out) {
		int a,b,c;
		in >> a >> b >> c;
		ll sum = 0;
		const int MOD = (1 << 30);
		RE(i, a){
		    RE(j, b){
		        RE(k, c){
		        	int x = i*j*k;
		        		
		           sum = (sum%MOD + d(x)%MOD)%MOD; 
		        }
		    }
		}
        out << sum;
	}
	
	int d(int x){
		int divisors = 2;
		if (x == 1)
			return 1;
		for(int y = 2;  y*y <= x; y++){
			if (x % y == 0){
				if (x/y != y)
					divisors++;
				divisors++;
			}
		}
		return divisors;
	}
};