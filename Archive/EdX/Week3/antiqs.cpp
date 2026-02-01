#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

std::vector<int> aux;

void antiqs(unsigned int l, unsigned int r)
{
    if (l >= r-1)
        return;
    else
    {
        long long int mid = (l + r);
        mid = mid / 2;
        long long int max = aux[r];
        long long int buf;
        antiqs(l, r-1);
        buf = aux[mid];
        aux[mid] = max;
        aux[r] = buf;
    }
}

int main()
{
    FILE *infile = fopen("antiqs.in", "r");
    FILE *outfile = fopen("antiqs.out", "w");
    int n;
    fscanf(infile, "%d", &n);
    aux = std::vector<int>(n+2, 0);
    for (int i = 0; i <= n; i++)
        aux[i] = i;
    antiqs(1,n);
    for (int i = 1; i <= n; i++)
        fprintf(outfile, "%d ", aux[i]);
    return 0;
}
