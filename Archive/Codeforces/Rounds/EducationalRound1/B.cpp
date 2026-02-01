#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int l, r, k, q;
    cin >> str;
    scanf("%d", &q);
    bool mark[10000];
    for (int i = 0; i < q; i++){
        scanf("%d %d %d", &l, &r, &k);
        l--; r--;
        int n = r - l + 1;
        k = k % n;
        int cur = 0, next = -1;
        char a, b;
        a = str[l];
        memset(mark, 0, sizeof(mark));
        for (int j = 0; j < n; j++){
            mark[cur] = true;
            next = (cur + k)%n;
            b = str[l+next];
            str[l+next] = a;
            a = b;
            cur = next;
            while(mark[cur]){
                cur++;
                a = str[cur+l];
            }
        }
    }
    cout << str << "\n";
    return 0;
}