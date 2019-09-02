#include "../library/lib.hpp"
#include <iostream>
using namespace std;
string s, t;

bool check (int a, int b){
    int idx = 0;
    for (int i = 0;i < s.size(); i++){
        if (i < a || i > b){
            if (s[i] == t[idx])
                idx++;
        }
    }
    return idx == t.size();
}
class D1RemoveTheSubstringEasyVersion {
public:
	void solve(std::istream& in, std::ostream& out) {
		
		in >> s >> t;
		
		int ans = 0;
		for (int i = 0; i < s.size(); i++){
		    for(int j = i; j < s.size(); j++){
		        if (check(i, j)){
		            ans = max(ans, j-i+1);
		        }
		    }
		}
		out << ans;
	}
};