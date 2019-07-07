#include "../library/lib.hpp"
#include <iostream>
using namespace std;

bool cmp(pii a, pii b){
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        return a.second > b.second;
    else
        return false;
}

class ADragons {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n,s;
		in >> s >> n;
		vector<pii> d;
		REP(i,n){
			pii a;
			in >> a.first >> a.second;
			d.pb(a);
		}
		sort(d.begin(), d.end(), cmp);
        REP(i,n){
            if (d[i].first >= s){
                out << "NO";
                return;
            }
            else {
                s += d[i].second;
            }
        }
        out << "YES";
	}
};