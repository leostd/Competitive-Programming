#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    int n, t, k, d;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    int aux = n, counter, counter2;
    counter = counter2 = 0;
    counter = t * (ceil((double)n/k)); // without other oven
    int oven1 = t;
    int oven2 = t + d;
    priority_queue<int, vector<int>, greater<int>> bakes;
    bakes.push(oven1);
    while(aux > 0) {
        int a = bakes.top();
        bakes.pop();
        aux -= k;
        if (aux <= 0)
            counter = a;
        bakes.push(a+t);
    }
    priority_queue<int, vector<int>, greater<int>> bakes2;
    bakes2.push(oven1);
    bakes2.push(oven2);
    aux = n;
    while(aux > 0) {
        int a = bakes2.top();
        bakes2.pop();
        aux -= k;
        if (aux <= 0)
            counter2 = a;
        bakes2.push(a+t);
    }
    if (counter <= counter2)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}