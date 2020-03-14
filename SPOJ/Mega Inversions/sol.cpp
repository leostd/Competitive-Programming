#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>

#define lsb(x) ((x)&(-x))
#define MAXN 100005
#define DEBUG 1

typedef long long ll;

using namespace std;


int n;

void update_bit(int idx, ll val, vector<ll> &bit) {
    while(idx <= n) {
        bit[idx] += val;
        idx += lsb(idx);
    }
}

ll sum(int idx, vector<ll> &bit) {
    ll res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= lsb(idx);
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    int a[MAXN];

    cin >> n;
    vector<long long> bit_min(MAXN, 0), bit_max(MAXN, 0);

    for (int i = 1; i <= n; i++) 
        cin >> a[i], update_bit(a[i], 1, bit_max);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout << a[i] << ":\n";
        update_bit(a[i], -1, bit_max);
        ll left = sum(n, bit_min) - sum(a[i], bit_min);
        //cout << "left: " << left << endl;
        ll right = sum(a[i]-1, bit_max);
        //cout << "right: " << right << endl << endl;
        if (left > 0 && right > 0) {
            ans += (left*right);
        }
        update_bit(a[i], 1, bit_min);
    }

    cout << ans << "\n";

    return 0;
}
