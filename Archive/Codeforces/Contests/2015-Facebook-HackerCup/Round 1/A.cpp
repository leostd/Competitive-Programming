#include <bits/stdc++.h>
#define N 10000001
using namespace std;

bitset<N> prime;
int primacity[N];

void sieve()
{
    prime.set();
    memset(primacity, 0, sizeof(primacity));
    for (int p = 2; p <= N; p++)
    {
        if (prime[p])
        {
            primacity[p]++;
            for (int i=2*p; i <= N; i += p)
            {
                prime[i] = false;
                primacity[i]++;
            }
        }
    }
}

int main()
{
    int t, a, b, k, r;
    sieve();
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        if (i != 0)
            printf("\n");
        r = 0;
        scanf("%d %d %d", &a, &b, &k);
        for (int j = a; j <= b; ++j)
            if (primacity[j] == k)
                r++;
        printf("Case #%d: %d", i+1, r);
    }
    return 0;
}