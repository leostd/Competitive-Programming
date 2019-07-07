#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AAmusingJoke {
public:
	void solve(std::istream& in, std::ostream& out) {
		string a,b,c;
		in >> a >> b >> c;
		int l[27] = {0};
		REP(i, a.size())
			l[a[i]-'A']++;
		REP(i, b.size())
			l[b[i]-'A']++;
		REP(i, c.size())
			l[c[i]-'A']--;
		int ans = 0;
		REP(i,27){
			if (l[i] != 0){
				out << "NO";
				return;
			}
		}
		out << "YES";
	}
};