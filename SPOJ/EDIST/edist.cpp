#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <limits.h>
#include <iostream>
#define INF INT_MAX
using namespace std;

typedef long long int lli;
int memo[5000][5000];
string a, b;

int dp(int i, int j){
    if (i == -1)
        return j+1;
    else if (j == -1)
        return i+1;
    else if (memo[i][j] < INF)
        return memo[i][j];
    else{
        if (a[i] == b[j])
            memo[i][j] = dp(i-1, j-1);
        else{
            int x = dp(i-1, j) + 1;
            int y = dp(i-1, j-1) + 1;
            int z = dp(i, j-1) + 1;
            memo[i][j] = min(x,min(y, z));
        }
        return memo[i][j];
    }
}

int main(){
    int n, m, tc, ans;
    scanf("%d", &tc);
    while(tc--){
        cin >> a >> b;
        n = a.size();
        m = b.size();
        for (int i = 0; i < n+1; i++)
            for (int j = 0; j < m+1; j++)
                memo[i][j] = INF;
        ans = dp(n-1, m-1);
        printf("%d\n", ans);
    }
    return 0;
}