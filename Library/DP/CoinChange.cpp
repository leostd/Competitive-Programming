/*
    Minima cantidad de elementos que suman S. 
    Minima cantidad necesaria de monedas para dar un cambio de S

    Relacion de recurrencia:
    dp(sum): 0    si sum == 0
    dp(sum): INF  si sum < 0
    dp(sum): 1 + min(dp(sum-coins[i])). 0 <= i < NCOINS

    Complejidad en tiempo(Sn)
    Complejidad en espacio(S)

    Donde S es la suma de dinero y n es el numero
    de diferentes denominaciones que se tienen
*/

#include <bits/stdc++.h>
#define NCOINS 5
using namespace std;

int coins[5] = {1,2,3,4,5};
int memo[1000];

//Top-Down
int dp(int sum) {
    if (sum == 0)
        return 0;
    else if (sum < 0)
        return 0x3f3f3f3f;
    else if (memo[sum] != -1)
        return memo[sum];
    int ans = 0x3f3f3f3f;
    for (int i=0; i < NCOINS; ++i)
        ans = min(ans, dp(sum-coins[i]));
    return memo[sum] = ans + 1;
}

int main() {
    int money;
    memset(memo, -1, sizeof(memo));
    while(scanf("%d", &money), money){
        printf("%d\n", dp(money));
    }
    return 0;
}