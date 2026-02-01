/* I can't get AC without Big Integer */

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long lli;

int seq[105];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int i = 0;
        while(n != -999999)
        {
            seq[i++] = n;
            scanf("%d", &n);
        }
        lli maxp = LLONG_MIN;
        for (int j = 0; j < i; j++)
        {
            maxp = max(maxp, (lli)seq[j]);
            lli acc = 1;
            for (int k = j; k < i; k++)
            {
                acc *= seq[k];
                maxp = max(maxp, acc);
            }
        }
        printf("%lli\n", maxp);
    }
    return 0;
}