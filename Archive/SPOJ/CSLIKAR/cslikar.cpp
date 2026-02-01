#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int r, c; // row and columns
int movx[] = {0, 0, 1, -1}; //  possible movements xcoord
int movy[] = {1, -1, 0, 0}; // possible movements ycoord
ii s, d; // initial positions
vector<ii> fls; // flood array
vector<string> g; // grid
vvi dist; // distance matrix

bool valid(int x, int y) // valid postion
{
    return (x >= 0 && x < r && y >= 0 && y < c);
}

void printg()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%c", g[i][j]);
        printf("\n");
    }
}
void flood() // flood at each time step
{
    vector<ii> ns;
    ii a;
    int x, y;
    for (int i = 0; i < fls.size(); i++)
    {
        a = fls[i];
        for (int j = 0; j < 4; j++)
        {
            x = a.first + movx[j];
            y = a.second + movy[j];
            if (valid(x,y) && g[x][y] == '.')
            {
                g[x][y] = '*';
                ns.push_back(ii(x,y));
            }
        }
    }
    fls = ns;
}

void bfs(ii st)
{
    queue<ii> ps, nps;
    int x, y;
    ps.push(st);
    while(!ps.empty())
    {
        nps = queue<ii>();
        flood();
        //printg();
        while(!ps.empty())
        {
            ii aux = ps.front();
            ps.pop();
            if (g[aux.first][aux.second] == 'D')
                return;
            for (int i = 0; i < 4; i++)
            {
                x = aux.first + movx[i];
                y = aux.second + movy[i];
                if (valid(x, y) && g[x][y] != 'X' && g[x][y] != '*')
                {
                    nps.push(ii(x,y));
                    dist[x][y] = dist[aux.first][aux.second] + 1;
                    if (g[x][y] != 'D' && g[x][y] != 'S')
                        g[x][y] = 'X';
                }
            }                
        }
        ps = nps;
    }
}

int main()
{
    char ch;
    scanf("%d %d\n", &r, &c);
    g = vector<string>(r, "");
    dist = vvi(r, vi(c, 0));
    for (int i = 0; i < r; i++)
    {   
        for (int j = 0; j < c; j++)
        {
            scanf("%c", &ch);
            g[i].push_back(ch);
            if (ch == 'S')
                s = ii(i, j);
            else if (ch == 'D')
                d = ii(i, j);
            else if (ch == '*')
                fls.push_back(ii(i, j));
        }
        scanf("\n");   
    }
    bfs(s);
    if (dist[d.first][d.second] > 0)
        printf("%d\n", dist[d.first][d.second]);
    else
        printf("KAKTUS\n");
    return 0;
}