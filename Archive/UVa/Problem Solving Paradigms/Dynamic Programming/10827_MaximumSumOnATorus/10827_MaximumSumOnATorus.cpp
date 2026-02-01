#include <bits/stdc++.h>
#define N 500
#define INF 0x3f3f3f3f
using namespace std;

int g[N][N], n;

int maxSum1d(int arr[N]){
    int sum = 0, maxSum = -INF;
    for(int i = 0; i < 2*n; i++){
        sum = 0;
        for(int j = i, k = 0; k < n; k++, j++){
            sum+=arr[j];
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}


int findMaxSum(){
    int maxSum = -INF, sum = 0, left, right, top, bottom;
    int temp[N];
    for(left = 0; left < 2*n; left++){
        memset(temp, 0, sizeof(temp));
        for (int offset = 0; offset < n; offset++){
            for(int i = 0; i < 2*n; i++){
                temp[i] += g[i][left+offset];
            }
            sum = maxSum1d(temp);
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                scanf("%d", &g[i][j]);
                g[i+n][j] = g[i][j+n] = g[i+n][j+n] = g[i][j];
            }

        int ans = findMaxSum();
        cout << ans << "\n";
    }
    return 0;
}
