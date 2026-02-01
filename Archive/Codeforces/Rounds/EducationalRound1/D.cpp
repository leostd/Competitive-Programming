#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n, m, k, a, b;
char grid[1010][1010];
bool mark[1010][1010];
int xmov[4] = {0, 0, 1, -1};
int ymov[4] = {1, -1, 0, 0};
vector<ii> ps;
map<ii, int> pics;
bool check(int r, int c){
    return (r >= 0 && r < n) && (c >= 0 && c < m) && mark[r][c]==false;
}

int dfs(int r, int c){
    mark[r][c] = true;
    int acum = 0;
    for(int i = 0; i < 4; i++){
        int a = r + xmov[i];
        int b = c + ymov[i];
        if (check(a, b) && grid[a][b] == '*') {
            acum++;
            //mark[a][b] = true;
        }
        else if (check(a, b) && grid[a][b] == '.')
            acum += dfs(a, b);
    }
    ps.push_back(ii(r,c));
    return acum;
}

int main() {
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            grid[i][j] = getchar();
        getchar();
    }
    memset(mark, 0, sizeof(mark));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(!mark[i][j] && grid[i][j] == '.'){
                int ans = dfs(i,j);
                for(int l = 0; l < ps.size(); l++)
                    pics[ps[l]] = ans;
                ps.clear();
            }
        }
    }
    for(int i = 0; i < k; i++){
        scanf("%d %d", &a, &b);
        ii ans = ii(a-1,b-1);
        printf("%d\n", pics[ans]);
    }

    return 0;
}