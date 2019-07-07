#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CTwoShuffledSequences {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		vector<int> inc, dec, a;
		map<int, int> cnt;
		int x;
		REP(i,n){
			in >> x, a.pb(x);
			if (cnt.count(x) == 0){
				inc.pb(x);
			}
			else if (cnt[x] == 1){
				dec.pb(x);
			}
			else if (cnt[x] == 2){
				out << "NO";
				return;
			}
			cnt[x]++;
		}
		out << "YES\n";
		out << inc.size() << "\n";
		sort(inc.begin(), inc.end());
		REP(i,inc.size())
			out << inc[i] << " ";
		out << "\n" << dec.size() << "\n";
		sort(dec.begin(), dec.end(), greater<int>());
		REP(i,dec.size()){
			out << dec[i] << " ";
		}
		out << "\n";
		
	}
};