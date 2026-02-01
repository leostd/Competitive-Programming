#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main()
{
    //freopen("in", "r", stdin);
    int n;
    ii ps[1007];
    bool bs, bq, bpq;
    while(scanf("%d", &n) != EOF)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int op, r;
        bs = bq = bpq = true;
        for (int i = 0; i < n; i++){
            scanf("%d %d", &op, &r);
            if (op == 1)
            {
                s.push(r);
                q.push(r);
                pq.push(r);
            }
            else
            {
                if (bs){
                    if (!s.empty() && s.top() == r)
                        s.pop();
                    else
                        bs = false;
                }
                if (bq){
                     if (!q.empty() && q.front() == r)
                        q.pop();
                     else
                        bq = false;
                }
                if (bpq)
                {
                    if (!pq.empty() && pq.top() == r)
                        pq.pop();
                    else
                        bpq = false;
                }
            }
        }
        int ans = bpq + bs + bq;
        if (ans == 0)
            printf("impossible");
        else if (ans > 1)
            printf("not sure");
        else
        {
            if (bpq)
                printf("priority queue");
            else if (bq)
                printf("queue");
            else
                printf("stack");
        }
        printf("\n");
    
    }
    return 0;
}