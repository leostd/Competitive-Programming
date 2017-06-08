#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi g[10007], idx[10007];

int main(){
    //freopen("in", "r", stdin);
    int n, m, e, a;
    while(scanf("%d %d", &n, &m) != EOF){
        for (int i = 0; i <= 10007; i++){
            g[i].clear();
            idx[i].clear();
        }
        for (int i = 0; i < n; i++){
            scanf("%d", &e);
            vi elems, cols;
            for (int j = 0; j < e; j++){
                scanf("%d", &a);
                cols.push_back(a);
            }
            for (int j = 0; j < e; j++){
                scanf("%d", &a);
                elems.push_back(a);
            }
            for (int j = 0; j < e; ++j){
                g[cols[j]].push_back(elems[j]);
                idx[cols[j]].push_back(i+1);
            }
        }
        printf("%d %d\n", m, n);
        for (int i = 1; i <= m; i++){
            printf("%d", (int)g[i].size());
            for (int j = 0; j < (int)g[i].size(); ++j){
                printf("% d", idx[i][j]);
            }
            printf("\n");
            for (int j = 0; j < (int)idx[i].size(); ++j){
                printf("%d", g[i][j]);
                if (j < idx[i].size()-1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}