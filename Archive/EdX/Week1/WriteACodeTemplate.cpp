#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("template.in");
    std::ofstream cout("template.out");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <limits.h>

#define db false 

typedef std::pair<int, int> key;
typedef std::unordered_map<unsigned char, key > hashDist;
typedef long long int lli;

int dist(key k1, key k2)
{
    int r1, r2;
    r1 = std::abs(k1.first - k2.first);
    r2 = std::abs(k1.second - k2.second);
    return std::max(r1,r2);
}


int main()
{
    int w,h, charInt;
    unsigned char uc;
    lli mins = INT_MAX;
    hashDist m;
    int matDist[95][95];
    cin >> w >> h;
    std::string names[3], line, langs[3], minl;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            charInt = cin.get();
            uc = (unsigned char) charInt;
            if (uc == '\n')
            {
                charInt = cin.get();
                uc = (unsigned char) charInt;
            }
            if (db)
                cout << uc;
            m[uc] = key(h-i, j+1);
        }
        if (db)
            cout << std::endl;
    }
    
    getline(cin, line);
    getline(cin, line);
    //Reading templates
    for (int i = 0; i < 3; i++)
    {
        getline(cin, names[i]);
        while(getline(cin, line), line != "")
        {
            langs[i] += line;
            if (db)
                cout << line;
        }
    }
    //Sum  
    for (int i = 0; i < 3; i++)
    {
        unsigned char c1, c2;
        c1 = langs[i][0];
        lli sum = 0;
        for(int j = 1; j < langs[i].size(); j++)
        {
            c2 = langs[i][j];
            sum += dist(m[c1], m[c2]);
            c1 = c2;
        }
        if (sum < mins)
        {
            mins = sum;
            minl = names[i];
        }
    }
    cout << minl << std::endl << mins;
return 0;
}
