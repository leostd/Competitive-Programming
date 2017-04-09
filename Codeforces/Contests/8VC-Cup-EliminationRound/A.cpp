#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#define N 1005000
using namespace std;

bitset<N> primes;

void getPrimes()
{
    for (int p = 2; p * p <= N; p++){
        if (primes[p])
        {
            for (int i = p*2; i < N; i += p)
                primes[i] = false;
        }
    }
}

int main(){
    primes.set();
    getPrimes();
    int n;
    scanf("%d", &n);
    int i = 1;
    while(primes[i*n + 1])
        i++;
    printf("%d\n", i);
    return 0;
}