#include "../library/lib.hpp"
#include <iostream>
using namespace std;

int get_cost(const string &s, const vector<string> &p){
	int ans = INFINITY;
	int cost;
	for (int i = 0; i < p.size(); i++){
		int idx = 0;
		cost = 0;
		for (int j = 0; j < s.size(); j++){
			if (p[i][idx] == s[j])
				idx++;
			else{
				cost++;
				idx++;
			}
			if (idx == p[i].size())
				break;
		}
		if (idx == p[i].size())
			ans = min(ans, cost);
	}
	return ans;
}

class D1RGBSubstringEasyVersion {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		in >> q;
		string rgb = "RGB";
		while(q--){
			int n, k;
			string s;
			in >> n >> k >> s;
			vector<string> possible;
			for (int i = 0; i < 3; i++){
				string p;
				for(int j = 0; j < k; j++){
					p.pb(rgb[(i+j)%3]);
				}
				possible.pb(p);
			}
			int ans = INFINITY;
			for (int i = 0; i < n; i++){
				string ss = s.substr(i, n-i);
				ans = min(ans, get_cost(ss, possible));
			}
			out << ans << "\n";
		}

	}
};