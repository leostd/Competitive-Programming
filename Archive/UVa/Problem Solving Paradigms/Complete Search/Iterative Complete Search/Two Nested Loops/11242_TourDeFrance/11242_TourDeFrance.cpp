#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in", "r", stdin);
    int f, r;
    int fs[10], rs[10]; 
    double ds[102];
    while (scanf("%d %d", &f, &r) == 2) {
        for (int i = 0; i < f; ++i)
            scanf("%d", &fs[i]);
        for (int i = 0; i < r; ++i)
            scanf("%d", &rs[i]);
        int k = 0;
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < r; ++j){
                double aux = (double)rs[j] / fs[i];
                ds[k++] = (double)rs[j] / fs[i];
            }
        }
        sort(ds, ds+k);
        double ans = -1.0, aux;
        for (int i = 1; i < k; ++i) {
            ans = max(ans, (double)ds[i]/ds[i-1]);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}