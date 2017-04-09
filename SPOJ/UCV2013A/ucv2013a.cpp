#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef long long int lli;

// a ^ b
lli fpow(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    else if(b % 2 == 0)
        return (fpow(a, b/2) * fpow(a, b/2)) % 1000000007;
    else
        return (a * fpow(a, b-1)) % 1000000007;
}

int main()
{
    int n, l;
    lli res, aux;
    while(scanf("%d %d", &n, &l), n != 0 || l != 0)
    {
        res = 0;
        for (int i = 1; i <= l; i++)
        {
            res += (fpow(n, i));
        }
        printf("%lli\n", res % 1000000007);
    }
    return 0;
}