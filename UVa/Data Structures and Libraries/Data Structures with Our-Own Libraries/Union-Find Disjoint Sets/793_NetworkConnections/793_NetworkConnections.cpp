#include <iostream>
#include <sstream>
#include <string>
#define N 1000007
using namespace std;

int parent[N];

void initUF(int n)
{
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

int findUF(int x)
{
    if (parent[x] != x)
        return parent[x] = findUF(parent[x]);
    return x;
}

void unionUF(int x, int y)
{
    int rootx = findUF(x);
    int rooty = findUF(y);
    if (rootx != rooty)
        parent[rooty] = rootx;
}

bool connected(int x, int y)
{
    int rootx = findUF(x);
    int rooty = findUF(y);
    return rootx == rooty;
}

int main()
{
    //freopen("in", "r", stdin);
    int tc;
    bool first = true;
    scanf("%d", &tc);
    while (tc--)
    {
        if (first)
            first = false;
        else
            printf("\n");
        int n, a, b, succ, unsucc;
        succ = unsucc = 0;
        char op;
        scanf("%d\n", &n);
        initUF(n);
        string line;
        while(getline(cin, line), line != "")
        {
            stringstream sstr(line);
            sstr >> op >> a >> b;
            if (op == 'c')
                unionUF(a, b);
            else{
                bool ans = connected(a, b);
                if (ans)
                    succ++;
                else
                    unsucc++;
            }
        }
        printf("%d,%d\n", succ, unsucc);
    }
    return 0;
}