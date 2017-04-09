#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int s, b, tc = 1;
    while(scanf("%d %d", &b, &s), s != 0 || b != 0)
    {
        vector<int> ss(s, 0), bs(b, 0);
        for (int i = 0; i < b; i++)
            scanf("%d", &bs[i]);
        for (int i = 0; i < s; i++)
            scanf("%d", &ss[i]);
        sort(bs.begin(), bs.end());
        printf("Case %d: ", tc++);
        if (bs.size() <= ss.size())
            printf("0\n");
        else
            printf("%lu %d\n", bs.size() - ss.size(), bs[0]);
    }
    return 0;
}