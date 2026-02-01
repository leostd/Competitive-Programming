#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    //freopen("in", "r", stdin);
    int t;
    int ls[100005];
    bool chk[100005];
    vi ans;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        scanf("%d", &ls[i]);
    int up, down = 1;
    ans.push_back(t);
    memset(chk, 0, sizeof(chk));
    for (int i = t-2; i >= 0; --i) {
        if ((down == ls[i] || chk[i+ls[i]+1])){
            chk[i] = true;
            ans.push_back(i);
        }
        down++;
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        if(ans[i] > 0)
            printf("%d\n", ans[i]);
    return 0;
}