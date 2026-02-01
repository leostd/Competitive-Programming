#include "../library/lib.hpp"
#include <iostream>
using namespace std;

ll dist(pii a, pii b){
	return abs(a.fst - b.fst) + abs(b.snd - a.snd);
}

class BSail {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		pii src, dst;
		in >> n >> src.fst >> src.snd >> dst.fst >> dst.snd;
		string str;
		in >> str;
		map<char, pii> mv;
		mv['E'] = mp(1,0);
		mv['W'] = mp(-1,0);
		mv['N'] = mp(0,1);
		mv['S'] = mp(0,-1);
		int ans = 0;
		REP(i,n){
			pii m = mv[str[i]];
			pii nw = mp(m.fst + src.fst, m.snd + src.snd);
//			out << dist(src, dst) << " " << dist(nw, dst)<< endl;
//			ll a = dist(src, dst);
//			ll b = dist(nw, dst);
			if (dist(src, dst) > dist(nw, dst)){
				src = nw;
			}
			ans++;
			if (src == dst){
				out << ans;
				return;
			}
		}
		out << -1;
		return;
	}
};