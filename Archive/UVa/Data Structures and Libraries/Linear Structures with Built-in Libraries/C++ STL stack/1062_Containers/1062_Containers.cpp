#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vch;
typedef vector <vch> vvch; 

int main()
{
    //freopen("in", "r", stdin);
    int tc = 1;
    char ch, tp;
    vvch s;
    string a;
    while(cin >> a, a != "end")
    {
        s.clear();
        for (int i = 0; i < a.size(); ++i)
        {
            ch = a[i];
            if (s.empty())
                s.push_back(vch());
            for (int j = 0; j < s.size(); ++j)
            {
                if (!s[j].empty())
                    tp = s[j].back();
                if (ch <= tp || s[j].empty())
                {
                    s[j].push_back(ch);
                    break;
                }
                if (j == s.size()-1)
                {
                    s.push_back(vch());
                    s[j+1].push_back(ch);
                    break;
                }
            }
        }
        int ans = s.size();
        printf("Case %d: %d\n", tc++, s.size());
    }
    return 0;
}