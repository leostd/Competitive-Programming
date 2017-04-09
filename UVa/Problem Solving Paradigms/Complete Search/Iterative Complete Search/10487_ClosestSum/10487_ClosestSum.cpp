#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;

typedef long long int lli;
vector<lli> ns;

int main()
{
    int n, q, cs = 1;
    long long int sum, t;
    while(scanf("%d", &n), n != 0)
    {
        ns = vector<lli>(n, 0);
        for (int i = 0; i < n; i++)
            scanf("%lli", &ns[i]);
        //sort(ns.begin(), ns.end(), greater<lli>());
        scanf("%d", &q);
        printf("Case %d:\n", cs++);
        for (int i = 0; i < q; i++)
        {
            sum = INT32_MAX;
            scanf("%lli", &t);
            for (int j = 0; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    lli aux = ns[j] + ns[k];
                    if (abs(aux - t) < abs(t - sum))
                            sum = ns[j] + ns[k];
                }
            }
            printf("Closest sum to %lli is %lli.\n", t, sum);
        }   
        
    }
}