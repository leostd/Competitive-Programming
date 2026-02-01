#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> h, s, ans;

int main()
{
    int t, tc=1;
    int a, b;
    int n, r;
    scanf("%d", &t);
    while(t--)
    {
        h.clear();
        s.clear();
        scanf("%d %d", &n, &r);
        ans = vector<int>(n*n,0); // n^2 cause we need space for the intersection
        for (int i = 0; i < r; i++)
        {
            scanf("%d %d", &a, &b);
            s.push_back(a);
            h.push_back(b);
        }
        sort(s.begin(), s.end());
        sort(h.begin(), h.end());
        auto it = set_intersection(s.begin(), s.end(), h.begin(), h.end(), ans.begin());
        ans.resize(it - ans.begin());
        if (ans.size())
            printf("Scenario #%d: spied", tc++);
        else
            printf("Scenario #%d: spying", tc++);
        printf("\n");
    }
    return 0;
}