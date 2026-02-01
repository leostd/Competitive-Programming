#include <bits/stdc++.h>
#define N 1001
using namespace std;

typedef vector<int> vi;


int main(){
    vi g[N];
    bool leaf[N];
    int n, x;
    scanf("%d", &n);
    memset(leaf, false, sizeof(leaf));
    for (int i = 2; i <= n; i++){
        scanf("%d", &x);
        g[x].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        if (g[i].size() == 0)
            leaf[i] = true;
    for(int i = 1; i <= n; i++){
        if (leaf[i])
            continue;
        int c = 0;
        for(int j = 0; j < g[i].size(); j++){
            c += leaf[g[i][j]];
        }
        if(c < 3){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
