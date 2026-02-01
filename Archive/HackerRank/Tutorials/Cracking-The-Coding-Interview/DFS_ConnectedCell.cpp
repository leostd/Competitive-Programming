#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int mx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int my[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int mreg = 0, areg = 0;
vvi vis;

bool check(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int i, int j, const vvi &grid)
{
    int x, y;
    vis[i][j] = 1;
    for (int k = 0; k < 8; k++)
    {
        x = i + mx[k];
        y = j + my[k];
        if (check(x, y, grid.size(), grid[i].size()) && grid[x][y]==1 && vis[x][y] == 0)
        {
            areg++;
            dfs(x, y, grid);
        }
    }
}

int get_biggest_region(vector< vector<int> > grid) {
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                areg = 1;
                dfs(i, j, grid);
                if (areg > mreg)
                    mreg = areg;
            }
        }
    }
    return mreg;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    vis = vvi(n, vi(m, 0));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}