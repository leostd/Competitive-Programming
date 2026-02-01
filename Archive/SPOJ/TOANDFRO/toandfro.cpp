#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int c;
    while(scanf("%d\n", &c), c != 0)
    {
        string line, row;
        vector<string> matrix;
        getline(cin, line);
        int i = 0;
        bool revert = false;
        while(i < line.size())
        {
            if ((i+1) % c == 0)
            {
                row.push_back(line[i]);
                if (revert)
                    reverse(row.begin(), row.end());
                revert = !revert;
                matrix.push_back(row);
                row = "";
            }
            else
            {
                row.push_back(line[i]);
            }
            ++i;
        }
        for(int j = 0; j < c; j++)
        {
            for(int k = 0; k < matrix.size(); k++)
            {
                printf("%c", matrix[k][j]);
            }
        }
        printf("\n");
    }   
    return 0;
}