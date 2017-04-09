#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main ()
{
    int t;
    int sc = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, aux;
        vector<int> ns;
        vector<int> sns;
        map<int, int> reps;
        set<int> ssns;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &aux);
            ns.push_back(aux);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &aux);
            sns.push_back(aux);
            ssns.insert(aux);
        }
        for (int i = 0; i < n; i++)
        {
            if (ssns.count(ns[i]))
                reps[ns[i]]++;
        }
        printf("Scenario #%d: ", sc++);
        for(int i = 0; i < m; i++)
        {
            printf("%d",reps[sns[i]]);
        }
        printf("\n");
    }
    return 0;
}
