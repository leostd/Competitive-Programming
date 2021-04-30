#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#ifdef MAC
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
#include <complex>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#else
#include <bits/stdc++.h>
#endif
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
void solve() {
 
    int N; ll C; cin >> N >> C;
 
    ll A[N]; F0R(i, N) cin >> A[i];
    ll B[N-1]; F0R(i, N-1) cin >> B[i];
    ll dp1[N], dp2[N];
    dp1[0] = 0; dp2[0] = 0;
    ll ans = 1e18;
    F0R(i, N) {
        ckmin(ans, dp1[i] + max((C - dp2[i] + A[i] - 1) / A[i], 0ll));
        if (i == N-1) break;
        ll val = max((B[i] - dp2[i] + A[i] - 1) / A[i], 0ll);
        dp1[i+1] = dp1[i] + val + 1;
        dp2[i+1] = dp2[i] + val * A[i] - B[i];
    }
 
    cout << ans << nl;
 
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
 
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
 