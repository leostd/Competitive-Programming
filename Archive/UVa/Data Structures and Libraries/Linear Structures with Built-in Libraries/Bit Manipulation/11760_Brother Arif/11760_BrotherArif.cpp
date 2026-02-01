#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
using namespace std;

typedef long long int lli;

int main()
{
    int row, col;
    int a, b;
    int sc = 1;
    lli n;
    while(scanf("%d %d %lli", &row, &col, &n), row || col || n)
    {
        bool flag = true;
        bitset<10000> cr;
        bitset<10000> cc;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            cc[b] = 1;
            cr[a] = 1;
        }
        scanf("%d %d", &a, &b);
        if ((!cc[b] && !cr[a]) || (!cc[b] && a-1 >= 0 && !cr[a-1]) || (!cc[b] && a+1 < row && !cr[a+1]) || (!cr[a] && b-1 >= 0 && !cc[b-1]) || (!cr[a] && b+1 < col && !cc[b+1]))
            flag = false;
        if (flag)
            printf("Case %d: Party time! Let's find a restaurant!\n", sc++);
        else
            printf("Case %d: Escaped again! More 2D grid problems!\n", sc++);        
    }
    return 0;
}