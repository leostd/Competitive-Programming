#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BSortTheArray {
public:
	void solve(std::istream& in, std::ostream& out) {
        int n;
        in >> n;
        vector<int> a, b;
        int x;
        REP(i,n)
            in >> x, a.pb(x), b.pb(x);
        sort(a.begin(), a.end());
        int start, end;
        start = end = -1;
        bool flag = false;
        REP(i, n){
            if (a[i] != b[i] && start == -1){
                start = end = i;
            }
            else if (a[i] != b[i] && start != -1)
                end = i;
        }
        if (start == end && start == -1)
            out << "yes\n", out << 1 << " " << 1;
        else{
            reverse(b.begin()+start, b.begin()+end+1);
            REP(i, n){
                if (a[i] != b[i]){
                    out << "no";
                    return;
                }
            }
            out << "yes\n";
            out << start +1<< " " << end+1;
        }
	}
};