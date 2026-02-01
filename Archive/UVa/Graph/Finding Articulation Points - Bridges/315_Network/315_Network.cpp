#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

vi places[105];
int dfs_low[105], dfs_num[105], childs[105], parent[105];
int a,b,c,d, n, counter, root, articulation_points;

void aps(int s){
    dfs_num[s] = dfs_low[s] = counter++;
    vi al = places[s];
    bool flag = false;
    for (int i = 0; i < al.size(); i++){
        if (dfs_num[al[i]] == -1){
            aps(al[i]);
            childs[s]++;
            parent[al[i]] = s;
            if (dfs_low[al[i]] >= dfs_num[s])
                flag = true;
            dfs_low[s] = min(dfs_low[s], dfs_low[al[i]]);
        }
        else if(al[i] != parent[s])
            dfs_low[s] = min(dfs_low[s], dfs_num[al[i]]);
    }
    if ((root == s && childs[s] > 1) || (s != root && flag))
        articulation_points++;
}

int main(){
    while(scanf("%d\n", &n), n){
        fill(places, places+105, vi());
        counter = articulation_points = 0;
        string line;
        while(1){
            getline(cin, line);
            stringstream str(line);
            str >> a;
            if (a){
                while(str >> b){
                    places[a].push_back(b);
                    places[b].push_back(a);
                }
            }
            else
                break;
        }
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(childs, 0, sizeof(childs));
        memset(parent, 0, sizeof(parent));
        memset(dfs_low, 0, sizeof(dfs_low));
        for (int i = 0; i < n; i++){
            if (dfs_num[i] == -1){
                root = i;
                aps(i);
            }
        }
        printf("%d\n", articulation_points);
    }
    return 0;
}