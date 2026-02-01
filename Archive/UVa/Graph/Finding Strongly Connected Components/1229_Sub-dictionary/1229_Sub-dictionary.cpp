#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <map>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;

typedef vector<int> vi;
typedef vector<set<int>> vvi;

map<string, int> idx;
map<int, string> decode;
int dfs_num[N], indices, n;
vi order;
set<int> g[N], tg[N];
vvi components;

void kosaraju(int s, int pass, set<int> &component){
    dfs_num[s] = 1;
    set<int> al;
    if (pass == 1)
        al = g[s];
    else 
        al = tg[s];
    for (auto it = al.begin(); it != al.end(); ++it){
        if (dfs_num[*it] == -1)
            kosaraju(*it, pass, component);
    }
    order.push_back(s);
    if (pass == 2)
        component.insert(s);
}

int main(){
    string line, a, b;
    int x, y;
    while(scanf("%d\n", &n), n){
        indices = 0;
        fill(tg, tg+n, set<int>());
        fill(g, g+n, set<int>());
        fill(dfs_num, dfs_num+n, -1);
        decode.clear();
        idx.clear();
        components.clear();
        order.clear();
        for (int i = 0; i < n; i++){
            getline(cin, line);
            stringstream str(line);
            str >> a;
            if (idx.count(a) == 0){
                decode[indices] = a;
                idx[a] = indices++;
            }
            while(str >> b){
                if (idx.count(b) == 0){
                    decode[indices] = b;
                    idx[b] = indices++;
                }
                x = idx[a];
                y = idx[b];
                g[idx[a]].insert(idx[b]);
                tg[idx[b]].insert(idx[a]);
            }
        }
        set<int> component;
        for(int i = 0; i < n; i++){
            if (dfs_num[i] == -1){
                kosaraju(i, 1, component);
            }
        }
        fill(dfs_num, dfs_num+n, -1);
        for (int i = n-1; i > 0; i--){
            if (dfs_num[order[i]] == -1)
            {
                component = set<int>();
                kosaraju(order[i], 2, component);
                if (component.size() >= 2)
                    components.push_back(component);
            }
        }
        order.clear();
        component = set<int>();
        fill(dfs_num, dfs_num+n, -1);
        for (int i = 0; i < components.size(); i++){
            int j = *(components[i].begin());
            if (dfs_num[j] == -1)
                kosaraju(j, 1, component);
        }
        set<string> ans;
        cout << order.size() << "\n";
        for (int i = 0; i < order.size(); i++)
            ans.insert(decode[order[i]]);
        for (auto it = ans.begin(); it != ans.end(); ++it){
            if (it != ans.begin())
                cout << " ";
            cout << *it;
        }
        cout << "\n";
    }
    return 0;
}