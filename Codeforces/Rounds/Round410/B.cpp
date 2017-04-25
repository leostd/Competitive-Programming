#include <bits/stdc++.h>
using namespace std;

string ss[51];
int n;
deque<char> dq;

void rotate(string &s, int m)
{
    while(m--)
        for (int i = 1; i < s.size(); i++)
            swap(s[i-1], s[i]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        cin >> ss[i];
    string a = ss[0];
    int aux, ans;
    aux = ans = 0x3f3f3f3f;
    bool flag = true;
    string b;
    for (int i = 0; i < a.size(); i++)
    {
        aux = 0;
        for (int j = 0; j < n; j++)
        {
            b = ss[j];
            for (int k = 0; k < a.size(); k++)
            {
                if (ss[j][k] != a[k])
                {
                    int idx = ss[j].find(a[k]);
                    aux += abs(k-idx);
                    rotate(ss[j], abs(k-idx));   
                }
            }
            if (ss[j] != a){
                flag = false;
                break;
            }
            ss[j] = b;
        }
        if (!flag)
            break;
        rotate(a, 1);
        ans = min(ans, aux);
    }
    if (flag)
        printf("%d\n", ans);
    else
        printf("-1\n");
    return 0;
}