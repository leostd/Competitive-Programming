#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

vi frs;

int main()
{
    int scns, need, fs;
    scanf("%d", &scns);
    for (int i = 1; i <= scns; i++)
    {
         scanf("%d %d", &need, &fs);
         frs = vi(fs, 0);
         for (int j = 0; j < fs; j++)
            scanf("%d", &frs[j]);
        sort(frs.begin(), frs.end(), greater<int>());
        bool flag = true;
        for (int j = 0; j < fs; j++)
        {
            need -= frs[j];
            if (need <= 0)
            {
                printf("Scenario #%d:\n%d\n\n", i, j+1);
                flag = false;
                break;
            }
        }
        if (flag)
            printf("Scenario #%d:\nimpossible\n\n", i);
    }
    return 0;
}