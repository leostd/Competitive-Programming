#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi g[30];
bool mark[30];

void dfs(int s){
    mark[s] = true;
    for (int i = 0; i < g[s].size(); i++){
        if (!mark[g[s][i]])
            dfs(g[s][i]);
    }
}

int main()
{
    int tc;
    scanf("%d\n", &tc);
    while(tc--){
        int tree, acorn;
        tree = acorn = 0;
        memset(mark, false, sizeof(mark));
        for (int i = 0; i < 30; i++)
            g[i].clear();
        char a = 'a', b;
        while (a != '*'){
            a = getchar();
            if (a == '*')
                break;
            a = getchar();
            if (a != '*'){
                getchar();
                b = getchar();
                getchar();
                getchar();
                g[a-65].push_back(b-65);
                g[b-65].push_back(a-65);
            }
        }
        while(a = getchar(), a == '*');
        vi nodes;
        while(a = getchar(), a == ',' || (a >= 65 && a <= 91)){
            if (a == ',') continue;
            nodes.push_back(a-65);
        }
        for (int i = 0; i < nodes.size(); i++){
            if (g[nodes[i]].size() == 0){
                acorn++;
                mark[nodes[i]] = true;
            }
            else if (!mark[nodes[i]]){
                dfs(nodes[i]);
                tree++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
    return 0;
}