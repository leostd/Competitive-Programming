#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AKitaharaHarukisGift {
public:
	void solve(std::istream& in, std::ostream& out) {
		int x, n, total = 0, sum = 0;
		int f[300];
		memset(f,0,sizeof(f));
		f[0] = 1;
		in >> n;
		REP(i,n){
		    in >> x;
		    x /= 100;
            REP(j, 2*n)
                if (f[j])
                    f[j+x] = 1;
            sum += x;    
		}
		if (sum %2 != 0)
			out << "NO";
		else if (f[sum/2])
		    out << "YES";
		else
		    out << "NO";
	}
};