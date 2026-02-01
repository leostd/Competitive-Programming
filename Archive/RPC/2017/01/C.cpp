#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef pair<string, string> fn; //full name
string name;
vector<fn> s;

bool cmp(fn a, fn b){
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main(){
    int n;
    scanf("%d", &n);
    s = vector<fn>(n, fn());
    for(int i = 0; i < n; i++){
        cin >> s[i].first >> s[i].second;
    }
        
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < n; i++){
        cout << s[i].first << " " << s[i].second << "\n";
    }
    return 0;
}