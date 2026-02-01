#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a, b, c;
    b = s.size()-1;
    a = c = 0;
    while(a <= b)
    {
        if (s[a] != s[b])
            c++;
        a++;
        b--;
    }
    bool flag = false;
    if (s.size() == 1 || c == 1 || (s.size() % 2 != 0 && c==0))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}