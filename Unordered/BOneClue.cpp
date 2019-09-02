#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BOneClue {
public:
	void solve(std::istream& in, std::ostream& out) {
		int k, x;
		in >> k >> x;

		for (int i = k-1; i >= 0; i--){
		    if (x-i >= -1000000)
			out << x-i << " ";
		}
//		out << x << " ";
		for (int i = 1; i <= k-1; i++){
			if (x+i <= 1000000)
			 out << x+i << " ";
		}

	}
};