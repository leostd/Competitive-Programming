#include <bits/stdc++.h>
#define N 200001
using namespace std;

int n, m, a[N], b;

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int ans;
    for (int i = 0; i < m; i++){
        scanf("%d", &b);
        ans = upper_bound(a, a+n, b) - a;
        printf("%d ", ans);
    }
    return 0;
}
