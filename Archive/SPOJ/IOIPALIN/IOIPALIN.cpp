#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 0x3f3f3f3f
using namespace std;
 
int memo[6110][6110];
char a[5100], b[5100];
int t;
 
int dp (int ia, int ib){
    if (ia == -1 || ib == -1 || (t-1-ib) + (t-1-ia) > t-1)
        return 0;
    else if (memo[ia][ib] != -1)
        return memo[ia][ib];
    else{
        if (a[ia] == b[ib]){
            memo[ia][ib] = dp(ia-1,ib-1);
        }else{
            memo[ia][ib] = min(dp(ia, ib-1) + 1, dp(ia-1, ib) + 1);
        }
        return memo[ia][ib];
    }
 
}
 
int main()
{
    //freopen("ioipalin.txt", "r", stdin);
    scanf("%d", &t);
    scanf("%s", a);
    for (int i = 0; i <= t; i++)
        for (int j = 0; j <= t; j++)
            memo[i][j] = -1;
    for (int i = t-1; i >= 0; i--)
        b[t - i - 1] = a[i];
    int ans = dp(t-1, t-1);
    printf("%d\n", ans);
    return 0;
}
