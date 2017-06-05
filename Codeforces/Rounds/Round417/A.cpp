#include <bits/stdc++.h>
using namespace std;

struct part{
    bool l, s, r, p;
};

int main() {
    //freopen("in", "r", stdin);
    part ps[4];
    bool flag = false;
    for (int i = 0; i < 4; i++) 
        scanf("%d %d %d %d", &ps[i].l, &ps[i].s, &ps[i].r, &ps[i].p);
    for (int i = 0; i < 4; i++) {
        if (ps[i].l+ps[i].s+ps[i].r >= 1 && ps[i].p)
        {
            flag = true;
            break;
        }
        if (ps[i].l && ps[(i-1+4)%4].p) flag = true;
        if (ps[i].r && ps[(i+1)%4].p) flag = true;
        if (ps[i].s && ps[(i+2)%4].p) flag = true;
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}