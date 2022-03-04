#pragma GCC diagnostic ignored "-Wunused-const-variable"

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

#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)

 
typedef long long ll;
 
void fastIO() {
    cin.sync_with_stdio(false);
    cin.tie(0);
}

const int MAXN = 1e7+5;

ll n, m; // sizes
bool isPrime[MAXN];
int mu[MAXN];
vector<ll> primes;


void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    memset(mu, 0, sizeof(mu));
    mu[1] = 1;
    for(int x=2;x<MAXN;x++)
	{
		if(isPrime[x]) {
            primes.pb(x);
            mu[x] = -1;
        }
		for(int j=0; j < (int)primes.size() && primes[j]*x < MAXN;j++)
		{
			isPrime[x*primes[j]] = 0;
			if (x%primes[j] == 0) break;
			
            mu[x*primes[j]] = (-1)*mu[x];
		}
	}
}

void solve() {
    cin >> n;
    ll ans = 0;
    m = primes.size();
    for(ll i = 2; i*i <= n; i++) {
        if (mu[i])
            ans += (mu[i]*-1) * (n/(i*i));
    }

    cout << n - ans << endl;
}

int main() {
    fastIO();
    sieve(); 
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}