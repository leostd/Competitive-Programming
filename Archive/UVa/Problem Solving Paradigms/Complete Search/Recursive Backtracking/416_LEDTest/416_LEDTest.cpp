#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int on[12];
int n;

void initMp(){
    mp[0]=126;
    mp[1]=48;
    mp[2]=109;
    mp[3]=121;
    mp[4]=51;
    mp[5]=91;
    mp[6]=95;
    mp[7]=112;
    mp[8]=127;
    mp[9]=123;
}


int main() {
    initMp();
    string s;
    while(scanf("%d",&n) == 1 && n){
        for (int i = 0; i < n; i++){
            cin >> s;
            on[i]=0;
            for (int j = 0; j < 7; j++){
                if (s[j]== 'Y')
                    on[i] |= (1 << (6-j));
            }
        }
        bool flag = 0;
        for (int i = 9; i >= 0; i--){
            int broken = 0b1111111;
            int j;
            if (i + 1 - n < 0)
                break;
            for (j = 0; j < n; j++){
                int must_on = broken & mp[i-j];
                if ((must_on | on[j]) != must_on)
                    break;
                broken = broken & ~(on[j] ^ must_on);
            }
            if (j == n) {
                flag = 1;
                break;
            }
        }
        printf("%s\n", (flag ? "MATCH":"MISMATCH"));
    }
    return 0;
}