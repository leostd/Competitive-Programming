#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <deque>
using namespace std;

typedef long long int lli;

/*
    ns: #persons at the i-th station
    n: number of stations
    tc: #test cases
    b: limit of persons that she can see
*/
int ns[100000];
int n, tc;
lli b;


/*
    s: size of the sliding window
    max_st: max #stations achieved
    sum: sum of the elements in the sw
    minsum: min sum achieved
    sw: sliding window
*/
int max_st;
lli sum, minsum;
deque<int> sw;

int main()
{
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        sum = minsum = 0;
        minsum = 100000005;
        max_st = 0;
        sw.clear();
        scanf("%d %lli", &n, &b);
        for (int j = 0; j < n; j++)
            scanf("%d", &ns[j]);
        for (int k = 0; k < n; k++)
        {
            sum += ns[k];
            sw.push_back(ns[k]);
            while(sum > b)
            {
                sum -= sw.front();
                sw.pop_front();
            }
            if (sw.size() > max_st || (sw.size() == max_st && sum < minsum))
            {
                minsum = sum;
                max_st = sw.size();
            }
        }
        printf("%lli %d\n", minsum, max_st);
    }
    return 0;
}