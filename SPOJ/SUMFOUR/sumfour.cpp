#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long int li;

int main ()
{
    int n;
    scanf("%d", &n);
    vector<li> a, b, c, d;
    vector <li> ab, cd;
    a = b = c = d = vector<li>(n, 0);
    for (int i = 0; i < n; i++)
        scanf("%li %li %li %li", &a[i], &b[i], &c[i], &d[i]);

    /* sum of a[i] + b[j] elements in one vector. O(n^2) */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ab.push_back(a[i] + b[j]);
    /* sum of a[i] + b[j] elements in one vector. O(n^2) */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cd.push_back(c[i] + d[j]);
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    /* now we have (a + b) + (c + d) = 0, with the arrays sorted,
        we can search for -(a + b) in the cd array in logN */
    li tgt;
    li count = 0;
    pair<vector<li>::iterator, vector<li>::iterator> eq;
    for (int i = 0; i < ab.size(); i++) // O(n^2)
    {
        tgt = -ab[i];
        eq = equal_range(cd.begin(), cd.end(), tgt); // O(log(n^2)) = O (log(n)) 
        count += (int)(eq.second - eq.first);
    }
    printf("%li\n", count);
    return 0;
}