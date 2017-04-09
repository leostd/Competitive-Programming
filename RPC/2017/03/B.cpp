#include <bits/stdc++.h>
using namespace std;

int arr[1000008];

struct 

int n, q;

int main ()
{
    while(scanf("%d %d", &n, &q) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);
        int l, r, k;
        sort(arr+1, arr+n+1);
        for (int i = 0; i < q; ++i)
        {
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", arr[(l-1) + k]);
        }
    }
    return 0;
}