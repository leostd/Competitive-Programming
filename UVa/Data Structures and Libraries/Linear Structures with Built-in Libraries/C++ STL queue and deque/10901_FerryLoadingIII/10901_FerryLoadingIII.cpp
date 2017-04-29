#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main()
{
    //freopen("in", "r", stdin);
    int cs, n, t, m, a, act, c[10007];
    ii ltop, rtop;
    string s;
    bool fside = true; // true -> left. false -> right
    scanf("%d", &cs);
    while(cs--)
    {
        queue<ii> left, right;
        int onferry;
        scanf("%d %d %d", &n, &t, &m);
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> s;
            if (s == "right")
                right.push(ii(a,i));
            else
                left.push(ii(a,i));
        }
        onferry = act = 0;
        fside = true;
        while(!left.empty() || !right.empty()){
            rtop.first = ltop.first = 0x3f3f3f3f;
            if (!left.empty())
                ltop = left.front();
            if (!right.empty())
                rtop = right.front();
            if (fside) { //left
                while(!left.empty() && act >= ltop.first && onferry < n){
                    c[ltop.second] = act+t;
                    onferry++;
                    left.pop();
                    ltop = left.front();
                }
                if (onferry){
                    onferry = 0;
                    act += t;
                    fside = false;
                }
                else
                {
                    if (ltop.first <= rtop.first) // wait on the left
                        act += (ltop.first-act); 
                    else{ // wait and cross
                        act += (rtop.first>=act) ? (rtop.first-act)+t : t;
                        fside = false;
                    }
                }   
            }
            else
            {
                while(!right.empty() && act >= rtop.first && onferry < n){
                    c[rtop.second] = act+t;
                    onferry++;
                    right.pop();
                    rtop = right.front();
                }
                if (onferry){
                    onferry = 0;
                    act += t;
                    fside = true;
                }
                else{
                    if (rtop.first <= ltop.first) // wait on the right
                        act += (rtop.first-act);
                    else {// wait and cross
                        act += (ltop.first >= act) ? (ltop.first-act)+t : t;
                        fside = true;
                    }
                }
            } 
        }
        for (int i = 0; i < m; i++)
            printf("%d\n", c[i]);
        if (cs != 0)
            printf("\n");
    }
    return 0;
}