#include <bits/stdc++.h>
using namespace std;


map<char, int> guestsByEntrance;
void initMap(){
    int i = 'A';
    for (i; i <= 'Z'; i++){
        guestsByEntrance[i]=0;
    }
}

int main() {
    //freopen("in", "r", stdin);
    int n, k;
    bool flag = true;
    string guests;
    scanf("%d %d\n", &n, &k);
    cin >> guests; 
    initMap();
    for (int i = 0; i < guests.size(); i++){
        guestsByEntrance[guests[i]]++;
    }
    set<char> guards;
    for(int i = 0; i < guests.size(); i++){
        if (guards.find(guests[i]) == guards.end()){
            if (k){
                guards.insert(guests[i]);
                k--;
                guestsByEntrance[guests[i]]--;
            }
            else{
                flag = false;
                break;
            }
        }
        else{
            guestsByEntrance[guests[i]]--;
        }
        if (guestsByEntrance[guests[i]] == 0)
            k++;
    }
    if (flag)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}