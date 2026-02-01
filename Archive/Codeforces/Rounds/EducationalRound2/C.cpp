#include <bits/stdc++.h>
using namespace std;



int main(){
    char ch;
    int n = 0;
    map<char, int> c;
    ch = getchar();
    while(ch >= 'a' && ch <= 'z'){
        c[ch]++;
        ch = getchar();
        n++;
    }
    bool palindrome = true, first = true;
    int odds = 0;
    for(auto it = c.begin(); it != c.end(); ++it) {
        if (it->second % 2 != 0 && first) {
            first = false;
            odds++;
        } else if (it->second % 2 != 0 && !first) {
            palindrome = false;
            odds++;
        }
    }
    if (!palindrome) {
        auto l = c.begin();
        auto r = c.end();
        r--;
        while (odds > 1) {
            while (r->second % 2 == 0)
                r--;
            while (l->second % 2 == 0)
                l++;
            r->second--;
            l->second++;
            odds -= 2;
        }
    }
    int i = 0, j = n-1;
    string str(n, 'X');
    auto it = c.begin();
    char aux = 'x';
    for(it; it != c.end(); ++it){
        while(it->second > 1){
            str[i] = str[j] = it->first;
            it->second-=2;
            i++; j--;
        }
        if (it->second)
            aux = it->first;
    }
    if (n%2 != 0)
        str[n/2] = aux;
    cout << str << "\n";
    return 0;
}
