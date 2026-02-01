#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(scanf("%d", &n), n)
    {
        int a, b;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            pq.push(a);
        }
        int ans = 0, acum = 0;
        while(pq.size() != 1)
        {
            a = pq.top();
            pq.pop();
            b = (!pq.empty()) ? pq.top() : 0;
            if (!pq.empty())
                pq.pop();
            pq.push(a+b);
            acum += (a+b);
        }
        printf("%d\n", acum);
        pq.pop();
    }
    return 0;
}