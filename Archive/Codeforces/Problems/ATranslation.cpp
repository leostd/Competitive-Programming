#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ATranslation {
public:
	void solve(std::istream& in, std::ostream& out) {
		string a,b;
		in >> a >> b;
		reverse(a.begin(), a.end());
		if (a.size() != b.size()){
			out << "NO";
			return;
		}
		REP(i,a.size()){
			if (a[i] != b[i]){
				out << "NO";
				return;
			}
		}
		out << "YES";
	}
};