#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int cs[1000007];

int main()
{   
    int a, b, ans;
    memset(cs, 0, sizeof(cs));
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        cs[a] = 1; // hole
    }
    if (cs[1] == 1)
    {
        printf("%d\n", 1);
        return 0;
    }
    cs[1] = 2; // bone
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &a, &b);
        int bone = 0, hole = 0, cup = 0;
        if (cs[a] == 2)
            bone = a;
        else if (cs[b] == 2)
            bone = b;
        if (!bone)
            continue;
        if (cs[a] == 1)
            hole = a;
        else if (cs[b] == 1)
            hole = b;
        if (hole && bone)
        {
            ans = hole;
            break;
        }
        // bone at the cup
        if (cs[a] == 0)
        {
            cs[a] = 2;
            cs[bone] = 0;
            ans = a;
        }
        else if (cs[b] == 0)
        {
            cs[b] = 2;         
            cs[bone] = 0;
            ans = b;
        }
    }
    printf("%d\n", ans);
    return  0;
}