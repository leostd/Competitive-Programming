#include <iostream>
#include <set>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    int n, m;
    while(scanf("%d %d", &n, &m), n || m)
    {
        set<int> jk, jl, bth;
        int a;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            jl.insert(a);
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &a);
            if (jl.count(a))
                bth.insert(a);
        }
        printf("%d\n", bth.size());
    }
    return 0;
}