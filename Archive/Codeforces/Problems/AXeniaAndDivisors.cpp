#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AXeniaAndDivisors {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		int a[8];
		memset(a, 0, sizeof(a));
		int x;
		REP(i,n)
			in >> x, a[x]++;
        if(a[5] > 0 || a[7] > 0 || a[1] == 0){
            out << -1;
            return;
        }
        vector<vector<int>> ans;
        vector<int> aux;
        int cnt = 0;
        REP(i,a[1]){
            aux.clear();
            if (a[2] >= 1 && a[4] >= 1){
                aux.pb(1);
                aux.pb(2);
                aux.pb(4);
                a[2]--;
                a[4]--;
                ans.pb(aux);
            }
            else if(a[2] >= 1 && a[6] >= 1){
                aux.pb(1);
                aux.pb(2);
                aux.pb(6);
                a[2]--;
                a[6]--;
                ans.pb(aux);
            }
            else if(a[3] >= 1 && a[6] >= 1){
                aux.pb(1);
                aux.pb(3);
                aux.pb(6);
                a[3]--;
                a[6]--;
                ans.pb(aux);
            }
        }
        a[1] -= ans.size();
        RE(i,7)
            if (a[i] != 0){
                out << -1;
                return;
            }
        REP(i,ans.size()){
                REP(j,ans[i].size()){
                    out << ans[i][j] << (j==2? "" : " ");
                }
                out << "\n";
            }

	}
};