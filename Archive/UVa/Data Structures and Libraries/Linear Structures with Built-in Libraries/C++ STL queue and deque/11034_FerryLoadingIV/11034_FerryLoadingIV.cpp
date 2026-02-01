#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main()
{
    //freopen("in", "r", stdin);
    int cs, a;
    string s;
    scanf("%d", &cs);
    int rf, lf;
    while(cs--)
    {
        int ans = 0;
        int l, m;
        queue<int> lq, rq;
        bool fside = true; // true -> left. false -> right
        scanf("%d %d", &l, &m);
        l *= 100; // meters to centimeters
        for (int i = 0; i < m; i++)
        {
            cin >> a >> s;
            if (s[0] == 'r') rq.push(a);
            else lq.push(a);
        }
        int laux = 0;
        while(!lq.empty() || !rq.empty())
        {
            laux = 0;
            if (fside){
                while(!lq.empty())
                {
                    lf = lq.front();
                    if (lf + laux <= l){
                        laux += lf;
                        lq.pop();
                    }
                    else
                        break;
                }
                fside = !fside;
                ans++;
            }
            else {
                while(!rq.empty())
                {
                    rf = rq.front();
                    if (rf + laux <= l){
                        laux += rf;
                        rq.pop();
                    }
                    else
                        break;
                }
                fside = !fside;
                ans++;
            }
        }
        printf("%d\n", ans); // +1 of the last travel
    }
    return 0;
}