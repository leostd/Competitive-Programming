#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BQueueAtTheSchool {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, t;
		string cur, next;
		in >> n >> t >> cur;
		FOR(i,1,t){
			next = cur;
			REP(j,n-1){
				if (cur[j] == 'B' && cur[j+1] == 'G')
					swap(next[j], next[j+1]);
			}
			cur = next;
		}
		out << cur;
	}
};