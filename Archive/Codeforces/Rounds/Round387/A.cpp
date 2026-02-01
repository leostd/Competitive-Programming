#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, maxd = 1, b, a;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            if (n/i == i)
                v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(n/i);
            }
            if (i > maxd && i != n)
                maxd = i;
            else if (n/i > maxd && n/i != n)
                maxd = i;
        }
    }
    b = n / maxd;
    a = max(b, maxd);
    b = min(b, maxd);
    printf ("%d %d\n", b, a);
    return 0;
}