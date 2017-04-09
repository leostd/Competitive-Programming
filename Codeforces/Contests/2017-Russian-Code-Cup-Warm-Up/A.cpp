#include <iostream>
#include <algorithm>
#include <math.h>
#include <bitset>
using namespace std;

int n;
int ns[100007];
bitset<100007> bs;
int sum = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ns[i];
        sum += ns[i];
    }
    sort(ns, ns+n);
    int idx;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int aux = sum;
        aux -= ns[i];
        if (aux == ns[i])
        {
            flag = true;
            idx = i;
            break;
        }
    }
    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == idx)
                continue;
            cout << ns[i] << " ";
        }
        cout << ns[idx] << "\n";
    }
    return 0;
}
