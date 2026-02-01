#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
using namespace std;

typedef long long int lli;

int main()
{
    int t, n, sc = 1;
    char c;
    lli sum;
    scanf("%d\n", &t);
    while(t--)
    {
        map<string, int> labels, gotos;
        sum = 0;
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++)
        {
            string line;
            bool first = false;
            while(c = getchar(), c != '\n' && c != EOF)
            {
                if (c == ' ' && !first)
                    continue;
                else
                {
                    first = true;
                    line.push_back(c);
                }

            }
            if (line == "")
                continue;
            if (line[line.size()-1] == ':') // check whether is a label or not 
            {
                int j = line.size()-2;
                while (j >= 0)
                    if (!isalpha(line[j--]))
                        break;       
                if (j == -1) // its a label
                {
                    line.pop_back();
                    labels[line] = i;
                }
            }
            else if (line[line.size()-1] == ';') // check whether is a goto statement or not
            {
                string aux = line.substr(0,5);
                int j=5;
                while(j < line.size()-1)
                    if (!isalpha(line[j++]))
                        break;
                if (aux.compare("goto ") == 0 && j == line.size()-1) //its a goto statement
                {
                    aux = line.substr(5, line.size()-1);
                    aux.pop_back();
                    sum += (i - labels[aux] - 1);
                }
            }
        }
        printf("Scenario #%d: %lli\n", sc++, sum);
    }
    return 0;
}