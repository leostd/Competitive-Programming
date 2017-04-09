#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long int lli;

struct wv{
    int st, ft; // start finish
    int bt;
    lli fp; // before fun
};

wv wvs[300009];
lli memo[300009];
int n;

bool cmp(wv a, wv b){
    return a.st < b.st;
}

int bs(int l, int u, int x){
    while(u > l){
        int mid = l + (u - l)/2;
        if (wvs[mid].st >= x)
            u = mid;
        else
            l = mid+1;
    }
    if (wvs[l].st >= x)
        return l;
    else 
        return -1;
}

lli dp(int id){
    if (id > n)
        return 0;
    else if (memo[id] != -1)
        return memo[id];
    else{
        memo[id] = 0;
        int idx = bs(0, n-1, wvs[id].ft);
        if (idx != -1)
            memo[id] = max(dp(id+1), dp(idx) + wvs[id].fp);
        else
            memo[id] = max(dp(id+1), wvs[id].fp);
        return memo[id];
    }
}

int main(){
    int max;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %lli %d", &wvs[i].st, &wvs[i].fp, &wvs[i].bt);
        wvs[i].ft = wvs[i].st + wvs[i].bt; // -1?
        memo[i] = -1;
    }
    sort(wvs, wvs+n, cmp);
    lli ans = dp(0);
    cout << ans << "\n";
    return 0;
}