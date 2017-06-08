#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int m[10][10], n;
bool check[10];

int getMin(int row) {
    int a = 0x3f3f3f3f;
    int idx = -1;
    for (int col = 0; col < n; ++col) {
        if (check[col]) continue;
        if (a > m[row][col])
        {
            a = m[row][col];
            idx = col;
        }
    }
    return idx;
}

int main() {
    //freopen("in", "r", stdin);
    int t, idx, maxs, sum;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &m[i][j]);
        memset(check, false, sizeof(check));
        vi p;
        for (int i = 0; i < n; i++)
            p.push_back(i);
        maxs = 0;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += m[i][p[i]];
        }
        maxs = sum;
        while(next_permutation(p.begin(), p.end())) {
            sum = 0;
            for (int i = 0; i < n; i++) {
                sum += m[i][p[i]];
            }
            maxs = min(sum, maxs);
        }
        printf("%d\n", maxs);
    }
    return 0;
}

