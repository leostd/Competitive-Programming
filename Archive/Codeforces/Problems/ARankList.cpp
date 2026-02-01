#include "../library/lib.hpp"
#include <iostream>
using namespace std;

bool cmp(pii a, pii b){
	if (a.fst > b.fst)
		return true;
	else if (a.fst == b.fst)
		return a.snd < b.snd;
	return false;
}

class ARankList {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, x, y, p;
		in >> n >> p;
		vector<pii> v;
		map<pii, int> m;
		pii a;
		REP(i, n){
			in >> a.fst >> a.snd;
			v.pb(a);
			m[a]++;
		}
		sort(v.begin(), v.end(), cmp);
        out << m[v[p-1]];

	}
};