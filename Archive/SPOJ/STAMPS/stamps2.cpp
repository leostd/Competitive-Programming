#include <bits/stdc++.h>
using namespace std;

int frs[1000];

int main(){
    int t, sc = 1;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        int a;
        for (int i = 0; i < m; i++)
            scanf("%d", &frs[i]);
        sort(frs, frs+m, greater<int>());
        int i;
        for (i = 0; i < m && n > 0; ++i) 
            n -= frs[i];
        if (n > 0) printf("Scenario #%d:\nimpossible\n", sc++, i);
        else printf("Scenario #%d:\n%d\n", sc++, i);
        printf("\n");
    }
    return 0;
}