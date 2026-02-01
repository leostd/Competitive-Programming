#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CCandies {
public:
	void solve(std::istream& in, std::ostream& out) {
        const int MAXN = 1e5+1;
	    int n, q, a[MAXN], sum[MAXN];
	    in >> n;
	    sum[0] = 0;
	    for(int i = 1; i <= n; i++){
	        in >> a[i];
	        sum[i] = a[i] + sum[i-1];
	    }
	    in >> q;
	    int x, y;
	    for (int i = 0; i < q; i++){
	        in >> x >> y;
	        out << (sum[y] - sum[x-1]) / 10 << "\n";
	    }
	}
};