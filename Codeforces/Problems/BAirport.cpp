#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BAirport {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m, x;
		priority_queue<int> mnq;
		priority_queue<int, vector<int>, greater<int>> mxq;
		in >> n >> m;
		REP(i, m)
			in >> x, mxq.push(x), mnq.push(x);
		int ansmx = 0, ansmn = 0;
		REP(i,n){
			int a = mxq.top(); mxq.pop();
			ansmx += a;
			a--;
			if (a > 0)
				mxq.push(a);
			int b = mnq.top(); mnq.pop();
			ansmn += b;
			b--;
			if (b > 0)
				mnq.push(b);
		}
		out << ansmn << " " << ansmx;
	}
};