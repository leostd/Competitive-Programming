#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

const int MAXN = 100002;
int n, tc, counter;
map<string, int> idx;
int parent[MAXN], ranking[MAXN];

int find(int s){
    if (s != parent[s])
        parent[s] = find(parent[s]);
    return parent[s];
}

bool connected(int a, int b){
    return find(a) == find(b);
}

void uf(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    if (roota != rootb){
        int ranka = ranking[roota];
        int rankb = ranking[rootb];
        if(ranka > rankb){
            parent[rootb] = roota;
            ranking[roota] += ranking[rootb];
        }
        else{
            parent[roota] = rootb;
            ranking[rootb] += ranking[roota];   
        }
    }
}

int main(){
    string a, b;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        counter = 0;
        idx.clear();
        for (int i = 0; i < MAXN; i++)
            parent[i] = i;
        fill(ranking, ranking+MAXN, 1);
        for (int i = 0; i < n; i++){
            cin >> a >> b;
            if (!idx.count(a))
                idx[a] = counter++;
            if (!idx.count(b))
                idx[b] = counter++;
            int x = idx[a];
            int y = idx[b];
            if (!connected(x, y))
                uf(x, y);
            printf("%d\n", ranking[find(x)]);
        }
    }
    return 0;   
}