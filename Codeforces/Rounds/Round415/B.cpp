#include <bits/stdc++.h>
using namespace std;

struct d {
    long long int k, l;
    long long int p1, p2;
};

bool cmp(d a, d b) { return a.p1 > b.p1; }
d di[100005];

int main () {
    //freopen("in", "r", stdin);
    int n, f;
    long long aux;
    scanf("%d %d", &n, &f);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &di[i].k, &di[i].l);
        aux = (di[i].k < di[i].l) ? di[i].l - di[i].k : 0;
        if (aux){
            di[i].p1 = min(aux, di[i].k);
            di[i].p2 = di[i].l - aux;
        }
        else
            di[i].p1 = 0;
    }
    sort(di, di+n, cmp);
    long long ac = 0;
    int i=0;
    for(i = 0; i < f; ++i) {
        ac += di[i].p1+di[i].p2;
        aux = di[i].p1;
        aux = di[i].k;
        aux = di[i].l;
    } 
    for(i; i < n; i++){
        ac += min(di[i].k, di[i].l);
        aux = di[i].p1;
        aux = di[i].k;
        aux = di[i].l;
    }
    cout << ac << "\n"; 
    return 0;
}