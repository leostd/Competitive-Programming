#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define INF INT_MAX
using namespace std;

typedef long long int lli;

struct Cylinder{
    int ox;
    int nt;
    int wt;
    Cylinder(int o=0, int n=0, int w=0){
        ox = o;
        nt = n;
        wt = w;
    }
};

Cylinder cs[1005];
lli memo[1005][35][85];
int t, a, q;

lli dp(int id, int ox, int nt){
    if (id > q)
        return INF;
    if (id == q && (ox > 0 || nt > 0))
        return INF;
    else if(ox <= 0 && nt <= 0)
        return 0;
    else if (memo[id][max(0, ox)][max(0, nt)] != -1)
        return memo[id][max(0,ox)][max(0,nt)];
    else{
        lli x = dp(id+1, ox, nt);
        lli y = cs[id].wt + dp(id+1, ox - cs[id].ox, nt - cs[id].nt);
        memo[id][max(0,ox)][max(0,nt)] = min(x, y);
        return memo[id][max(0,ox)][max(0,nt)];
    }
}

int main(){
    int c;
    scanf("%d", &c);
    while(c--){
        scanf("%d %d", &t, &a);
        scanf("%d", &q);
        for (int i = 0; i <= q; i++)
            for (int j = 0; j <= t; j++)
                for (int k = 0; k <= a; k++)
                    memo[i][j][k] = -1;
        for (int i = 0; i < q; i++)
            scanf("%d %d %d", &cs[i].ox, &cs[i].nt, &cs[i].wt);
        lli ans = dp(0, t, a);
        printf("%lli\n", ans);

    }
    return 0;
}