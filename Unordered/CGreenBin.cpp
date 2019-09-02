#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CGreenBin {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		map<string, ll> m;
		string s;
		
		for (int i = 0; i < n; i++) 
			in >> s, sort(s.begin(), s.end()), m[s]++;
		
		ll ans = 0;
		for (auto it = m.begin(); it != m.end(); ++it){
			ans += it->snd * (it->snd-1) / 2;
		}
		
		out << ans;

	}
};