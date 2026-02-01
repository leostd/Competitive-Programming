#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int t;
int narr[20], sarr[20];
int main()
{
    scanf("%d", &t);
    int k = 0;
    lli n, a, b;
    bool flag;
    for (int i = 1; i <= t; ++i)
    {
        scanf("%lli", &n);
        k = 0;
        a = n;
        while(a)
        {
            sarr[k++] = a % 10;
            a /= 10;
        }
        for (int j = 0; j < k-1; j++)
        {
            if (sarr[j] < sarr[j+1])
            {
                for (int k = 0; k <= j; k++)
                    sarr[k] = 9;
                sarr[j+1]--;
            }
        }
        printf("Case #%d: ", i);
        if (sarr[k-1] != 0)
            printf("%d", sarr[k-1]);
        for (int j = k-2; j >= 0; j--)
            printf("%d", sarr[j]);
        printf("\n");
    }
    return 0;
}