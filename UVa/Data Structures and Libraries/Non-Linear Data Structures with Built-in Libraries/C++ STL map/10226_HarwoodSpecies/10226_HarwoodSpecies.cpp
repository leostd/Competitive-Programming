#include <map>
#include <iostream>
using namespace std;

int main () {
    //freopen("in", "r", stdin);
    int tc;
    scanf("%d\n\n", &tc);
    string line;
    int count;
    map<string, int> mp;
    while (tc--)
    {
        mp.clear();
        count = 0;
        while (getline(cin, line), line != "")
        {
            if (!mp.count(line))
                mp[line] = 0;
            mp[line]++;
            count++;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            int c = it->second;
            string aux = it->first;
            cout << it->first << " ";
            printf("%.4f\n", ((double)c/count)*100);
        }
        if(tc)
            printf("\n");
    }
    return 0;
}