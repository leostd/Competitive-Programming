#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <set>
#include <map>
using namespace std;

const int MAXN = 10005;

int parent[MAXN], r[MAXN], money[MAXN];
int n, m, a, b, tc;

int find(int s){
    if (s != parent[s])
        parent[s] = find(parent[s]);
    return parent[s];
}

void uf(int x, int y){
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty){
        if (r[rootx] > r[rooty]){
            parent[rooty] = rootx;
        }
        else if (r[rootx] < r[rooty]){
            parent[rootx] = rooty;
        }
        else {
            parent[rooty] = rootx;
            r[rootx]++;
        }
    }
}

int main(){
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < MAXN; i++){
            parent[i] = i;
            r[i] = 1;
        }
        for (int i = 0; i < n; i++){
            scanf("%d", &a);
            money[i] = a;
        }
        for (int i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            uf(a, b);
        }
        map<int, int> calc;
        for(int i = 0; i < n; i++){
            if (calc.count(find(i)) == 0)
                calc[find(i)] = money[i];
            else
                calc[find(i)] += money[i];
        }
        auto it = calc.begin();
        for (it; it != calc.end(); ++it){
            if (it->second != 0)
                break;
        }
        if (it != calc.end())
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
    }
    return 0;
}