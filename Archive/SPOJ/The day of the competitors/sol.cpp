#include <iostream>
#include <tuple>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define lsb(x) ((x)&(-x))

typedef long long ll;

int bit[MAXN];
int n;

void update(int idx, int val) {
    while(idx <= n) {
        bit[idx] = min(val, bit[idx]);
        idx += lsb(idx);
    }
}

int minq(int idx) {
    int res = 0x3f3f3f3f;
    while (idx > 0) {
        res = min(res,bit[idx]);
        idx -= lsb(idx);
    }
    return res;
}

int minq(int a, int b) {
    int x = minq(a-1);
    int y = minq(b);
    return min(x,y);
}
int main(){
    int t;
    cin >> t;

    while (t--){
        
        tuple<int, int, int> s[MAXN];

        cin >> n;
        int x, y, z;
        for (int i = 0; i < n; i++){
            cin >> x >> y >> z;
            s[i] = make_tuple(x,y,z);
            //cout << get<0>(s[i]) << " " << get<1>(s[i]) << " " << get<2>(s[i]) << endl;
        }

        sort(s, s+n);
        fill(bit, bit+n, 0x3f3f3f3f);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            tie(x,y,z) = s[i];
            // cout << x << y << z << endl;
            int q = minq(y-1);
            // cout << "MRQ: " << q << endl;
            ans += (z < q);
            update(y, z);
            // cout << "BIT = {";
            // for (int i = 1; i <= n; i++){
            //     cout << bit[i] << (i < n? ",": ""); 
            // }
            // cout << "}\n";
        }

        cout << ans << endl;

    }

    return 0;
}