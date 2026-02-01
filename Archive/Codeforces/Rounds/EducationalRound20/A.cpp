#include <bits/stdc++.h>
using namespace std;

int n, k;
int m[102][102];

void printm()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

bool symetric()
{
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (m[i][j] != m[j][i])
                return false;
    return true;
}
int main()
{
    scanf("%d %d", &n, &k);
    memset(m, 0, sizeof(m));
    int nelem = n*n;
    int nodiag = nelem - n;
    if (k > nelem)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n && k > 0; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (i == j)
            {
                m[i][i] = 1;
                k--;
            }
            else if (k >= 2)
            {
                m[i][j] = 1;
                m[j][i] = 1;
                k -= 2;
            }
            if (k <= 0)
                break;
        }
    }
    if (symetric())
        printm();
    else
        printf("-1\n");
    return 0;
}