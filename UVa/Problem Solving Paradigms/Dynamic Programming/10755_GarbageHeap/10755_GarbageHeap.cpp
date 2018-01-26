#include <bits/stdc++.h>
#define N 21
using namespace std;

typedef long long int lli;

lli g[N][N][N];
int a, b, c, t;

lli kadane(lli arr[N]){
    lli sum = 0, maxSum = -21474836480, maxAux;
    maxAux = maxSum;
    bool flag = false;
    for(int i = 0; i < c; i++){
        sum += arr[i];
        if (arr[i] >= 0) flag = true;
        if (sum < 0){
            maxAux = max(sum, maxAux);
            sum = 0;
            continue;
        }else if (sum > maxSum)
            maxSum = sum;
    }
    if (flag)
        return maxSum;
    else
        return maxAux;
}

lli kadane2d(lli mat[N][N]){
    lli maxSum = -21474836480, temp[N], sum;
    int left, right;
    for(left = 0; left < b; left++){
        memset(temp, 0, sizeof(temp));
        for(right = left; right < b; right++){
            for(int i = 0; i < c; i++)
                temp[i] += mat[right][i];
            sum = kadane(temp);
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

lli findMaxSum(){
    lli maxSum = -21474836480, temp[N][N], sum;
    int left, right;
    for(left = 0; left < a; left++){
        memset(temp, 0, sizeof(temp));
        for(right = left; right < a; right++){
            for(int i = 0; i < b; i++)
                for(int j = 0; j < c; j++)
                    temp[i][j] += g[right][i][j];
            sum = kadane2d(temp);
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int main(){
    lli aux=-21474836480;
    bool first = true;
    scanf("%d", &t);
    while(t--){
        memset(g, 0, sizeof(g));
        scanf("%d %d %d", &a, &b, &c);
        for (int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                for(int k = 0; k < c; k++){
                    scanf("%lli", &g[i][j][k]);
                    aux = max(aux, g[i][j][k]);
                }
        if (!first)
            cout << "\n";
        else
            first = false;
        if(aux >= 0){
            lli ans = findMaxSum();
            cout << ans << "\n";
        } else
            cout << aux << "\n";
    }
    return 0;
}
