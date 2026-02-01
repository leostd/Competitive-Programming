#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int memo[25][25];
int n, correct[25], student[25];

int dp(int c, int s){
    int &ret = memo[c][s];
    if (c == n || s == n)
        return ret = 0;
    if (ret != -1)
        return ret;
    ret = 0;
    if (correct[c] == student[s])
        return ret = 1 + dp(c+1, s+1);
    ret = max(dp(c+1, s), dp(c, s+1));
    return ret;
}

int main()
{
    int x;
    scanf("%d", &n);
    while(n != -1)
    {
        for (int i = 0; i < n; i++){
            scanf("%d", &x);
            correct[x-1] = i;
        }
        string line;
        scanf("\n");
        while(getline(cin, line)){
            if (line == "")
            {
                n = -1;
                break;
            }
            stringstream sstr(line);
            int i = 0;
            while(sstr >> x){
                student[x-1] = i;
                i++;
            }
            if (i == 1){
                n = x;
                break;
            }
            else{
                memset(memo, -1, sizeof(memo));
                int ans = dp(0, 0);
                printf("%d\n", ans);
            }
        }
        if (cin.eof()){
            n = -1;
            break;
        }
    }
    return 0;
}