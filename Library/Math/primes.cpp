#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll sqr(ll x) {
    return x*x;
}

/*
 Erathostenes Sieve

 O(NlogN)
*/
const int NPRIMES = 1e7; // max size for this algorithm
vector<int> primes;
bool isPrime[NPRIMES];
void sieve() {
    // assume all numbers are prime at the begining
    memset(isPrime, 1, sizeof(isPrime));
    
    // start from 2 as 1 is not considered a prime number
    for(int x = 2; x < NPRIMES; x++) {
        if (isPrime[x]) {
            primes.push_back(x);

            // mark as not primes all the multiples of current prime number
            for(int y = x+x; y < NPRIMES; y+=x) {
                isPrime[y] = false;
            }
        }
    }
}


/*
 * Prime factorization
 * 
 * O(sqrt(N))
 */
vector<pll> factorize(ll x) {
    vector<pll> ans;
    int curPrime = 0;
    int curPow = 0;
    ll xx = x;
    while(sqr(primes[curPrime]) < xx) {
        if (x % primes[curPrime])
            x /= primes[curPrime], curPow++;
        else {
            if (curPow > 0)
                ans.push_back(make_pair(curPrime, curPow));
            curPow = 0;
            curPrime++;
        }
    }

    if (curPow)
        ans.push_back(make_pair(curPrime, curPow));

    if (x)
        ans.push_back(make_pair(x, 1));

    return ans;
}

    