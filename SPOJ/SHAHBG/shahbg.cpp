#include <stdlib.h>
#include <stdio.h>
using namespace std;

int pis[20002];

int main()
{
    int p, pi;
    scanf("%d", &p);
    int groups = 0;
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &pi);
        if (pis[pi+1] == 1 && pis[pi-1] == 1)
            groups--;
        else if (!(pis[pi+1] == 1 || pis[pi-1] == 1))
            groups++;
        pis[pi] = 1;
        printf("%d\n", groups);
    }
    printf("Justice\n");
    return 0;
}