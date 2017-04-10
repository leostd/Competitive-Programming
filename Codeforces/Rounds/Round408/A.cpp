#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int hs[200];

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &hs[i]);
    int a, b, ans;
    bool flag1 = false;
    bool flag2 = false;
    for (a = m; a <= n && !flag1; a++)
        if (hs[a] != 0 && hs[a] <= k)
        {
            flag1 = true;
            break;
        }
    
    for (b = m; b >= 1 && !flag2; b--)
        if (hs[b] != 0 && hs[b] <= k)
        {
            flag2 = true;
            break;
        }
    if (flag1 && flag2)
        ans = min(abs(a-m), abs(b-m));
    else if (flag1 && !flag2)
        ans = abs(a - m);
    else
        ans = abs(b - m);
    printf("%d\n", ans * 10);
    return 0;
}