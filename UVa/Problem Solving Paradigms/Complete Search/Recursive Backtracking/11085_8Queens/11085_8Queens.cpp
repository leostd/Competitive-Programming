#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
    There is one queen per column. The row where is placed
    the i-th queen (the queen in the i-th column) wil be 
    in one array.
*/

typedef vector<int> vi;
vector<vi> sols; // vector of all the posible solutions
vi rows; // vector for the row coord of the i-th queen

// can we place a queen in the (r, c) square?
bool place(int r, int c)
{
    for (int prev = 0; prev < c; prev++)
    {
        if (r == rows[prev] || abs(r - rows[prev]) == abs(c - prev)) // we only have to check this condition. row and diagonal attack
            return false;
    }
    return true;
}

void backtrack(int c)
{
    if (c == 8)
        sols.push_back(rows);
    else
    {
        for (int i = 0; i < 8; i++)
            if (place(i, c))
            {
                rows[c] = i;
                backtrack(c+1);
            }
    }
}

int main()
{
    int tc = 1, a;
    rows = vi(8, 0);
    backtrack(0); // precalculate all the possible solutions. 8! = O(41K) iterations
    vi in(8, 0); // input vector
    while(scanf("%d", &in[0]) != EOF)
    {
        for (int i = 1; i <= 7; i++)
            scanf("%d", &in[i]);
        int count;
        int minc = 10; // minimum moves, initialize with an upper bound 
        for (int i = 0; i < sols.size(); i++)
        {
            count = 0;
            for (int j = 0; j < 8; j++)
                if (sols[i][j] != in[j]-1)
                    count++;
            if (count < minc)
                minc = count;
        }
        printf("Case %d: %d\n", tc++, minc);
    }
    return 0;
}