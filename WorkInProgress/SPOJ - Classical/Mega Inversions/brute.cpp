#include <iostream>

using namespace std;

#define MAXN 100005

int main(){
    int a[MAXN], n;

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int left = 0, right = 0;
        for (int j = 1; j <= n; j++) {
            if (j == i)
                continue;
            if (j < i) 
                left += a[j] > a[i];
            else
                right += a[j] < a[i];
        }
        ans += left*right;
    }

    cout << ans << endl;

    return 0;
}