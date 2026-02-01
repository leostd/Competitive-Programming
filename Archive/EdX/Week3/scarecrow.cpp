#include <vector>
#include <unordered_map>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

typedef long long int lli;
typedef std::vector<lli> vlli;

vlli matrys, aux;
int n,k;

int bs(int a, int b, int t) // binary search
{
    int mid;
    if (aux[a] == t)
        return a;
    if (aux[b] == t)
        return b;
    while (b - a > 1)
    {
        mid = a + (b - a) / 2;
        if (aux[mid] == t)
            return mid;
        else if (aux[mid] > t)
            b = mid;
        else if (aux[mid] < t)
            a = mid;
    }
    if (aux[a] == t)
        return a;
    else if (aux[b] == t)
        return b;
    else
        return -1; // return -1 if the element doesn't exist
}

bool scareswap(int idx)
{
    lli b;
    int tgt, dist, h, l;
    b = matrys[idx]; // the number to put in place
    tgt = bs(idx, aux.size()-1, b); // the index of the first ocurrence at the sorted array
    h = tgt;
    while (aux[h] == b)
    {
       dist = h - idx; // the distance between de actual position and the target position
       if (dist % k == 0) // if the distance is multiple of k then put it in place
       {
           std::swap(matrys[idx], matrys[h]); 
           return true;
       }
       h++; // if there are more than one ocurrence of the target number, there are contiguous
    }
    l = tgt; // if the BS find the element at the end of the array, then, it must search in deacreasing order
    while (aux[l] == b)
    {
        dist = l - idx;
        if (dist % k == 0)
        {
            std::swap(matrys[idx], matrys[l]);
            return true;
        }
        l--;
    }
    return false; // return false if we can't swap the elements
}

int main()
{
    FILE *infile = fopen("scarecrow.in", "r");
    FILE *outfile = fopen("scarecrow.out", "w");
    lli a;
    int b, idx = 0;
    lli sz;
    fscanf(infile, "%d %d", &n, &k);
    matrys = vlli(n, 0);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        fscanf(infile, "%lli", &matrys[i]);
    }
    aux = matrys;
    std::sort(aux.begin(), aux.end()); // sort a copy of the array
    while(n > 0) // at the beginning, assume that there are n unsorted elements 
    {
        if (aux[idx] == matrys[idx]) // if they are equal the number is in place
        {
            n--; // deacrease the number of unsorted elements
            idx++; // increase the index
        }
        else
        {
            if (!scareswap(idx)) // if we cannot swap, print NO, and break
            {
                fprintf(outfile, "NO\n");
                flag = false;
                break;
            }
            else // otherwise, we deacrease the numbers of usorted elements
            {
                n--;
            }
        }
    }
    if (flag)
        fprintf(outfile, "YES\n");
    return 0;
}