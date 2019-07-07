#include "../library/lib.hpp"
#include <iostream>
#include <time.h>
using namespace std;

class AMiddleOfTheContest {
public:
	void solve(std::istream& in, std::ostream& out) {
		string str;
		in >> str;
		int h1 = (str[0] - '0') * 10 + (str[1] - '0');
		int m1 = (str[3] - '0') * 10 + (str[4] - '0');
		in >> str;
		int h2 = (str[0] - '0') * 10 + (str[1] - '0');
		int m2 = (str[3] - '0') * 10 + (str[4] - '0');
		if (h2 < h1)
			h2 += 24;
		else if (h2 == h1 && m1 == m2)
			h2 += 24;
		int mins = m2 - m1 + (h2 - h1) * 60;
		mins /= 2;
		int hans = (h1 + (m1+mins)/60) % 24;
		int mans = (m1 + (mins%60))%60;
		string hs ;
		string ms ;
		if (hans >= 10){
			hs.pb(hans/10 + '0');
			hs.pb((hans%10) +'0');
		}else{
			hs.pb('0');
			hs.pb(hans + '0');
		}

		if(mans >= 10){
			ms.pb(mans/10 + '0');
			ms.pb((mans%10) + '0');
		}
		else{
			ms.pb('0');
			ms.pb(mans + '0');
		}
		out << hs << ":" << ms;
	}
};