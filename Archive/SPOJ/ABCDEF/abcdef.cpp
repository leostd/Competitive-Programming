#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> s;
    vector<int> ab, abc, fe, fed;
    int n;
    scanf("%d", &n);
    s = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    /* collect all the triplets that we can form. s^3*/
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                    abc.push_back((s[i]*s[j])+s[k]);
    /* collect all the triplets we can form but, with d != 0 */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (s[k] != 0)
                    fed.push_back((s[i] + s[j]) * s[k]);
    sort(fed.begin(), fed.end());
    int count = 0, tgt;
    pair <vector<int>::iterator, vector<int>::iterator> it;
    for (int i = 0; i < abc.size(); i++)
    {
        tgt = abc[i];
        it = equal_range(fed.begin(), fed.end(), tgt);
        count += (int)(it.second - it.first);
    }
    printf("%d\n", count);
}