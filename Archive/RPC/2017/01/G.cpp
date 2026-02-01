#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int, int> ii;

int memo[505][505], m[505][505];
int rows, cols;
int mr[4] = {0, 0, 1, -1};
int mc[4] = {1, -1, 0, 0};

bool check(ii p){
    return (p.first > 0 && p.first <= rows && p.second > 0 && p.second <= cols);
}

void bfs(int r, int c){
    queue<ii> q;
    int it=0;
    ii a,b;
    a.first = r;
    a.second = c;
    memo[r][c] = it;
    q.push(a);
    while(!q.empty()){
        int s = q.size();
        it++;
        for(int i = 0; i < s; i++){
            a = q.front();
            q.pop();
            for (int j = 0; j < 4; j++){
                b.first = a.first + (mr[j] * m[a.first][a.second]);
                b.second = a.second + (mc[j] * m[a.first][a.second]);
                if (check(b) && memo[b.first][b.second] == -1){
                    q.push(b);
                    memo[b.first][b.second] = it;
                }
                    
            }
        }
    }
}

int main(){
    scanf("%d %d", &rows, &cols);
    for(int i = 0; i <= rows; i++)
        for(int j = 0; j <= cols; j++)
            memo[i][j] = -1;
    memo[1][1] = 0;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= cols; j++)
            scanf("%1d", &m[i][j]);
    bfs(1, 1);
    if (memo[rows][cols] == -1)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", memo[rows][cols]);
    return 0;
}