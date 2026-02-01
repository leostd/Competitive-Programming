#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    vi alpha[200];
    char ch;
    int i = 0;
    while(ch = getchar(), ch != '\n')
        alpha[ch].push_back(i++);
    string str;
    int s, e, act, q, prev;
    scanf("%d", &q);
    while(q--){
        cin >> str;
        s = e = act = prev  = -1;
        for(int i = 0; i < str.size(); i++){
            auto it = upper_bound(alpha[str[i]].begin(), alpha[str[i]].end(), prev);
            act = alpha[str[i]][it - alpha[str[i]].begin()];
            if (it == alpha[str[i]].end()){
                e = -1;
                break;
            }
            else{
                if (i == 0)
                    s = act;
                if (i == str.size()-1)
                    e = act;
                prev = act;
            }
        }
        if (e == -1)
            printf("Not matched\n");
        else
            printf("Matched %d %d\n", s, e);
    }
    return 0;
}
