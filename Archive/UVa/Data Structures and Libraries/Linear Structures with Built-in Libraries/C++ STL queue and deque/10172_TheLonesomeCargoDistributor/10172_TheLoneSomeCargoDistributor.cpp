#include <bits/stdc++.h>
#define SMAX 101
#define QMAX 100
using namespace std;

queue<int> st[SMAX];
stack<int> cr;

const int mv = 2, ld = 1, unld = 1; 
int main()
{
    //freopen("in", "r", stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int n, s, q, qi, b, counter;
        counter = 0;
        scanf("%d %d %d", &n, &s, &q);
        for (int i = 0; i < n; ++i){
            scanf("%d", &qi);
                for (int j = 0; j < qi; ++j)
                {
                    scanf("%d", &b);
                    st[i].push(b);
                    counter++;
                }
        }
        int act = 0;
        int cargo;
        int ans = 0;
        while(counter)
        {
            // unload
            while (!cr.empty()){
                cargo = cr.top();
                if (cargo == act+1){
                    counter--;
                    cr.pop();
                }
                else if (st[act].size() < q){
                    st[act].push(cargo);
                    cr.pop();
                }
                else if (st[act].size() == q)
                    break;
                ans += unld;
            }

            // load
            while (!st[act].empty() && cr.size() < s){
                cargo = st[act].front();
                st[act].pop();
                ans += ld;
                cr.push(cargo);
            }

            // move to the next station
            if (counter)
            {
                if (act == n-1)
                    act = 0;
                else
                    act++;
                ans += mv;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}