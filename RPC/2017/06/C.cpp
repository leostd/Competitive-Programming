#include <bits/stdc++.h>
using namespace std;

struct mis {
    int x, a, d;
    bool operator <(const mis &b) const {
        if (x != b.x)
            return x < b.x;
        else if(a != b.a)
            return a < b.a;
        else if (d != b.d)
            return d < b.d;
    }
    bool operator==(const mis &b) const {
        return x == b.x && a == b.a && d == b.d;
    }
};

set<mis> mida, midb;

int main() {
    //freopen("in", "r", stdin);
    int t;
    char ans[2][50] = {"IMPOSSIBLE", "POSSIBLE"};
    scanf("%d", &t);
    mis vt[30];
    bool flag;
    while(t--) {
        int x,a,d,m;
        scanf("%d %d %d %d", &x, &a, &d, &m);
        mida.clear(); midb.clear();
        mis mi;
        flag = false;
        for (int i = 0; i < m; i++)
            scanf("%*s %d %d %d", &vt[i].x, &vt[i].a, &vt[i].d);
        int m1, m2;
        m1 = m/2 + m%2; m2 = m/2;
        for (int i = 0; i < (1 << m1); ++i){
            mi.x = mi.a = mi.d = 0;
            for (int j = 0; j < m1; ++j){
                if ((1<<j) & i) {
                    mi.a += vt[j].a;
                    mi.x += vt[j].x;
                    mi.d += vt[j].d;
                }
            }
            if (mi.a <= a && mi.x <= x && mi.d <= d)
                mida.insert(mi);
        }
        for (int i = 0; i < (1<<m2); ++i) {
            mi.x = mi.a = mi.d = 0;
            for (int j = 0; j < m2; j++) {
                if ((1<<j) & i) {
                    mi.a += vt[j+m1].a;
                    mi.x += vt[j+m1].x;
                    mi.d += vt[j+m1].d;
                }
            }
            if (mi.a <= a && mi.x <= x && mi.d <= d)
                midb.insert(mi);
        }
        for (auto it = mida.begin(); it != mida.end(); ++it) {
            mi.x = x - it->x;
            mi.a = a - it->a;
            mi.d = d - it->d;
            flag = midb.find(mi) != midb.end();
            if(flag) break;
        }
        printf("%s\n", ans[flag]);
    }
}