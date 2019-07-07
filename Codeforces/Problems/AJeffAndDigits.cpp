#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 1004
class AJeffAndDigits {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		int a[N], cnt[6];
		memset(cnt, 0, sizeof(cnt));
		REP(i,n)
			in >> a[i], cnt[a[i]]++;
		if (cnt[0] == 0)
		    out << -1;
		else if (cnt[5] < 9)
		    out << 0;
		else {
		    REP(i,cnt[5] - cnt[5] % 9) out << 5;
		    REP(i, cnt[0]) out << 0;
		}

	}
};