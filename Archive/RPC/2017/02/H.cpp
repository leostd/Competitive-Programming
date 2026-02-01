#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long ll;

struct A{
    ll s, f, p; // start, finish, profit
};

bool cmp(A a, A b){
    return a.s < b.s;
}

bool cmp2(A a, A b){
    return a.s < b.f;
}

A as[200009];
ll memo[200009];
ll n, k;

ll dp(int id)
{
    if (id == k)
        return 0;
    if (memo[id] != -1)
        return memo[id];
    int idx = lower_bound(as, as+k, as[id], cmp2) - as;
    memo[id] = max(dp(id+1), as[id].p + dp(idx));
    return memo[id];
}

int main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%lld %lld", &as[i].s, &as[i].f);
        as[i].p = as[i].f - as[i].s + 1;
    }
    sort(as, as+k, cmp);
    memset(memo, -1, sizeof(memo));
    ll ans = dp(0);
    cout << n - ans << "\n";
    return 0;
}   