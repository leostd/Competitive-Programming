#include <iostream>
#include <deque>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int t, nc;
    while(scanf("%d\n", &nc), nc != 0)
    {
        string line;
        map<char, int> keyb; // Key: the key on the keyboard. Value: How many times is this key in the sliding window
        deque<char> sw;     // Sliding window
        getline(cin, line);
        int maxseq = 0, count = 0;
        for (int i = 0; i < line.size(); i++)
        {
            if (keyb.count(line[i])) // the key is in the layout
            {
               sw.push_back(line[i]);
                if (sw.size() > maxseq)
                    maxseq = sw.size();
                keyb[line[i]]++;
            }
            else // the key is not in the layout
            {
                if (keyb.size() < nc) // there is space available for this new key
                {
                    keyb[line[i]]++;
                    sw.push_back(line[i]);
                    if (sw.size() > maxseq)
                        maxseq = sw.size();
                }
                else // there is no more space in the layout. 
                {
                    char aux = sw.front(); 

                    while(keyb[aux] > 1) // pop front until there is an element that we can remove from the keyb
                    {
                        keyb[aux]--;
                        sw.pop_front();
                        aux = sw.front();
                    }
                    keyb.erase(aux);
                    sw.pop_front();
                    sw.push_back(line[i]);
                    keyb[line[i]]++;
                }
            }
        }
        printf("%d\n", maxseq);
    }
    return 0;
}