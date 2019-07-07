#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ADZYLovesChessboard {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		char g[105][105];
		memset(g, 'x', sizeof(g));
		vector<pii> p;
		in >> n >> m;
		RE(i,n){
			RE(j, m){
				in >> g[i][j];
				if (g[i][j] == '.'){
					if ((i+j)&1)
						g[i][j] = 'W';
					else
						g[i][j] = 'B';
				}
			}
		}
		RE(i,n){
			RE(j,m){
				out << g[i][j];
			}
			out << endl;
		}
	}
};