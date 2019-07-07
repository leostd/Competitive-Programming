#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class APanoramixsPrediction {
public:
	void solve(std::istream& in, std::ostream& out) {
		int x, y;
		vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
		in >> x >> y;
		REP(i, primes.size()){
			if (primes[i] == x){
				if (i+1 < primes.size() && primes[i+1] == y){
					out << "YES";
				}
				else{
					out << "NO";
				}
				return;
			}
		}

	}
};