#include <bits/stdc++.h>
#define N 100
using namespace std;

int main(){
    int n, m;
    int d[N];
    scanf("%d %d", &n, &m);
    for(int i =0; i < n; i++)
        scanf("%d", &d[i]);
    sort(d, d+n, greater<int>());
    int ans = 0, i=0;
    while(m>0){
        m-=d[i++];
        ans++;
    }
    printf("%d", ans);
    return 0;
}
