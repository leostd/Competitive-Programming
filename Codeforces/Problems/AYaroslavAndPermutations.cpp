#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AYaroslavAndPermutations {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		int x;
		priority_queue<pii, vector<pii>, less<pii>> q;
		map<int, int> m;
		REP(i,n){
			in >> x;
			m[x]++;
		}
		int last = -1;
		for(auto it = m.begin(); it != m.end(); ++it){
			if (it->snd > (n+1)/2){
				out << "NO";
				return;
			}
		}
		out << "YES";
	}
};