#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, char> ic;
typedef vector <ic> vic;

int main(){
    set<char> complexity;
    map<char, int> code;
    vic decode;
    string s;
    int ops = 0; 
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        complexity.insert(s[i]);
        code[s[i]]++;
    }
    if (complexity.size() <= 2)
        cout << 0 << "\n";
    else {
        for (auto it = code.begin(); it != code.end(); ++it)
            decode.push_back(ic(it->second, it->first));
        sort(decode.begin(), decode.end());
        for (auto it = decode.begin(); it != decode.end(); ++it){
            ops += it->first;
            complexity.erase(it->second);
            if (complexity.size() <= 2)
                break;   
        }
        cout << ops << "\n";

    }
    return 0;
}