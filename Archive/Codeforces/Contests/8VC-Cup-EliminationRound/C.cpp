#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int components = 0; // number of conected components
int n; // number of balls
bool visited[10005];
vvi g;

void dfs(int s){
    visited[s] = true;
    for(int i = 0; i < g[s].size(); i++)
    {
        if (!visited[g[s][i]])
            dfs(g[s][i]);
    }
}

int main()
{
    int a;
    scanf("%d", &n);
    g = vvi(n, vi());
    memset(visited, n, false);
    for (int i = 0; i < n; i++){
        scanf("%d", &a);
        g[i].push_back(a-1);
        g[a-1].push_back(i);
    }
    for (int i = 0; i < n; i++){
        if (!visited[i])
        {
            dfs(i);
            components++;
        }
    }
    printf("%d", components);
    printf("\n");
    return 0;
}