#include <bits/stdc++.h>
using namespace std;



int main() {
    //freopen("in", "r", stdin);
    int n, k;
    int ns[200005];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &ns[i]);
    long long int acum = 0;
    double ans = 0;
    deque<int> dq;
    int i = 0;
    while (i < n)
    {
        while(dq.size() < k){
            acum += ns[i];
            dq.push_back(ns[i]);
            i++;
        }
        ans += acum;
        acum -= dq.front();
        dq.pop_front();
    }
    ans = (double)ans / (n-k+1) ;
    printf("%lf\n", ans);
    return 0;
}