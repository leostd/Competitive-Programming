#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BWOWFactor {
public:
	void solve(std::istream& in, std::ostream& out) {
		const int MAXN = 1000001;
		string s;
		in >> s;
		ll vcounter[MAXN];
		memset(vcounter, 0, sizeof(vcounter));
		for(int i = 1; i < s.size(); i++){
			if (s[i] == 'v' && s[i-1] == 'v'){
				vcounter[i]++;
			}
			vcounter[i] += vcounter[i-1];
		}
		
		ll ans = 0;
		for (int i = 0; i < s.size(); i++){
			if(s[i] == 'o'){
				ans += vcounter[i] * (vcounter[s.size()-1] - vcounter[i]);
			}
		}
		out << ans;
	}
};