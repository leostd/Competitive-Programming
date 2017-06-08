#include <bits/stdc++.h>
using namespace std;

string a, b, c;
vector<string> ans;

void f(int aid, int bid, string aux){
    if (bid == b.size())
    {
        ans.push_back(aux);
    }
    else
    {
        if (!c.empty()){
            char ch = c[c.size()-1];
            c.pop_back();
            if (ch == b[bid])
                f(aid, bid+1, aux+"o ");
            c.push_back(ch);
        }
        if (aid < a.size()){
            c.push_back(a[aid]);
            f(aid+1, bid, aux+"i ");
            c.pop_back();
        }
    }
}


int main()
{
    //freopen("in", "r", stdin);
    while(cin >> a >> b)
    {
        string aux = "";
        ans.clear();
        f(0,0, aux);
        printf("[\n");
        sort(ans.begin(), ans.end());
        for (int i=0; i < ans.size(); ++i)
        {
            cout << ans[i].substr(0, ans[i].size()-1) << "\n";
        }
        printf("]\n");
    }
    return 0;
}