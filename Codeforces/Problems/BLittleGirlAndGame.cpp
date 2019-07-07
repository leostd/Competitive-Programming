#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BLittleGirlAndGame {
public:
	void solve(std::istream& in, std::ostream& out) {
		string str;
		map<char,int> mp;
		in >> str;
		REP(i,str.size())
			mp[str[i]]++;
		int odds = 0;
		for(auto it = mp.begin(); it != mp.end(); ++it){
			if (it->snd % 2 != 0)
				odds++;
		}

		if ((odds >= 1 && (odds-1) % 2 == 0) || odds == 0)
			out << "First";
		else
		    out << "Second";

	}
};