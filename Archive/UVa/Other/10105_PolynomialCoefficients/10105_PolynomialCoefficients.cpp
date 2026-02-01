#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
    lli factorials[13];
    factorials[1] = 1;
    factorials[0] = 1;
    for (int i = 2; i <= 13; ++i)
        factorials[i] = factorials[i-1] * i;
    int n, k, exps;
    while(scanf("%d %d", &n, &k) != EOF) {
        lli dans = factorials[n]; 
        for (int i = 1; i <= k; ++i){
            scanf("%d", &exps);
            dans /= factorials[exps];
        }
        printf("%lli\n", dans);
    }
    return 0;
}