#include "../library/lib.hpp"
#include <iostream>
using namespace std;


class ALightsOut {
	int xmov[4] = {0,0,1,-1}, ymov[4] = {1,-1,0,0};
public:
	void print(int g[4][4], ostream& out){
		REP(i,3){
			REP(j,3)
				out << g[i][j];
			out << "\n";
		}
	}
	void solve(std::istream& in, std::ostream& out) {
	    int g[4][4], ans[4][4];
	    REP(i,3)
	        REP(j,3)
	            in >> g[i][j], ans[i][j] = 1;
	    REP(i,3){
	        REP(j,3){
	            if (g[i][j] % 2 != 0){
	            	ans[i][j] ^= 1;
					REP(k, 4){
						int r = i + xmov[k];
						int c = j + ymov[k];
						if (r >= 0 && r < 3 && c >= 0 && c < 3)
							ans[r][c] ^= 1;
					}
	            }
	        }
	    }
	    REP(i,3){
            REP(j,3)
                out << ans[i][j];
            out << "\n";
	    }
	}
};