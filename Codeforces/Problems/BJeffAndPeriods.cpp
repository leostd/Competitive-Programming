#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BJeffAndPeriods {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		vector<pii> v, ans;
		map<int, int> last, period;
		int x;
		in >> n;
		REP(i,n){
			in >> x;
			if (period.count(x) == 0){
				period[x] = 0;
			}else if (period[x] == 0){
				period[x] = i - last[x];
			}else
				period[x] = (period[x] == i - last[x]) ? period[x] : -1;
			last[x] = i;
		}
		
		for(auto it = period.begin(); it != period.end(); ++it){
			if (it->snd != -1)
				ans.pb(*it);
		}
		out << ans.size() << "\n";
		REP(i,ans.size())
			out << ans[i].fst << " " << ans[i].snd << "\n"; 
	}
};