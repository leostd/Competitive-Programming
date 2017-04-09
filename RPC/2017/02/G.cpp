#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

map<char, int> code;
map<int, char> decode;


int xmov[4] = {1, 0, -1, 0};
int ymov[4] = {0, 1, 0, -1};
int grid[45][45], match[1605], color[1605], p[1605];
int n, m, num_clouds;
bool mark_dfs[1607], mark_bfs[45][45]; 
vii lands;
vi g[1607], L, R, clouds;
void setMaps()
{
    code['L'] = 1;
    code['W'] = 2;
    code['C'] = 3;
    decode[1] = 'L';
    decode[2] = 'W';
    decode[3] = 'C';
}

bool check(int x, int y, int l)
{
    return (x >= 0 && x < 40 && y >= 0 && y < 40 && grid[x][y] == l && !mark_bfs[x][y]);
}
void bfs(ii src)
{
    queue<ii> q;
    mark_bfs[src.first][src.second] = true;
    q.push(src);
    while(!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            ii a = q.front();
            q.pop();
            int x, y;
            for (int i = 0; i < 4; i++)
            {
                x = a.first + xmov[i];
                y = a.second + ymov[i];
                if (check(x, y, 1))
                {
                    mark_bfs[x][y] = true;
                    q.push(ii(x, y));
                }
            }
        }
    }
}

int countLands()
{
    memset(mark_bfs, false, sizeof(mark_bfs));
    int ans = 0;
    ii aux;
    for (int i = 0; i < lands.size(); i++)
    {
        aux = lands[i];
        if (!mark_bfs[aux.first][aux.second])
        {
            bfs(aux);
            ans++;
        }
    }
    return ans;
}

void separateLands()
{
    int x, y;
    for (int i = 0; i < lands.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            x = lands[i].first + xmov[j];
            y = lands[i].second + ymov[j];
            if (grid[x][y] == 3)
                grid[x][y] = 2;
        }
    }
}

void findClouds()
{
    ii aux;
    int x, y, act;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 3)
            {
                num_clouds++;
                act = i*m + j;
                clouds.push_back(act);
                for (int k = 0; k < 4; k++)
                {
                    x = i + xmov[k];
                    y = j + ymov[k];
                    if(x < 0 || x > n || y < 0 || y > m)
                        continue;
                    if (grid[x][y] == 3)
                        g[act].push_back(x*m + y);
                }
            }
}

void colorGraph(int src){
    mark_dfs[src] = true;
    vi aux = g[src];
    for (int i = 0; i < aux.size(); i++)
    {
        if (mark_dfs[aux[i]] || p[src] == aux[i] || color[aux[i]] != -1) continue;
        color[aux[i]] = !color[src];
        if (color[aux[i]])
            L.push_back(aux[i]);
        else
            R.push_back(aux[i]);
        p[aux[i]] = src;
        colorGraph(aux[i]);
    }
}

bool matching(int cur)
{
    if (cur == -1) return true;
    mark_dfs[cur] = true;
    vi aux = g[cur];
    for (int i = 0; i < (int)aux.size(); i++)
    {
        int next = aux[i];
        if (mark_dfs[aux[i]]) continue;
        mark_dfs[aux[i]] = true;
        if (matching(match[next]))
        {
            match[next] = cur;
            match[cur] = next;
            return true;
        }
    }
    return false;
}

int max_bipartite_matching()
{
    memset(match, -1, sizeof(match));
    int flow = 0;
    for (int i = 0; i < L.size(); i++)
    {
        memset(mark_dfs, false, sizeof(mark_dfs));
        flow += matching(L[i]);
    }
    return flow;
}

void printGrid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}


int main()
{
    setMaps();
    scanf("%d %d\n", &n, &m);
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ch = getchar();
            grid[i][j] = code[ch];
            if (code[ch] == 1)
                lands.push_back(ii(i, j));
        }
        scanf("\n");
    }
    int l = countLands();
    //printGrid();
    separateLands();
    //printf("\n");
    //printGrid();
    findClouds();
    memset(mark_dfs, false, sizeof(mark_dfs));
    memset(color, -1, sizeof(color));
    int mis = 0, sz;
    for (int i = 0; i < num_clouds; i++)
    {
        if (!mark_dfs[clouds[i]]){
            L.clear();
            R.clear();
            p[i] = -1;
            L.push_back(clouds[i]);
            colorGraph(clouds[i]);
            sz = L.size()+R.size();
            mis += (sz - max_bipartite_matching());
        }

    }
    printf("%d\n", mis + l);
    return 0;
}