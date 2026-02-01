#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

lli ipow(int n, int e) {
    if (e == 0)
        return 1;
    if (e == 1)
        return n;
    if (e % 2 == 0)
        return ipow(n, e/2) * ipow(n, e/2);
    if (e % 2 != 0)
        return n * ipow(n,e-1);
}

struct Poly {
    int d;
    int coef[21];
    lli evaluate(int x) {
        lli ans = coef[0];
        for (int i = 1; i <= d; i++){
            if (coef[i] == 0) continue;
            else
                ans += coef[i]*ipow(x, i);
        }
        return ans;
    }   
};

int main() {
    //freopen("in", "r", stdin);
    int tc, d, k;
    scanf("%d", &tc);
    while(tc--){
        Poly p;
        vi bm;
        scanf("%d", &p.d);
        for (int i = 0; i <= p.d; i++)
            scanf("%d", &p.coef[i]);
        scanf("%d", &d);
        scanf("%d", &k);
        k--;
        int idx = 1;
        lli a;
        while (bm.size() <= k) {
            a = p.evaluate(idx);
            for (int i = 0; i < d*idx && bm.size() <= k; i++)
                bm.push_back(a);
            idx++;
        }
        printf("%lli\n", bm[k]);
    }
    return 0;
}