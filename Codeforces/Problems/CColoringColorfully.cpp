#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CColoringColorfully {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s;
		in >> s;
		// 0 fst
		int cnt0, cnt1;
		cnt0 = cnt1 = 0;
		for(int i = 0; i < s.size(); i++){
		    if (i % 2 == 0){
		        if (s[i] == '1')
		            cnt0++;
		    }
		    else{
		        if (s[i] == '0')
		            cnt0++;
		    }
		}

        for(int i = 0; i < s.size(); i++){
            if (i % 2 == 0){
                if (s[i] == '0')
                    cnt1++;
            }
            else{
                if (s[i] == '1')
                    cnt1++;
            }
        }
        out << min(cnt0, cnt1);

	}
};