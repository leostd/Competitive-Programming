#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

map<vi, int> mp;

int main()
{
    //freopen("in", "r", stdin);
    int tc;
    int n;
    while(scanf("%d", &n), n)
    {
        int a, maxf = -1;
        mp.clear();
        vi b;
        for (int i = 0; i < n; ++i)
        {
            b.clear();
            for (int j = 0; j < 5; ++j){
                scanf("%d", &a);
                b.push_back(a);
            }
            sort(b.begin(), b.end());
            mp[b]++;
            if (mp[b] > maxf)
                maxf = mp[b];
        }
        int counter = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it){
            if (it->second == maxf)
                counter++;
        }
        printf("%d\n", counter*maxf);
    }
    return 0;
}

