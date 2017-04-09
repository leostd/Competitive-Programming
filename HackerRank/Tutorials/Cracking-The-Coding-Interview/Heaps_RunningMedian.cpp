#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main(){
    int n;
    priority_queue<int,vector<int>, greater<int>> ls;
    priority_queue<int, vector<int>, less<int>> gs;
    int sz = 0;
    double b = 0.0;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    for (int i = 0; i < n; i++)
    {
       if (sz == 0)
           ls.push(a[i]);
        else
        {
            if (gs.empty())
                ls.push(a[i]);
            else if (b < a[i])
                ls.push(a[i]);
            else
                gs.push(a[i]);
            if ((int)gs.size() - (int)ls.size() > 1) //gs > ls
            {
                ls.push(gs.top());
                gs.pop();
            }
            else if ((int)ls.size() - (int)gs.size() >  1)
            {
                gs.push(ls.top());
                ls.pop();
            }
        }
        sz++;
        if (sz % 2 == 0)
        {
            b = (gs.top() + ls.top()) / 2.0;
        }
        else
        {
            if (gs.size() > ls.size())
                b = gs.top();
            else
                b = ls.top();
        }
        printf("%.1lf\n", b);
    }
    return 0;
}