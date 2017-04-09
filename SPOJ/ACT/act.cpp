#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t, n;
    string line;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d ", &n);
        cin >> line;
        printf("%c\n", line[line.size()-1]);
    }
    return 0;
}