#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int p, dna;
    while (scanf("%d %d", &p, &dna), p || dna)
    {
        map<string, int> clones;
        vector<int> ans(p+1, 0);
        string person;
        for (int i = 0; i < p; i++)
        {
            cin >> person;
            if (clones.count(person))
            {
                ans[clones[person]]--;
                clones[person]++;
                ans[clones[person]]++;
            }
            else
            {
                ans[1]++;
                clones[person]++;
            }
        }
        for (int i = 1; i <= p; i++)
            printf("%d\n", ans[i]);
        printf("\n");
    }    
    return 0;
}