#include "../library/lib.hpp"
#include <iostream>
using namespace std;

#define MOD 998244353

vector<int> pw10;

int mmult(int a, int b){
    return ((a%MOD) *  1LL * (b%MOD)) % MOD;
}


int msum(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
    return a;
}



int f(string x, int n){
    int sz = (int)x.size() * 2;
    sz--;
    int a, b, w, y;
    a = b = 0;
    for (int i = 0; i < x.size(); i++){
        w = pw10[sz - (i * 2)];
        a = msum(a, mmult((x[i] - '0'), w));
        b = msum(b, mmult((x[i] - '0'), pw10[sz - (i*2+1)]));
    }
    a = mmult(a, n);
    b = mmult(b, n);

    return msum(a, b);
}

class D1SubmarineInTheRybinskSeaEasyEdition {
public:
	void solve(std::istream& in, std::ostream& out) {
        int n;
        vector<string> nums;
        string num;

        pw10 = vector<int>(30);
        pw10[0] = 1;
        for (int i = 1; i < 30; ++i) {
            pw10[i] = mmult(pw10[i - 1], 10);
        }
        
        in >> n;
        for (int i = 0; i < n; i++)
            in >> num, nums.pb(num);

        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = msum(ans, f(nums[i], n));
        }
        out << ans << "\n";
	}
};