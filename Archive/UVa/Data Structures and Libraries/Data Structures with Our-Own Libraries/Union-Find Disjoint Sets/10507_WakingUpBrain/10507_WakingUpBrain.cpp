#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int counter[30];
bool aw[30];
vi g[30];

// void initUF(int x, int id)
// {
//     for (int i = 0; i <= n; i++)
//         parent[id][i] = i;
// }

// int findUF(int x, int id)
// {
//     if (parent[x] != x)
//         return parent[id][x] = find(parent[id][x]);
//     return x;
// }

// bool connectedUF(int a, int b)
// {
//     int roota = find(a);
//     int rootb = find(b);
//     return roota == rootb
// }

// void unionUF(int x, int y)
// {
//     int rootx = findUF(x);
//     int rooty = findUF(y);
//     if (rootx != rooty)
//         parent[rooty] = rootx;
// }

int main()
{
    //freopen("in", "r", stdin);
    int n, m, a, b;
    set<int> awake, slept;
    char ch;
    int ans;
    bool flag;
    while(scanf("%d %d\n", &n, &m) != EOF){
        //initUF(n);
        for (int i = 0; i < 30; i++)
            g[i].clear();
        awake.clear();
        slept.clear();
        for (int i = 0; i < 3; ++i){
            ch = getchar();
            awake.insert(ch-65);
        }
        getchar();
        for (int i = 0; i < m; ++i)
        {
            while(a=getchar(), a == '\n');
            b = getchar();
            if (!awake.count(a-65)) slept.insert(a-65);
            if (!awake.count(b-65)) slept.insert(b-65);
            g[a-65].push_back(b-65);
            g[b-65].push_back(a-65);
            getchar();
        }
        ans = 0;
        flag = true;
        auto it = awake.begin();
        memset(aw, false, sizeof(aw));
        memset(counter, 0, sizeof(counter));
        while(awake.size() < n && flag)
        {
            flag = false;
            it = awake.begin();
            for (it; it != awake.end(); ++it)
            {
                if (aw[*it])
                    continue;
                for (int i = 0; i < g[*it].size(); ++i)
                {
                    if (awake.count(g[*it][i])) // awake
                        continue;
                    counter[g[*it][i]]++;
                }
                aw[*it] = true;
            }
            it = slept.begin();
            while(!slept.empty() && it != slept.end())
            {
                if (counter[*it] >= 3)
                {
                    flag = true;
                    awake.insert(*it);
                    slept.erase(*it);
                    it = slept.begin();
                }
                else
                    ++it;
            }
            ans++;
        }
        if (flag)
            printf("WAKE UP IN, %d, YEARS\n", ans);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");
    }
    return 0;
}