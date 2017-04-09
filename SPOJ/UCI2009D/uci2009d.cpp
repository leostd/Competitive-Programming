#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

typedef pair<int, int> ii;
set<ii> octave;
vector<string> mp;
set<set<ii>> es;
vector<vector<bool>> mrk;
int count, n;

void bt (int i, int j, int e) // i = row. j = column. e = emeralds
{
    if (octave.size() == 8)
    {
        es.insert(octave);
    }
    else
    {
        if (!mrk[i][j])
        {
            mrk[i][j] = true;
            if (mp[i][j] == 'X')
            {
                octave.insert(ii(i,j));
                if (i + 1 < n && i + 1 >= 0) // down
                    bt(i+1, j, e+1);
                if (i - 1 < n && i - 1 >= 0) // up
                    bt(i-1, j, e+1);
                if (j + 1 < n && j + 1 >= 0) // right
                    bt(i, j+1, e+1);
                if (j - 1 < n && j - 1 >= 0) // left
                    bt(i, j-1, e+1);
                octave.erase(ii(i,j));
                 mrk[i][j] = false;
            }
        }
    }
} 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d\n", &n);
        mp = vector<string>(n,"");
        mrk = vector <vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            getline(cin, mp[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                bt(i,j,0);
        printf("%lu\n", es.size());
        es.clear();
    }
    return 0;
}