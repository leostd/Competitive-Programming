#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

typedef long int li;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        li x;
        li y;
        li z;
        string op1, op2, res, ssign, esign;
        cin >> op1 >> ssign >> op2 >> esign >> res;
        if (op1.find("m") != string::npos)
        {
            y = stoi(op2);
            z = stoi(res);
            x = z - y;
        }
        else if (op2.find("m") != string::npos)
        {
            x = stoi(op1);
            z = stoi(res);
            y = z - x;
        }
        else
        {
            x = stoi(op1);
            y = stoi(op2);
            z = x + y;
        }
        printf("%li + %li = %li\n", x, y, z);
    }
    return 0;
}