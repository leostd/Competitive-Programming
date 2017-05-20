#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int p, x, y;
bool mark [10000000];
vi ansv;

bool pseudo(int z){
    int i = (z / 50) % 475;
    for (int j = 0; j < 25; ++j){
        i = (i * 96 + 42) % 475;
        if (i + 26 == p) return true;
    }
    return false;
}

int bfs(int z){
    queue<ii> q;
    mark[z] = true;
    bool flag;
    int mina = 0x3f3f3f3f;
    q.push(ii(z,0));
    while (!q.empty()){
        int s = q.size();
        for (int i = 0; i < s; i++){
            ii a = q.front();
            flag = pseudo(a.first);
            q.pop();
            if (flag && mina > a.second)
                mina = a.second;
            else if (!flag){
                if (a.first - 50 >= y && !mark[a.first-50]){
                    mark[a.first-50] = true;
                    q.push(ii(a.first-50, a.second));
                }
                if (a.second < mina && !mark[a.first+100]){
                    mark[a.first+100] = true;
                    q.push(ii(a.first+100, a.second+1));
                }
            }
        }
    }
    return mina;
}

int main()
{
    //freopen("in", "r", stdin);
    scanf("%d %d %d", &p, &x, &y);
    memset(mark, false, sizeof(mark));
    int ans = bfs(x);
    printf("%d\n", ans);
    return 0;
}