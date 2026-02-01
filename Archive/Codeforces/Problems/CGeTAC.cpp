#include "../library/lib.hpp"
#include <iostream>
using namespace std;

#define N 100001

class CGeTAC {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s;
		int sum[N], n, q;
		memset(sum, 0, sizeof(sum));
		in >> n >> q >> s;
		for(int i = 1; i < s.size(); ++i){
			if (s[i] == 'C' && s[i-1] == 'A')
				sum[i+1] = 1;
		}
		for(int i = 1; i <= s.size(); i++)
			sum[i] += sum[i-1];
		int a, b;
		REP(i,q){
			in >> a >> b;
			out << sum[b] - sum[a] << "\n";
		}

	}
};