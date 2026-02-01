#include <bits/stdc++.h>
using namespace std;

struct Domino
{
    int p1, p2;
};

Domino d1, d2, ds[20];
int n, m;
bool check[20];

bool solve (int idx, Domino prev) {
    bool flag = false;
    if (idx + 1 == n) { // last piece
        for (int i = 0; i < m; i++) {
            if (check[i]) continue;
            if (prev.p2 == ds[i].p1 && ds[i].p2 == d2.p1)
                return true;
            if (prev.p2 == ds[i].p2 && ds[i].p1 == d2.p1)
                return true;
        }
    }
    for (int i = 0; i < m; i++) {
        if (check[i]) continue;
        if (prev.p2 == ds[i].p1){
            check[i] = true;
            flag = solve (idx+1, ds[i]);
            check[i] = false;
        }
        else if (prev.p2 == ds[i].p2) {
            check[i] = true;
            swap(ds[i].p1, ds[i].p2);
            flag = solve (idx+1, ds[i]);
            check[i] = false;
        }
        if (flag) break;
    }
    return flag; 
}

int main()
{
    //freopen("in", "r", stdin);
    while (scanf("%d", &n), n)
    {
        scanf("%d", &m);
        scanf("%d %d", &d1.p1, &d1.p2);
        scanf("%d %d", &d2.p1, &d2.p2);
        for (int i = 0; i < m; ++i)
            scanf("%d %d", &ds[i].p1, &ds[i].p2);
        memset(check, 0, sizeof(check));
        bool flag = solve(0, d1);
        printf((flag ? "YES\n" : "NO\n"));
    }
    return 0;
}