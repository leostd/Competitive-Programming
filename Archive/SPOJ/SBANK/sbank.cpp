#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> accs;

int main ()
{
    int t, n;
    scanf("%d", &t);
    string line;
    while(t--)
    {
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
            accs[line]++;
        }
        for (auto it = accs.begin(); it != accs.end(); ++it)
            cout << it->first << it->second << "\n";
        cout << "\n";
        accs.clear();
        cin.ignore();

    }
    return 0;
}