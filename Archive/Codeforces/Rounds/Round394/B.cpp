#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    int n, m, a, b;
    deque<int> dq1, dq2;
    vi v1, v2;
    bool flag;
    cin >> n >> m;
    cin >> a;
    v1.push_back(a);
    for (int i = 1; i < n; i++){
        cin >> b;
        v1.push_back(b);
        dq1.push_back(abs(a-b));
        a = b;
    }
    dq1.push_back(abs(v1[0]+m-v1[n-1]));
    cin >> a;
    v2.push_back(a);
    for (int i = 1; i < n; i++){
        cin >> b;
        v2.push_back(abs(b));
        dq2.push_back(abs(a-b));
        a = b;
    }
    dq2.push_back(abs((v2[0]+m-v2[n-1])));
    for (int i = 0; i < dq2.size(); i++){
        if (dq1 == dq2)
            flag = true;
        a = dq2.front();
        dq2.pop_front();
        dq2.push_back(a);
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";        
}
