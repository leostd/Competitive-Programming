#include <bits/stdc++.h>
using namespace std;

bool colcheck[101];

int main() {
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d %d\n", &n, &m);
    memset(colcheck, 0, sizeof(colcheck));
    char g[101][101];
    for (int i = 0; i < n; ++i){
        for (int col = 0; col < m; ++col){
            scanf("%c ", &g[i][col]);
            char aux = g[i][col];
        }
    }
    int ans = 0, prev = 0, pos;
    bool first = true;
    bool flag = false;
    do{
        pos = 0;
        flag = false;
        for (int row = 0; row < n-1; row++) {
            for (int col = 0; col < m; col++) {
                if (colcheck[col]) continue;
                char aux1 = g[row][col];
                char aux2 = g[row+1][col];
                if (g[row][col] == g[row+1][col]) continue;
                if (g[row][col] > g[row+1][col]) {
                    prev = ans;
                    ans++;
                    colcheck[col] = true;
                    flag = true;
                    break;
                }
                if (g[row][col] < g[row+1][col]){
                    break;
                }
            }
            if (flag){
                break;
            }
        }
    }while(flag);
    printf("%d\n", ans);
    return 0;
}