#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ADiverseStrings {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		while(n--){
			string str;
			in >> str;
			int c[27];
			bool flag = false, flag2 = false, ans = false;
			memset(c, 0, sizeof(c));
			REP(i,str.size())
				c[str[i]-'a']++;
			REP(i, 26){
				if (c[i] == 1 && !flag)
					flag = true;
				else if (c[i] > 1){
					ans = true;
					out << "No\n";
					break;
				}
				else if (c[i] == 0 && flag){
					flag2 = true;
				}
				else if (c[i] == 1 && flag && flag2){
					ans = true;
					out << "No\n";
					break;
				}
			}
			if (!ans)
				out << "Yes\n";
		}

	}
};