#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, tc=1;
    char ch;
    scanf("%d", &t);
    char f[200];
    bool m[200];
    while(t--){
        memset(m, 0, sizeof(m));
        int ans = 0;
        scanf("%d\n", &n);
        for(int i = 0; i < n; i++){
            ch = getchar();
            f[i] = ch;
        }
        for(int i = 0; i < n-1; i++){
            if (!m[i] && f[i] == '.'){
                m[i] = m[i+1] = m[i+2] = true;
                ans++;
            }
        }
        if (!m[n-1] && f[n-1] == '.')
            ans++;
        printf("Case %d: %d\n",tc++, ans);
    }
    return 0;
}
