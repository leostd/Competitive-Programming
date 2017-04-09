#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;


map<char, int> nuc;

int main()
{
    string chain;
    int n, maxn = 0, eqm;
    scanf("%d\n", &n);
    char c, idx[4] = {'A', 'G', 'T', 'C'};
    bool flag;
    int it = 0;
    eqm = n / 4;
    cin >> chain;
    while(it < chain.size())
    {
        c = chain[it];
        if (chain[it++] != '?')
            nuc[c]++;
        if (nuc[c] > maxn)
            maxn = nuc[c];
    }
    if (maxn > eqm || n % 4 != 0)
        printf("===\n");
    else
    {
        it = 0;
        for (int i = 0; i < 4; i++)
        {
            while(nuc[idx[i]] != eqm)
            {
                if(chain[it] == '?')
                {
                    chain[it] = idx[i];
                    nuc[idx[i]]++;
                }
                it++;
            }
        }
        cout << chain << "\n";
    }
    return 0;
}