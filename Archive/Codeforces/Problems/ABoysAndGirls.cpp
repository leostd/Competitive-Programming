#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ABoysAndGirls {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		string ans;
		int t = n+m;
		REP(i, t){
			if (!ans.empty()){
				if (ans.back() == 'B'){
					if (m > 0){
						ans.pb('G');
						m--;
					}else
						ans.pb('B'), n--;
				}else{
					if (n > 0)
						ans.pb('B'), n--;
					else
						ans.pb('G'), m--;
				}
			}
			else
				if (n > m)
					ans.pb('B'), n--;
				else
					ans.pb('G'), m--;
		}
		out << ans;
	}
};