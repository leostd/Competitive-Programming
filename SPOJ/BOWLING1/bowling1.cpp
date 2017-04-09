#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main()
{
    int t, b1, b2, points, frames;
    scanf("%d", &t);
    vi balls;
    while(t--)
    {
        points = 0;
        frames = 0;
        for (int i = 0; i < 10; i++)
        {
            scanf("%d", &b1);
            balls.push_back(b1);
            if (b1 == 10)
            {
                if (i == 9)
                {
                    int aux1, aux2;
                    scanf("%d %d", &aux1, &aux2);
                    balls.push_back(aux1);
                    balls.push_back(aux2);
                    continue;
                }
                else
                    continue;
            }
            scanf("%d", &b2);
            balls.push_back(b2);
            if (b1 + b2 == 10 && i == 9)
            {
                int aux1;
                scanf("%d", &aux1);
                balls.push_back(aux1);
            }
        }
        int i = 0;
        while(i < balls.size() && frames < 10)
        {
            b1 = balls[i];
            points += b1;
            if (b1 == 10 && frames < 10)
            {
                if (i + 1 < balls.size() && i + 2 < balls.size())
                    points += (balls[i+1]+balls[i+2]);
            }
            else
            {
                b2 = balls[++i];
                points += b2;
                if (b1 + b2 == 10 && i+1 < balls.size())
                    points += balls[i+1];
            }
            ++frames;
            ++i;
        }
        printf("%d\n", points);   
        balls.clear();
    }
}