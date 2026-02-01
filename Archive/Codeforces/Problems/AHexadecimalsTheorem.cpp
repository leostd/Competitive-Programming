#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AHexadecimalsTheorem {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		ll fibs[1000000];
		memset(fibs, 0, sizeof(fibs));
		fibs[0] = 0;
		fibs[1] = fibs[2] = 1;
		int next_fib = 3;
		in >> n;
		while(fibs[next_fib-1] < (int)(1e9+5)){
		    fibs[next_fib] = fibs[next_fib - 1] + fibs[next_fib-2];
		    next_fib++;
		}
        REP(a,next_fib){
			REP(b, next_fib){
				REP(c, next_fib){
					if (fibs[a] + fibs[b] + fibs[c] == n){
						out << fibs[a] << " " << fibs[b] << " " << fibs[c];
						return;
					}
				}
			}
		}
		out << "I'm too stupid to solve this problem";
	}
};