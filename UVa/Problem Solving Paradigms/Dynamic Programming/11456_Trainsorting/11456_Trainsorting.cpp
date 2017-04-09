#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int ns[2001];
int lis[2001], lds[2001];
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &ns[i]);
        for (int i = n-1; i >= 0; i--)
        {
            lis[i] = 1;
            for (int j = i+1; j < n; j++)
            {
                if (ns[j] < ns[i])
                    lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        for (int i = n-1; i >= 0; i--)
        {
            lds[i] = 1;
            for (int j = i+1; j < n; j++)
            {
                if (ns[j] > ns[i])
                    lds[i] = max(lds[i], lds[j] + 1);
            }
        }
        int best = 0;
        for (int i = 0; i < n; i++)
            best = max(best, lis[i] + lds[i] - 1);
        best = max(0, best);
        printf ("%d\n", best);
    }
    return 0;
}