#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <tuple>

using namespace std;

#define MAXN 500001
#define lsb(x) ((x)&(-x))

typedef tuple<int,int,int> iii;

int n;

int bit[MAXN];

void update(int idx, int val) {
    while (idx <= n) bit[idx] = min(val, bit[idx]), idx += lsb(idx);
}

int query(int idx) {
    int ans = 0x3f3f3f3f;
    while (idx > 0) ans = min(ans,bit[idx]), idx -= lsb(idx);
    return ans;
}

void set_tuple(iii &t, int x, int y, int z){
    get<0>(t) = x;
    get<1>(t) = y;
    get<2>(t) = z;
}

void print_tuple(iii &t) {
    cout << get<0>(t) << get<1>(t) << get<2>(t) << "\n";
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    tuple<int, int, int> s[MAXN];
    int x,y,z;

    for (int i = 0; i < n; i++) 
        cin >> x >> y >> z, set_tuple(s[i],x,y,z);

    sort(s, s+n);
    fill(bit, bit+n, 0x3f3f3f3f);

    int ans = 0, aux;
    for (int i = 0; i < n; i++) {
        tie(x,y,z) = s[i];
        aux = query(y-1);
        ans += (z < aux);
        // cout << x << " " << y << " " << z << endl;
        // cout << "Query: " << aux << endl;
        update(y, z);
    }

    cout << ans << "\n";

    return 0;
}