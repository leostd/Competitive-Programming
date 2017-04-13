#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, ll> ill;
typedef vector<ill> vill

int n;
ll str[300007];
int idx[300007];
vill g[300007];
bool status[3000007];

bool comp(int a, int b)
{
    return g[a].size() < g[b].size();
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        idx[i] = i;
    }
    int a, b;
    int ms = 0x3f3f3f;
    for (int i = 0; i < n-1; i++)
    {
        scanf ("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    sort(idx, idx+n, comp);
    
    return 0;
}