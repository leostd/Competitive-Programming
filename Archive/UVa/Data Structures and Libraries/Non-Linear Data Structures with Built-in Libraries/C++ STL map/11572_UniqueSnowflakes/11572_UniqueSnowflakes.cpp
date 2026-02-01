#include <iostream>
#include <map>
#include <algorithm>
#define N 1000007
using namespace std;

int prv[N], arr[N];

int main()
{
    //freopen("in", "r", stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int n, a, ans = 0, aux = 0;
        map<int, int> mp;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            prv[i] = mp[arr[i]];
            mp[arr[i]] = i;
        }
        int p = 1;
        int i;
        for (i = 1; i <= n; ++i)
        {
            if (prv[i] >= p)
            {
                ans = max(ans, i-p);
                p = prv[i]+1;
            }
        }
        ans = max(ans, i-p);
        printf("%d\n", ans);
    }
    return 0;
}