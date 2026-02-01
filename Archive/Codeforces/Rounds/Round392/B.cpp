#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;

int lacks[4]; // r b y g
int tl = 0; // how many lacks
bool idx[102];
map<char, int> lts;

int main()
{
    string s;
    cin >> s;
    memset(idx, false, sizeof(bool)*102);
    memset(lacks, 0, 4*sizeof(int));
    lts['R'] = 0;
    lts['B'] = 1;
    lts['Y'] = 2;
    lts['G'] = 3;
    for(int i = 0; i < s.size(); i++)
    {
        if ( s[i] != '!' && !idx[i]){
            int l, r;
            l = r = i;
            idx[i] = true;
            while (l >= 0 || r < s.size())
            {
                l = l - 4;
                r = r + 4;
                if (l >= 0)
                {
                    if (s[l] == '!')
                        lacks[lts[s[i]]]++;
                    s[l] = s[i];
                }
                if (r < s.size())
                {
                    if (s[r] == '!')
                        lacks[lts[s[i]]]++;
                    s[r] = s[i];
                }
            }
        }
    }
    printf("%d %d %d %d\n", lacks[0], lacks[1], lacks[2], lacks[3]);
    return 0;
}