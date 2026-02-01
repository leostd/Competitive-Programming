#include <bits/stdc++.h>
using namespace std;

int t, k, turns;
int j;
bool s[1200];

void turn(int idx)
{
    turns++;
    int pan = idx+k;
    for (idx; idx < pan; ++idx)
        s[idx] = !s[idx];
}

int main()
{
    scanf("%d\n", &t);
    for (int i = 1; i <= t; ++i)
    {
        memset(s, false, sizeof(s));
        bool flag = true;
        turns = 0;
        char ch;
        j = 0;
        while(ch = getchar(), ch != ' ')
            s[j++] = (ch == '+') ? true : false;
        scanf("%d\n", &k);
        for (int l = 0; l <= j-k; ++l)
            if (!s[l])
                turn(l);
        for (int l = 0; l < j; ++l)
            if (!s[l])
                flag = false;
        printf("Case #%d: ", i);
        if (flag)
            printf("%d\n", turns);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
