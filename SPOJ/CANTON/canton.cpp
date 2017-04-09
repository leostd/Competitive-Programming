#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const unsigned k = 10000000;
ii terms[k];

void precalculate()
{
    int a, b;
    unsigned i = 0;
    bool up, right = true;
    a = b = 1;
    while(i != k)
    {
        terms[i] = ii(a, b);
        if (a == 1 && right)
        {
            b++;
            up = false;
            i++;
            right = false;
        }
        else if (b == 1 && right)
        {
            a++;
            up = true;
            i++;
            right = false;
        }
        else if (a != 1 && b != 1 || !right)
        {
            if (up)
            {
                a--;
                b++;
                i++;
            }
            else
            {
                b--;
                a++;
                i++;
            }
            right = true;
        }
    }
}

int main()
{
    int t;
    unsigned q;
    precalculate();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%u", &q);
        printf("TERM %d IS %d/%d\n", q, terms[q-1].first, terms[q-1].second);
    }
    return 0;
}