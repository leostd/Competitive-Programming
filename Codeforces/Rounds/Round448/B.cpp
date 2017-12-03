#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n;
    ll x, k, a[100010], low, up;
    cin >> n >> x >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll b = a[i];
        low = up = -1;
        if (k == 0) {
            if (b % x != 0){
                low = b;
                up = b+(x - (b % x))-1;
            }
        }
        else if (k == 1){
            if (b % x == 0){
                low = b;
                up = low + x - 1;
            }
            else{
                low = b + (x - (b % x));
                up = low + x - 1;
            }
        }
        else {
            if (b % x == 0){
                low = b + (k-1)*x;
                up = low + x - 1;
            }
            else{
                low = b + (x - (b % x)) + (k-1) * x;
                up = low + x - 1;
            }
        }
        if (low != -1){
            ans += (upper_bound(a, a+n, up) - a) - (lower_bound(a, a+n, low) - a);
        }
    }
    cout << ans << "\n";
    return 0;
}
