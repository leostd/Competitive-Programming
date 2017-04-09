#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;

int ns[100000], l[100000], l_id[100000], pred[100000];

int main()
{
    int n, i = 0, size = 0, pos, lis_end;
    while(scanf("%d", &n) != EOF)
        ns[i++] = n;
    for (int j = 0; j < i; j++)
    {
        pos = lower_bound(l, l+size, ns[j]) - l;
        l[pos] = ns[j];
        l_id[pos] = j;
        pred[j] = pos ? l_id[pos-1]:-1;
        if (size < pos + 1)
        {
            size = pos + 1;
            lis_end = j;
        }
        else if (pos + 1 == size)
            lis_end = j;
    }
    printf("%d\n-\n", size);
    stack<int> ans;
    int aux = lis_end;
    while(aux >= 0 )
    {
        ans.push(aux);
        aux = pred[aux];
    }
    while(!ans.empty())
    {
        aux = ans.top();
        ans.pop();
        printf("%d\n", ns[aux]);
    }
    return 0;
}