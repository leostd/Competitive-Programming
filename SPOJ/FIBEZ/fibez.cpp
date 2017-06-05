#include <bits/stdc++.h>
#define MODULO (100000000+7)
using namespace std;

int memo[500005];


int main() {
    int t, n;
    scanf("%d", &t);
    memset(memo, -1, sizeof(memo));
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i < 500001; ++i){
        memo[i] = (memo[i-1] + memo[i-2])%MODULO;
    }
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", memo[n]);
    }
    return 0;
}