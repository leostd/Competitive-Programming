#include <bits/stdc++.h>
using namespace std;
#define N 10000006
struct med{
    int p, t, inc;
    bool operator < (const med &other) const{
        if (t == other.t)
            return p > other.p;
        return t > other.t;
    }
};

char names[3007][10010];
int n, k;
med meds[3007];
int times[3007];
priority_queue<med> taken;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s %d", names[i], &meds[i].t);
            meds[i].p = i;
            meds[i].inc = meds[i].t;
        }
        for (int i = 0; i < n; i++)
            taken.push(meds[i]);
        med act;
        while(k)
        {
            act = taken.top();
            printf("%d %s\n", act.t, names[act.p]);
            taken.pop();
            act.t += act.inc;
            taken.push(act);
            k--;
        }
    }
    return 0;
}