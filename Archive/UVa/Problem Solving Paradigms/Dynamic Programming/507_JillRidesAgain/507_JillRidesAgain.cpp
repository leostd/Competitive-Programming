#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long int lli;

int ns[1000000];

int main()
{
    int t, tc=1; 
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n-1; i++)
            scanf("%d", &ns[i]);
        lli sum, maxsum;
        int f,l, maxf, maxl;
        f = l = maxf = maxl = 0;
        sum = maxsum = 0;
        for (int i = 0; i < n-1; i++)
        {
            l = i;
            sum += ns[i];
            if (sum < 0)
            {
                f = i+1;
                sum = 0;
            }
            if (sum > maxsum ||\
            (sum == maxsum && l - f == maxl - maxf && f < maxf) ||\
            (sum == maxsum && l - f > maxl - maxf))
            {
                maxl = l;
                maxf = f;
                maxsum = sum;
            }
        }
        if (maxsum)
            printf("The nicest part of route %d is between stops %d and %d\n", tc++, maxf+1, maxl+2);
        else
            printf("Route %d has no nice parts\n", tc++);
    }
    return 0;
}