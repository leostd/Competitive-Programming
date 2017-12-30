#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

map<string, int> idx;
vi g[101];

int main() {
    int n, m, in[101], tc = 1;
    string b[101], s, d;
    bool check[101];
    while(scanf("%d", &n) != EOF){
        idx.clear();
        memset(in, 0, sizeof(in));
        memset(check, 0, sizeof(check));
        for(int i =0; i < 101; i++)
            g[i].clear();
        for (int i = 0; i < n; i++){
            cin >> b[i];
            idx[b[i]] = i;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            cin >> s >> d;
            g[idx[s]].push_back(idx[d]);
            in[idx[d]]++;
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ", tc++);
        int cnt = 0;
        while(cnt < n){
            for(int i = 0; i < n; i++) {
                if (in[i] == 0 && !check[i]) {
                    cnt++;
                    if (cnt < n)
                        cout << b[i] << " ";
                    else
                        cout << b[i] << ".\n";
                    check[i] = true;
                    for (int j = 0; j < g[i].size(); j++)
                        in[g[i][j]]--;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}