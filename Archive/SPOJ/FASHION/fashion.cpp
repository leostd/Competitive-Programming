#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int lli;

int main()
{
    int t, n;
    vi m, w;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        m = vi(n, 0);
        w = vi(n, 0);
        for (int i = 0; i < n; i++)
            scanf("%d", &m[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &w[i]);
        sort(m.begin(), m.end());
        sort(w.begin(), w.end());
        lli ht = 0;
        for (int i = 0; i < n; i++)
            ht += (m[i] * w[i]);
        printf("%lli\n", ht);
    }
    return 0;
}