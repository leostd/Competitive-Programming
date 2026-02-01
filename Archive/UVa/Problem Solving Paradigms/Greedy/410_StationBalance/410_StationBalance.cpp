#include <bits/stdc++.h>
#define C 5
#define S 10
using namespace std;

typedef pair<int, int> ii;

int main(){
    int c, s, t = 1;
    int mass[S];
    ii chambers[C];
    while(scanf("%d %d", &c, &s) != EOF){
        memset(mass, 0, sizeof(mass));
        double total_mass = 0;
        for(int i = 0; i < s; i++){
            scanf("%d", &mass[i]);
            total_mass += mass[i];
        }
        sort(mass, mass + 2*c);
        double imbalance = 0.0, avg = total_mass/(double)c;
        for(int i = 0; i < c; i++){
            chambers[i].first = mass[i];
            chambers[i].second = 2*c-1-i == i ? 0: mass[2*c-1-i];
            imbalance += fabs((double)(chambers[i].first + chambers[i].second) - avg);
        }
        printf("Set #%d\n", t++);
        for(int i = 0; i < c; i++){
            printf("%2d:", i);
            if (chambers[i].first == 0 && chambers[i].second == 0)
                printf("\n");
            else if(chambers[i].first == 0 && chambers[i].second > 0)
                printf(" %d\n", chambers[i].second);
            else if (chambers[i].second == 0 && chambers[i].first > 0)
                printf(" %d\n", chambers[i].first);
            else if (chambers[i].first > 0 && chambers[i].second > 0)
                printf(" %d %d\n", chambers[i].first, chambers[i].second);

        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
    return 0;
}
