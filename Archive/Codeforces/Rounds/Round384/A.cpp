#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, a, b;
int idx, nearest;
int ia, ea;
int aps[100000];

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++)
        scanf("%1d", &aps[i]);
    ia = aps[a-1];
    ea = aps[b-1];
    if (ia == ea)
        printf("0\n");
    else
    {   
        printf("1\n");
    }
    return 0;
}