#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, p, aux;
        int ps[1000];
        bool flag = false;
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p; ++i) {
            scanf("%d", &ps[i]);
        }
        int i = 0;
        for (i; i < (1 << p); ++i) {
            int sum = 0;
            for (int j = 0; j < p; ++j){
                if (i & (1 << j))
                    sum += ps[j];
            }
            if (sum == n) {
                flag = true;
                break;
            }
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}