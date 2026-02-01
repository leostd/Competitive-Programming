#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int f(int x) {
    vi ds;
    while(x) {
        int d = x %10;
        ds.push_back(d);
        x /= 10;
    }
    sort(ds.begin(), ds.end());
    int tot = 0;
    for(int i = 1; i <= ds.size(); i++) {
        int b = 1;
        for (int j = 1; j <= ds.size()-i; ++j) 
            b *= 10;
        b *= ds[i-1];
        tot += b;
    }
    return tot;
}

int main() {
    int n, m;
    vi ds;
    while(scanf("%d", &n) != EOF) {
        m = f(n);
        int ac = 0;
        while(n - m) {
            ac++;
            n = n-m;
            m = f(n);
        }
        ac++;
        printf("%d\n", ac);
    }
    return 0;
}