#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int counters[10];

bool can (int n)
{
    n++;
    while ( n < 10)
    {
        if (counters[n])
            return false;
        n++;
    }
    return true;
}

int main()
{
    //freopen("pqueue.txt", "r", stdin);
    //freopen("pqueueout.txt", "w", stdout);
    int t, m, n, a;
    int secs;
    queue<bool> chk;
    queue<int> q;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        secs = 0;
        q = queue<int>();
        chk = queue<bool>();
        for (int j = 1; j <= 9; j++)
            counters[j] = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a);
            counters[a]++;
            q.push(a);
            if (j == m)
                chk.push(true);
            else
                chk.push(false);
        }
        while (!q.empty())
        {
            if (can(q.front()))
            {
                if (chk.front())
                {
                    printf("%d\n", secs+1);
                    break;
                }
                else
                {
                    secs++;
                    counters[q.front()]--;
                    q.pop();
                    chk.pop();
                }
            }
            else
            {
                q.push(q.front());
                q.pop();
                chk.push(chk.front());
                chk.pop();
            }
        }
    }
    return 0;
}
