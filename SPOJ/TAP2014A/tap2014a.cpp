#include <bits/stdc++.h>
using namespace std;

struct card {
    int n, s;
};

bool check(card a, card b) {
    return (a.s == b.s || a.n == b.n);
}

int main() {
    //freopen("in", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        card cs[58];
        int n;
        scanf("%d", &n);
        int a, b;
        for(int i = 0; i < n; i++){
            scanf("%d %c", &a, &b);
            cs[i].n = a;
            cs[i].s = b;
        }
        bool flag = true;
        for(int i = 1; i < n; ++i) {
            if (check(cs[i-1], cs[i])){
                flag = false;
                break;
            }
        }
        if (flag)
            printf("B\n");
        else
            printf("M\n");
    }
    return 0;
}