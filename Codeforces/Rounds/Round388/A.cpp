#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
using namespace std;

vector<int> primes;

int main()
{
    int n;
    scanf("%d", &n);
    while(n >= 2 && n != 3)
    {
        n = n - 2;
        primes.push_back(2);
    }
    if (n == 3)
        primes.push_back(3);
    printf("%lu\n", primes.size());
    for (int i = 0; i < primes.size(); i++)
        printf("%d ", primes[i]);
    printf("\n");
    return 0;
}