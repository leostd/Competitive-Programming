#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

int fastpow(int a, int e)
{
    if (e == 0)
        return 1;
    else if (e == 1)
        return a;
    else if (e % 2 == 0)
        return fastpow(a,e/2) * fastpow(a, e/2);
    else if (e % 2 == 1)
        return a * fastpow(a, e-1);
}

int main()
{
    int t, n, m;
    int wd, count;
    scanf("%d", &t);
    while(t--)
    {
        count = 0;
        scanf("%d %d", &n, &m);
        vector<bool> aux(fastpow(2,n), true), aux2;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &wd);
            aux[wd-1] = 0;
        }
        while(aux.size() > 1)
        {
            for (int i = 0; i < ceil(aux.size()); i+=2)
            {
                if (aux[i] ^ aux[i+1])
                    count++;
                aux2.push_back(aux[i] | aux[i+1]);
            }
            aux = aux2;
            aux2.clear();
        }
        printf("%d\n", count);

    }
    return 0;
}