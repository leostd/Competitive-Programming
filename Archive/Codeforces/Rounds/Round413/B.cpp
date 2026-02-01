#include <bits/stdc++.h>
using namespace std;

struct S {
    int p, bc, fc;
    S() {p = bc = fc = 0;}
    S(int _p, int _bc, int _fc) : p(_p), bc(_bc), fc(_fc) {}
    bool operator< (const S &o) const { return p < o.p; }
};

set<S> ss[4];
S arr[200007];
int bs[200007];

int main() {
    //freopen("in", "r", stdin);
    int n, pi, ai, bi, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &arr[i].p);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &arr[i].fc) ;
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i].bc);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &bs[i]);
    for (int i = 0; i < n; ++i){
        ss[arr[i].bc].insert(arr[i]);
        ss[arr[i].fc].insert(arr[i]);
    }
    long long int ans = 0;
    S aux;
    for (int i = 0; i < m; ++i) {
        if (ss[bs[i]].empty()){
            printf("-1 ");
            continue;
        }
        aux = *(ss[bs[i]].begin());
        printf("%d ", aux.p);
        ss[aux.bc].erase(aux);
        ss[aux.fc].erase(aux);
    }
    return 0;
}

