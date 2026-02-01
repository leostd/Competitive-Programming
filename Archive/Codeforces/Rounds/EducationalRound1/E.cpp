#include <bits/stdc++.h>
#define M 31
#define N 31
#define K 51
#define INF 0x3f3f3f3f
using namespace std;


int n,m,k;
int memo[M][N][K];

int dp(int rows, int cols, int req){
    if (rows * cols < req)
        return INF;
    else if (rows * cols == req || req == 0)
        return 0;
    else if (memo[rows][cols][req] != -1)
        return memo[rows][cols][req];
    int &ans = memo[rows][cols][req];
    ans = INF;
    for (int i = 1; i <  rows; i++){
        for(int j = 0; j <= req; j++){
            int a = (cols*cols) + dp(i, cols, j) + dp(rows-i, cols, req-j);
            ans = min(ans, a);
        }
    }
    for(int i = 1; i < cols; i++){
        for (int j = 0; j <= req; j++){
            int a = (rows*rows) + dp(rows, i, j) + dp(rows, cols-i, req-j);
            ans = min(ans, a);
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < t; i++){
        scanf("%d %d %d", &n, &m, &k);
        int ans = dp(n, m, k);
        printf("%d\n", ans);
    }
    return 0;
}