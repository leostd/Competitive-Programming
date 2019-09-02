#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class D12KGame {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in >> t;
		while(t--){
			int n, k;
			bool alice = true;
			in >> n >> k;
			if (k > n || k % 3 != 0) {
				if ( n % 3 == 0)
					alice = false;
			}else{
				int nn = n % (k+1);
				if (nn % 3 == 0)
					alice = false;
				if (nn == k)
					alice = true;
			}
			if (alice)
				out << "Alice\n";
			else
				out << "Bob\n";
		}

	}
};