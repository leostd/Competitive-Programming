#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int n, m, k, dst, src;
int indg[105];
priority_queue<int, vector<int>, greater<int>> q;
vi g[105], aux;

int main(){
    cin >> n >> m;
    string line;
    fill(g, g+105, vi());
    memset(indg, 0, sizeof(indg));
    for (int i = 0; i < m; i++){
        cin >> dst;
        cin >> k;
        indg[dst] = k;
        for(int j = 0; j < k; j++)
        {
            cin >> src;
            g[src].push_back(dst);
        }
    }
    for (int i = 1; i <= n; i++)
        if (indg[i] == 0)
            q.push(i);
    while(!q.empty()){
        int a = q.top();
        q.pop();
        printf("%d ", a);
        vi al = g[a];
        for (int i = 0; i < al.size(); i++){
            indg[al[i]]--;
            if (indg[al[i]] == 0)
                q.push(al[i]);
        }
    }
    printf("\n");
    return 0;
}