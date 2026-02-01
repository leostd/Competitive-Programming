#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sstream>

using namespace std;

typedef vector<int> vi;

int main()
{
    freopen("MyDearNeighbours.in", "r", stdin);
    int n, p, neighbour;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d\n", &p);
        vi minDegs;
        int minDeg = INT_MAX;
        vi ns;
        int degree=0;
        for(int j = 0; j < p; j++)
        {
            string line;
            getline(cin, line);
            stringstream sstr(line);
            degree = 0;
            while(sstr >> neighbour)
                degree++;
            if(degree == minDeg)
                minDegs.push_back(i+1);
            else if(degree < minDeg)
            {
                minDeg = degree;
                minDegs.clear();
                minDegs.push_back(j+1);
            }
        }
        for(int j = 0; j < minDegs.size(); ++j)
            printf("%d ", minDegs[j]);
        printf("\n");
    }
    return 0;
}
