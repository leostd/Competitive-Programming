#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long int lli;

int main()
{
    int t, sc = 1;
    int e, m, k, w;
    int wi, he;
    scanf("%d\n", &t);
    lli sum;
    while(t--)
    {
        sum = 0;
        vector<int> woods;
        scanf("%d %d %d %d", &e, &m, &k, &w);
        for (int i = 0; i < e; i++)
        {
            scanf("%d %d", &he, &wi);
            if (wi < m+1)
                continue;
            else if (wi >= m+1)
            {
                int aux = wi / (m+1);
                int j = 0;
                while(j < aux && j < w)
                {
                    woods.push_back(he);
                    j++;
                }
            }
        }
        sort(woods.begin(), woods.end(), greater<int>());
        int i;
        for (i = 0; i < woods.size() && i < w; i++)
            sum += woods[i];
        sum += (i*k);
        printf("Scenario #%d: %lli\n", sc++, sum);
    }
}