#include "../library/lib.hpp"
#include <iostream>
using namespace std;

typedef pair<int, vector<int>> ivi;

class BLettersShop {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s, f;
		int n, m;
		in >> n >> s;
		map<char, vector<int>> h;
		REP(i, s.size()){
			h[s[i]].pb(i);
		}
		in >> m;
		int cnt[30];
		REP(i, m){
			in >> f;
			int ans = -1;
			memset(cnt, 0, sizeof(cnt));
			REP(j, f.size()){
				cnt[f[j]-'a']++;
			}
			REP(j, 30){
				if (cnt[j] != 0)
					ans = max(ans, h[j+'a'][cnt[j]-1]+1);
			}
			out << ans << "\n";
		}
	}
};