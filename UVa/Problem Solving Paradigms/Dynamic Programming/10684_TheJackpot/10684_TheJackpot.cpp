#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int ns[100000];

int main()
{
    int n;
    while(scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &ns[i]);
        lli maxsum, sum;
        maxsum = sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ns[i];
            if (sum < 0)
                sum = 0;
            maxsum = max(maxsum, sum);
        }
        if (maxsum == 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %lli.\n", maxsum);
    }
    return 0;
}