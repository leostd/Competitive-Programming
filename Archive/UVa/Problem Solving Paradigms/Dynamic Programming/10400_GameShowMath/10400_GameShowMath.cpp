#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int nums[105], opsans[105];
bool visited[101][70000];
int n, p, t;
string ops = "+-/*";

int operation(int a, int b, int op)
{
    if (op == 0)
        return a + b;
    else if (op == 1)
        return a - b;
    else if (op == 2)
        return a / b;
    else if (op == 3 && b != 0 &&  a % b == 0)
        return a * b;
    else
        return -1;
}

bool bt(int idx, int acc)
{
    if (idx == p-1)
    {
        if (acc == t)
            return true;
        else
            return false;
    }
    else if (acc < -32000 || acc > 32000)
        return false;
    else if (visited[idx][acc + 32001])
        return false;
    else
    {
        visited[idx][acc + 32001] = true;
        int aux = nums[idx+1], ans; // initial state
        for (int i = 0; i < 4; i++)
        {
            nums[idx+1] = operation(nums[idx], nums[idx+1], i); // do the operation
            if (nums[idx+1] != -1){ // check if the operation is a valid one
                opsans[idx] = i; // save the index of the operation
                ans = bt(idx+1, nums[idx+1]); // recursive call
            }
            nums[idx+1] = aux; // return to the initial state;
            if (ans) // check if we have found a valid solution. cut
            {
                return ans;
            }
        }
        return false;
    }
}

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &p);
        for (int i = 0; i < p; i++)
            scanf("%d", &nums[i]);
        scanf("%d", &t);
        memset(visited, 0, sizeof(visited));
        int ans = bt(0, 0);
        if (ans){
            for (int i = 0; i < p; i++)
            {
                if (i < p-1)
                    printf("%d%c", nums[i], ops[opsans[i]]);
                else
                    printf("%d=%d\n", nums[i], t);
            }
        }
        else
            printf("NO EXPRESSION\n");
    }
    return 0;
}