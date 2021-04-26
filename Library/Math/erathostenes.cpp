#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+5;
bool isPrime[MAXN];
vector<int> primes;

void sieve(int n) {
    fill(isPrime, isPrime+n, 1);
    for(int x = 2; x <= n; x++) {
        if (isPrime[x]) {
            primes.push_back(x);
            for(int y = x+x; y <= n; y+=x)
                isPrime[y] = false;
        }
    }
}


int main() {
    sieve(1000000);
    assert(primes[0] == 2 && primes.size() > 1 && primes[1] == 3);
    return 0;
}