#include<bits/stdc++.h>
#define M 11
using namespace std;
int main(){
    int n, m, bi, t[M];
    scanf("%d %d", &n, &m);
    memset(t, 0, sizeof(t));
    for(int i=0; i<n; i++){
        scanf("%d", &bi);
        t[bi-1]++;
    }
    long long int ans=0;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j<m; j++){
            ans += t[i]*t[j];
        }
    }
    cout << ans << "\n";
    return 0;
}
