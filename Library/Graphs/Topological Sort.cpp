#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

const int NODES = 1000;

typedef vector<int> vi;

int n, m; // n = #nodes, m = #edges 
int it; // iterator to assign the place in the reverse order array;
int src, dst; // read input variables
int tsv[NODES]; // topological sort array in reverse order
bool vis[NODES]; // visited array
vi g[NODES]; // DAG

void ts(int s){
  vis[s] = true;
  for (int i = 0; i < (int)g[s].size(); i++){
       if (!vis[g[s][i]])
            ts(g[s][i]);
  }
  tsv[it++] = s; // the line that differ from dfs algorithm
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%d %d", &src, &dst);
        g[src].push_back(dst);
    }
    //initial node possibly vary between 0 and 1
    for (int i = 0; i < n; i++)
        if (!vis[i])
            ts(i);
    for (int i = m-1; i > 0; i--){
        printf("%d ", tsv[i]);
    }
    printf("\n");
    return 0;
}