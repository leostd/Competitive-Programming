#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

map<string, int> wins;
map<string, int> gavg;

int main()
{
    int t, g1, g2, maxwins = 0;;
    string e1, e2, winner;
    scanf("%d", &t);
    while(t--)
    {
        for (int i = 0; i < 16; ++i)
        {
            cin >> e1 >> e2 >> g1 >> g2;
            gavg[e1] += (g1 - g2);
            gavg[e2] += (g2 - g1);
            if (g1 > g2)
            {
                wins[e1]++;
                if (wins[e1] > maxwins || (wins[e1] == maxwins && gavg[e1] > gavg[winner]))
                {
                    winner = e1;
                    maxwins = wins[e1];
                }
            }
            else
            {
                wins[e2]++;
                if (wins[e2] > maxwins || (wins[e2] == maxwins && gavg[e2] > gavg[winner]))
                {
                    winner = e2;
                    maxwins = wins[e2];
                }
            }        
        }
        cout << winner << "\n";
        gavg.clear();
        wins.clear();
    }
    return 0;
}