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

// Maximum prime number to be considered for square
// divisibility
const int MAX_PRIME = 1e7+5;
 
// Maximum value of result. We do binary search from 1
// to MAX_RES
const int MAX_RES = 2000000000l;
 
void SieveOfEratosthenes(vector<long long> &a)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[MAX_PRIME];
    memset(prime, true, sizeof(prime));
 
    for (long long p=2; p*p<MAX_PRIME; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (long long i=p*2; i<MAX_PRIME; i += p)
                prime[i] = false;
        }
    }
 
    // Store all prime numbers in a[]
    for (long long p=2; p<MAX_PRIME; p++)
        if (prime[p])
            a.push_back(p);
}
 
// Function to count integers upto k which are having
// perfect squares as factors. i is index of next
// prime number whose square needs to be checked.
// curr is current number whos square to be checked.
long long countSquares(long long i, long long cur,
                       long long k, vector<long long> &a)
{
    // variable to store square of prime
    long long square = a[i]*a[i];
 
    long long newCur = square*cur;
 
    // If value of greatest integer becomes zero
    if (newCur > k)
        return 0;
 
    // Applying inclusion-exclusion principle
 
    // Counting integers with squares as factor
    long long cnt = k/(newCur);
 
    // Inclusion (Recur for next prime number)
    cnt += countSquares(i+1, cur, k, a);
 
    // Exclusion (Recur for next prime number)
    cnt -= countSquares(i+1, newCur, k, a);
 
    // Final count
    return cnt;
}
 
// Driver Program
int main()
{
    // Computing primes and storing it in an array a[]
    vector <long long> a;
    SieveOfEratosthenes(a);
    int t;
    cin >> t;
    long long n;
    while(t--) {
      cin >> n;
      cout << n - countSquares(0,1,n,a) << endl;
    }
    return 0;
}