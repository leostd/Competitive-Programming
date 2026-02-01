#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    int a[1001];
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) 
            scanf("%d", &a[i]);
        long long int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; ++j)
                if (a[j] <= a[i])
                    ans++;
        }
        printf("%lli\n", ans);
    }
    return 0;
}