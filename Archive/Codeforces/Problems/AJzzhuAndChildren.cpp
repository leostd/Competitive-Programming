#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AJzzhuAndChildren {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		int x;
		queue<pii> q;
		REP(i,n){
		    in >> x;
		    q.push(mp(x,i+1));
		}
		while(q.size() > 1){
		    pii p = q.front();
		    q.pop();
		    if (p.first > m){
		        p.first -= m;
		        q.push(p);
		    }
		}
		out << q.front().second;

	}
};