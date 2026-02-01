#include <bits/stdc++.h>
using namespace std;


int main() {
    long long int n, m;
    cin >> n >> m;
    if (n > 26)
        cout << m;
    else{
        long long a = 1;
        for (int i = 0; i < n; i++)
            a *= 2;
        cout << m % a;
    }
    return 0;
}
