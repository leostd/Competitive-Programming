#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BPresentFromLena {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		vector<string> ans;
		string str;
		in >> n;
		REP(i,n+1){
		    str = "";
		    REP(k,n-i)
		    	str.pb(' '), str.pb(' ');
		    REP(j,i+1){
		        str.pb(j+'0'); if (i==0) continue; else str.pb(' ');
		    }
			for(int k = i; k > 0; k--){
				str.pb(k-1+'0'); if(k > 1) str.pb(' ');
			}
//			REP(k,n-i)
//				str.pb(' ');
		    ans.pb(str);
			
		}
		REP(i,ans.size()){
		    out << ans[i] << "\n";
		}
		for(int i = ans.size()-2; i >= 0; i--)
			if (i > 0)
				out << ans[i] << "\n";
			else
				out << ans[i];
	}
};