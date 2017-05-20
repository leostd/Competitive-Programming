#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct mrk
{
    int lo, hi;
    string name;
    mrk(int l, int h, string n)
    {
        lo = l; hi = h; name = n;
    }
};

int main()
{
    int t, d, m, l, aux, q;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &d);
        vector<mrk> db(d, mrk(0, 0, ""));
        for (int i = 0; i < d; i++)
            cin >> db[i].name >> db[i].lo >> db[i].hi;
        scanf("%d", &q);
        while(q--)
        {
            int flag = -1;
            bool first = true;
            scanf("%d", &aux);
            int mm;
            for (int i = 0; i < d; i++)
            {
                if (aux >= db[i].lo && aux <= db[i].hi && first)
                {
                    first = false;
                    flag = i;
                }
                else if (aux >= db[i].lo && aux <= db[i].hi && !first)
                    flag = -1;
            }
            if (flag != -1)
                printf("%s\n", db[flag].name.c_str());
            else
                printf("UNDETERMINED\n");
        }
        if (t)
        printf("\n");
    }
    return 0;
}