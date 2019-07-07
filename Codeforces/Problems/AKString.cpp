#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AKString {
public:
	void solve(std::istream& in, std::ostream& out) {
		int k;
		string str;
		in >> k >> str;
		int n = str.size();
		map<char, int> mp;
		REP(i,str.size())
		    mp[str[i]]++;
		str = "";
        for (auto it = mp.begin(); it != mp.end(); ++it){
            if (it->second % k != 0){
                out << -1;
                return;
            }else{
                REP(i,it->second / k)
                    str.pb(it->first);
            }
        }
        while(n > 0){
            out << str;
            n -= str.size();
        }
        

	}
};