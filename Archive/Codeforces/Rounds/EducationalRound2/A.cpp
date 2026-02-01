#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2, a, b;
    int cnt1, cnt2;
    cin >> s1;
    cnt1 = cnt2 = 0;
    for (int i = 0; i <= s1.size(); i++){
        if (s1[i] == ';' || s1[i] == ',' || i == s1.size()){
            bool integer = s2.size() > 0;
            for(int j = 0; j < s2.size(); j++){
                if (!isdigit(s2[j])){
                    integer = false;
                    break;
                }
            }
            if (integer){
                if(s2[0] == '0' && s2.size() > 1)
                    integer = false;
            }
            if (integer){
                if (cnt1)
                    a += ',' + s2;
                else
                    a += s2;
                cnt1++;
            }
            else{
                if (cnt2)
                    b += ',' + s2;
                else
                    b += s2;
                cnt2++;
            }
            s2.clear();
        }
        else{
            s2.push_back(s1[i]);
        }
    }
    if (a.empty() && cnt1 == 0)
        cout << "-" << "\n";
    else
        cout << "\"" << a << "\"\n";
    if (b.empty() && cnt2 == 0)
        cout << "-" << "\n";
    else
        cout << "\"" << b << "\"\n";
    return 0;
}
