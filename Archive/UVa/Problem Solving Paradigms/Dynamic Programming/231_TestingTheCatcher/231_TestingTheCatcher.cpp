#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;

int lds[1000000], ns[1000000];
int main()
{
    int num = 1, tc = 1;
    bool first = true;
    while(true)
    {
        int maxds = 0, mds, i = 0;
        scanf("%d", &num);
        if (num == -1) 
            break;
        while(num != -1)
        {
            if (num != -1)
                ns[i++] = num;
            scanf("%d", &num);
        }
        memset(lds, 0, sizeof(lds));
        lds[0] = 1;
        for (int j = 0; j < i; j++)
        {
            mds = 0;
            for (int k = 0; k < j; k++)
            {
                if (ns[k] >= ns[j])
                    mds = max(mds, lds[k]);
                lds[j] = mds+1;
            }
            if (mds+1 > maxds)
                    maxds = mds+1;
        }
        if (!first)
            printf("\n");
        first = false;
        printf("Test #%d:\n  maximum possible interceptions: %d\n", tc++, maxds);
    }
    return 0;
}