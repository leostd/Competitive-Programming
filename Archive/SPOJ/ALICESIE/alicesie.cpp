#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> marked;

int main()
{
    int t, n; 
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", (n + 1)/2);
    }
    return 0;
}