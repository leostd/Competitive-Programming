#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vi g[1003];
int cases, n, m, a, b, ranking;
int indg[10003];

int main(){
    scanf("%d", &cases);
    for (int tc = 1; tc <= cases; tc++){
        queue<int> q;
        queue<int> aux;
        vector<ii> ranks;
        memset(indg, 0, sizeof(indg));
        fill(g, g+1003, vi());
        ranking = 1;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            g[b].push_back(a);
            indg[a]++;
        }
        for (int i = 0; i < n; i++){
            if (indg[i] == 0){
                q.push(i);
                aux.push(1);
            }
        }
        while(!q.empty()){
            int a = q.front();
            ranking = aux.front();
            ranks.push_back(ii(ranking, a));
            aux.pop();
            q.pop();
            vi al = g[a];
            for (int i = 0; i < al.size(); i++){
                indg[al[i]]--;
                if (indg[al[i]] == 0){
                    q.push(al[i]);
                    aux.push(ranking+1);
                }
            }
        }
        sort(ranks.begin(), ranks.end());
        printf("Scenario #%d:\n", tc);
        for (int i = 0; i < ranks.size(); i++){
            printf("%d %d\n", ranks[i].first, ranks[i].second);
        }
        printf("\n");
    }
    return 0;
}