#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int n,m;
    scanf("%d %d", &n, &m);
    cin >> str;
    int l,r;
    char c1, c2;
    for (int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        l--, r--;
        getchar();
        c1 = getchar();
        getchar();
        c2 = getchar();
        for(l; l <= r; l++)
            if (str[l] == c1)
                str[l] = c2;
    }
    cout << str << "\n";
    return 0;
}
