#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int t, n;
    long long unsigned k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %llu", &n, &k);
        printf("%llu\n", k^(k >> 1));
    }
    return 0;
}