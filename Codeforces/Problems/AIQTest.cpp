#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AIQTest {
public:
	void solve(std::istream& in, std::ostream& out) {
        vector<string> g;
        string s;
        int n, m;
        n = 4, m = 4;
        REP(i, n)
            in >> s, g.pb(s);
        REP(i, n-1){
            int cnt = 0;
            REP(j, m-1){
                cnt = 0;
                if (g[i][j] == '#')
                    cnt++;
                if (g[i+1][j] == '#')
                    cnt++;
                if (g[i][j+1] == '#')
                    cnt++;
                if (g[i+1][j+1] == '#')
                    cnt++;
                if (cnt <= 1 || cnt >= 3){
                    out << "YES";
                    return;
                }
            }
            
        }
        out << "NO";
	}
};