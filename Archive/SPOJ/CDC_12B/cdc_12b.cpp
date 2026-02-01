#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

typedef pair<int, string> is;

bool cmp (is a, is b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

bool cmp2 (is a, is b)
{
    return a.second < b.second;
}

int main()
{
    int t;
    int n, e;
    scanf("%d", &t);
    for (int sc = 1; sc <= t; ++sc)
    {
        scanf("%d %d", &n, &e);
        vector<is> tks(n, is(0, "")); // vector for all the tasks
        vector<string> c; // tasks that he can do
        for (int i = 0; i < n; ++i)
        {
            cin >> tks[i].second;
            scanf("%d", &tks[i].first);
        }
        sort(tks.begin(),tks.end(),[](pair<int,string> a, pair<int,string> b){
            if(a.first == b.first){
                return a.second < b.second;             
            }else {
                return a.first < b.first;
            }
        });
        int i = 0;
        int count = 0;
        while(i < n)
        {
            if (e - tks[i].first >= 0)
            {
                count++;
                e = e - tks[i].first;
                c.push_back(tks[i].second);
                e += count;
                i++;
            }
            else
                break;
        }
        sort(c.begin(), c.end());
        printf("Scenario #%d: %d\n", sc, count);
        for (i = 0; i < count-1; i++)
            printf("%s ", c[i].c_str());
        printf("%s\n", c.back().c_str());
    }
    return 0;
}