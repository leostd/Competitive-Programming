#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ARemoveAProgression {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in >> t;
		vector<int> evens;
		for (int i = 0; i < t; i++){
			int n, x;
			in >> n >> x;
			out << x*2 << "\n";
		}
	}
};