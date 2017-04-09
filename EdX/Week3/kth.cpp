#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <random>

typedef std::vector<int> vi;

unsigned seed = 666;
std::default_random_engine generator (seed);

void kstatistic(vi &arr, int l, int r, int k)
{
    int s, e, m;
    std::uniform_int_distribution<int> distribution(l,r);
    s = l;
    e = r;
    m = distribution(generator);
    int p = arr[m];
    while (s <= e)
    {
        while (arr[s] < p)
            ++s;
        while (arr[e] > p)
            --e;
        if (s <= e)
        {
            int buf = arr[s];
            arr[s] = arr[e];
            arr[e] = buf;
            ++s;
            --e;
        }
    }
    if (l <= e && k <= e)
        kstatistic(arr, l, e, k);
    if (s <= r && s <= k)
        kstatistic(arr, s, r, k);
}

void mqsort(vi &arr, int l, int r)
{
    int s, e, m;
    std::uniform_int_distribution<int> distribution(l,r);
    s = l;
    e = r;
    m = distribution(generator);
    int p = arr[m];
    while (s <= e)
    {
        while (arr[s] < p)
            ++s;
        while (arr[e] > p)
            --e;
        if (s <= e)
        {
            int buf = arr[s];
            arr[s] = arr[e];
            arr[e] = buf;
            ++s;
            --e;
        }
    }
    if (l <= e)
        mqsort(arr, l, e);
    if (s <= r)
        mqsort(arr, s, r);
}

int main()
{
    FILE *infile = fopen("kth.in", "r");
    FILE *outfile = fopen("kth.out", "w");
    int n;
    int k1, k2;
    int A, B, C, a1, a2;
    std::vector<int> arr;
    fscanf(infile, "%d %d %d", &n, &k1, &k2);
    fscanf(infile, "%d %d %d %d %d", &A, &B, &C, &a1, &a2);
    arr = std::vector<int>(n+1, 0);
    arr[1] = a1;
    arr[2] = a2;
    for (int i = 3; i <= n; i++)
        arr[i] = A * arr[i-2] + B * arr[i-1] + C;
    if (k1 - k2 == 0)
    {
        kstatistic(arr, 1, n, k1);
        fprintf(outfile, "%d", arr[k1]);
    }
    else
    {
        kstatistic(arr, 1, n, k1);
        kstatistic(arr, k1, n, k2);
        mqsort(arr, k1, k2);
        for (int i = k1; i <= k2; i++)
        {
            fprintf(outfile, "%d ", arr[i]);
        }
    }
    return 0;
}