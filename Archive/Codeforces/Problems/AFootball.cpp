#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AFootball {
public:
	void solve(std::istream& in, std::ostream& out) {
		string x, y, first="";
		map<string, int> mp;
		int n;
		in >> n;
		REP(i,n){
			in >> x;
			if (first == "")
				first = x;
			if (first != "" && x != first)
				y = x;
			mp[x]++;
		}
		x = first;
		out << (mp[x] > mp[y] ? x : y);
	}
};