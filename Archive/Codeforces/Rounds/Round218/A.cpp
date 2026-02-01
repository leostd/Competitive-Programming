#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int ones, twos;

int main()
{
    int n, k, a;
    int indices[102], arr[102];
    scanf("%d %d", &n, &k);
    ones = twos = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == 1)
            ones++;
        else
            twos++;
        arr[i] = a;
    }
    int x, y, c, ans;
    int mc = 1000;
    for (int j = 0; j < n/k; j++)
    {
        c = 0; // changes
        for (int m = 0; m < k; m++)
        {
            x = arr[j*k + m];
            for (int o = 0; o < n/k; o++)
            {
                if (o == j)
                    continue;
                y = arr[o*k + m];
                if (x != y)
                    c++;
            }
        }
        if (c < mc)
            mc = c;
    }
    ans = min(mc, min(ones, twos));
    printf("%d\n", ans);
    return 0;
}