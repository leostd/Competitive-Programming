#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int lli;

vector<lli> h, w, lis, lds;
lli maxlis, maxlds;

int main()
{
    int tc, c = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        int n;
        scanf("%d", &n);
        h = w = lis = lds = vector<lli>(n, 0);
        for (int i = 0; i < n; i++)
            scanf("%lli", &h[i]);
        for (int i = 0; i < n; i++)
            scanf("%lli", &w[i]);
        lis[0] = lds[0] = maxlis = maxlds = w[0];
        for (int i = 1; i < n; i++)
        {
            lli mlis = 0, mlds = 0;
            for (int j = 0; j < i; j++)
            {
                if (h[j] < h[i])
                    mlis = max(mlis, lis[j]);
                if (h[j] > h[i])
                    mlds = max(mlds, lds[j]);
            }
            lis[i] = mlis + w[i];
            lds[i] = mlds + w[i];
            if (lis[i] > maxlis)
                maxlis = lis[i];
            if (lds[i] > maxlds)
                maxlds = lds[i];
        }
        if (maxlis >= maxlds)
            printf("Case %d. Increasing (%lli). Decreasing (%lli).\n", c++, maxlis, maxlds);
        else
            printf("Case %d. Decreasing (%lli). Increasing (%lli).\n", c++, maxlds, maxlis);
    }
    return 0;
}