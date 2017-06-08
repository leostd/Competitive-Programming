#include <bits/stdc++.h>
#define EPS 10e-9
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    //freopen("in", "r", stdin);
    int k, x, y;
    while(scanf("%d", &k) != EOF) {
        x = 0x3f3f3f3f;
        double aux, intpart;
        vii ns;
        y = k+1;
        double fracpart;
        while (y < x) {
            aux = (double)(k*y) / (y-k);
            fracpart = modf(aux, &intpart);
            if (fracpart < EPS) {
                x = (int)aux;
                if (y <= x)
                    ns.push_back(ii(x,y));
            }
            y++;
        }
        printf("%d\n", ns.size());
        for (int i = 0; i < ns.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k, ns[i].first, ns[i].second);
    }
    return 0;
}