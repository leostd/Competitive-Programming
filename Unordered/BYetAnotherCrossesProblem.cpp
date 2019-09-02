#include "../library/lib.hpp"
#include <iostream>
using namespace std;


class BYetAnotherCrossesProblem {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		in >> q;
		for (int i = 0; i < q; i++){
			int n, m;
			in >> n >> m;
			vector<string> g;
			vector<vector<int>> psr, psc;
			char x;
			for (int j = 0; j < n; j++){
				string a;
				vector<int> b(m, 0);
				for(int k = 0; k < m; k++){
					in >> x;
					a.pb(x);
					if (k > 0){
					    b[k] += b[k-1] + (x == '.' ? 1 : 0);
					}
					else
					    b[k] = (x == '.' ? 1 : 0);
				}
				psr.pb(b);
				g.pb(a);
			}
			vector<int> c(m, 0);
			for (int j = 0; j < m; j++)
				c[j] = (g[0][j] == '.'? 1 : 0);
			psc.pb(c);
			for (int j = 1; j < n; j++){
				vector<int> c(m, 0);
				for (int k = 0; k < m; k++){
					c[k] = psc[j-1][k] + (g[j][k] == '.' ? 1 : 0);
				}
				psc.pb(c);
			}
			int ans = INFINITY;
			for (int j = 0; j < n; j++){
				for (int k = 0; k < m; k++){
					int x = psr[j][m-1] + psc[n-1][k];
					if (g[j][k] == '.' && x > 0)
						x--;
					ans = min(ans, x);
				}
			}
//			for (int j = 0; j < m; j++)
//				out << c[j] << " ";
//			out << "\n";
//			for (int i = 0; i < n; i++){
//				for (int j = 0; j < m; j++){
//					out << psc[i][j] << " ";
//				}
//				out << "\n";
//			}
//			out << "\n";
		out << ans << "\n";


		}

	}
};