#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#define N 10000000
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

bitset<N> primes;
vi pv;


void sieve()
{
    primes.set();
    primes[0] = 0;
    primes[1] = 0;
    for(long long int p = 2; p*p <= N; p++)
    {
        if (primes[p] == true)
        {
            for (long long int i = p*2; i <= N; i += p)
                primes[i] = false;
            pv.push_back(p);
        }
    }
}


bool isPrime(lli n)
{
    if (n < N)
        return primes[n];
    for (int i = 0; i < pv.size(); i++)
        if(n % pv[i] == 0) return false;
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int p, n;
    cin >> p;
    sieve();
    while(p--)
    {
        cin >> n;
        if (isPrime(n))
            printf("Prime\n");
        else
            printf("Not prime\n");
    }
    return 0;
}