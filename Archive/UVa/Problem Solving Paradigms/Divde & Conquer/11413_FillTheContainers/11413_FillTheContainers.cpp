#include <bits/stdc++.h>
#define N 1001
using namespace std;

int n, m, v[N];

bool f(int g){
    int acum = 0, ans = 0, i;
    for(i = 0; i < n; i++){
        if (acum + v[i] <= g)
            acum += v[i];
        else if(v[i] > g)
            return false;
        else{
            acum = v[i];
            ans++;
        }
    }
    ans++;
    return ans <= m;
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        int acum = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &v[i]);
            acum += v[i];
        }
        int l=1, r= acum, mid;
        while(r - l > 1){
            mid = l + (r-l)/2;
            if(f(mid))
                r = mid;
            else
                l = mid;
        }
        int ans = f(l) ? l : r;
        printf("%d\n", ans);
    }
    return 0;
}
