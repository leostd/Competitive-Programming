#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    int kidx, didx;
    long long int sum;
    while(scanf("%d %d", &n, &m), n != 0 && m !=0)
    {
        vector<int> ds(n, 0), ks(m, 0);
        kidx = didx = 0;
        sum = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &ds[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &ks[i]);
        sort(ds.begin(), ds.end());
        sort(ks.begin(), ks.end());
        while(kidx < m && didx < n)
        {
            while(ds[didx] > ks[kidx] && kidx < m)
                kidx++;
            if (m == kidx) 
                break;
            sum += ks[kidx];
            didx++;
            kidx++;
        }
        if (didx == n)
            printf("%lli\n", sum);
        else
            printf("Loowater is doomed!\n");
    }
    return 0;
}