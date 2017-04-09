#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef long long int lli;
lli memo[1000005];

lli dp(int i)
{
    if (i == 0)
        return memo[i] = 1;
    if (memo[i] != -1)
        return memo[i];
    int id1, id2, id3;
    id1 = floor(i - sqrt(i));
    id2 = floor(log(i));
    id3 = floor(i * sin(i)*sin(i));
    memo[i] = dp(id1) + dp(id2) + dp(id3);
    memo[i] = memo[i] % 1000000;
    return memo[i];
}

int main()
{
    int i;
    memset(memo, -1, sizeof(memo));
    while(scanf("%d", &i), i != -1)
    {
        lli ans = dp(i);
        printf("%lli\n", ans);
    }
    return 0;
}