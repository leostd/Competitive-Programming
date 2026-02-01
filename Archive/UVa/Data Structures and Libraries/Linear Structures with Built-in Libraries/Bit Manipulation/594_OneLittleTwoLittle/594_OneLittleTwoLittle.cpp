#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        bitset<32> bn(n);
        bitset<8> aux;
        //cout << bn.to_string() << endl;
        printf("%d converts to ", (int)bn.to_ulong());
        for (int i = 0; i < 8; i++)
        {
            aux[i] = bn[i];
            bn[i] = bn[24+i];
            bn[24+i] = aux[i];
        }

        for (int i = 8, j = 0; i < 16; i++, j++)
        {
            aux[i] = bn[i];
            bn[i] = bn[16+j];
            bn[16+j] = aux[i];
        }
        printf("%d\n", (int)bn.to_ulong());
        //cout << bn.to_string() << endl;
    }
    return 0;
}