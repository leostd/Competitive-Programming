#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AImportantExam {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		vector<string> sts;
		int pts[1001];
		
		string s;
		for (int i = 0; i < n; i++)
			in >> s, sts.pb(s);
		
		for (int i = 0; i < m; i++)
			in >> pts[i];
		
		ll ans = 0;
		for (int i = 0; i < m; i++){
			
			int aux[5];
			memset(aux, 0, sizeof(aux));
			for (int j = 0; j < n; j++)
				aux[sts[j][i] - 'A']++;
			
			int mx=-1;
			for (int i = 0; i < 5; i++)
				if (aux[i] > mx)
					mx = aux[i];
				
			ans += mx * pts[i];
		}
		
		out << ans;

	}
};