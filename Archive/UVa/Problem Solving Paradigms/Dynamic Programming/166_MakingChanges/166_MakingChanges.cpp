#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;

int coins[6] = {5, 10, 20, 50, 100, 200};
int own[6];
int amount;
double aux;
lli memo[1000], memo2[1000];

lli dp2(int m)
{
    if (m == 0)
        return 0;
    if (m < 0)
        return 10000000;
    if (memo2[m] != -1)
        return memo2[m];
    lli x = 10000000;
    for(int i = 0; i < 6; i++){
        if (m - coins[i] < 0)
            break;
            x = min(x, dp2(m-coins[i]));
    }
    return memo2[m] = x + 1;
}

lli dp(int m, int c)
{
    if (m == 0)
        return 0;
    if (m < 0)
        return dp2(-m);
    if (c == 6)
        return 1000000;
    if (!own[c])
        return dp(m, c+1);
    own[c]--;
    lli a = dp(m-coins[c], c);
    own[c]++;
    lli b = dp(m, c+1);
    return min(a+1, b);
}


int main()
{
    memset(memo2, -1, sizeof(memo2));
    while(scanf("%d %d %d %d %d %d", &own[0], &own[1], &own[2], &own[3], &own[4], &own[5]))
    {
        if (!any_of(own, own+6, [](int i){return i != 0;}))
            break;
        scanf("%lf", &aux);
        amount = floor(aux * 100 + 0.5);
        memset(memo, -1, sizeof(memo));
        int nochange = dp(amount, 0);
        printf("%3d\n", nochange);
    }
    return 0;
}