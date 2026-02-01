#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;

int main()
{
    int tc, n, c;
    vector<lli> s; // stall positions
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d", &n, &c);
        s = vector<lli> (n, 0);
        for (int i = 0; i < n; i++)
            scanf("%lli", &s[i]);
        sort(s.begin(), s.end());
        int cows; // number of cows placed
        lli max = 0; // max min distance
        lli lo = 1, hi = 10e9, mid; // Search space [1, 10^9)
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;
            cows = 1;
            int lc = s[0]; // last cow placed
            for (int i = 1; i < n; i++) // We're searching for the max minimum distance
            {
                if (s[i] - lc >= mid) // if the dist between the last placed and the current is geq then we place a new cow
                {
                    lc = s[i];
                    cows++;
                    if(cows == c)
                        break;
                }
            }
            if (cows == c)
            {
                lo = mid + 1;
                if (mid > max)
                    max = mid;
            }
            else
                hi = mid;
        }
        printf("%lli\n", max);
    }
    return 0;
}