#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <limits.h>
#include <map>
using namespace std;


typedef long long int lli;
int p, m, v, s, k, d;
int memo[10005][105];

int dp(int ms, int ks){
    if (ms <= 0)
        return 0;
    else if (memo[ms][ks] > -1)
        return memo[ms][ks];
    else{
        int a, b, c;
        a = b = c = INT_MAX;
        if (ks > 0)
            a = dp(ms-v-s, ks-1) + 1;
        if (ks < k && (ks + d) <= k)
            b = dp(ms, ks+d) + 1;
        c = dp(ms-v, ks)+1;
        memo[ms][ks] = min(min(a, b), c);
        return memo[ms][ks];
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++){
        scanf("%d %d %d %d %d %d", &p, &m, &v, &s, &k, &d);
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= k; j++)
                memo[i][j] = -1;
        int ans = dp(m, k);
        printf("Scenario #%d: ", tc);
        if (ans < p)
            printf("Ronny wins in time %d\n", ans);
        else
            printf("Ronny will be annihilated\n");
    }
    return 0;
}