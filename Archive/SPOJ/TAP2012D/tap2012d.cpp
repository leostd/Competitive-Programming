#include <bits/stdc++.h>
#define N 1000007
using namespace std;

struct tnode {
    int prefixes, words;
    int next[27], disp[27];
    tnode() { prefixes = words = 0; }
};

tnode trie[N];
int nodes, ans;

void tinit () {
    nodes = 1;
    for(int i = 0; i < 27; i++) {
        trie[0].next[i] = -1;
        trie[0].disp[i] = 0;
    }
    trie[0].prefixes = trie[0].words = 0;
}

void tinsert(string s) {
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (trie[pos].next[s[i]-65] == -1){
            trie[nodes].prefixes = trie[nodes].words = 0;
            for (int j = 0; j < 27; ++j){
                trie[nodes].next[j] = -1;
                trie[nodes].disp[j] = 0;
            }
            trie[pos].next[s[i]-65] = nodes;
            trie[pos].disp[s[i]-65]++;
            nodes++;
        }
        else
            trie[pos].disp[s[i]-65]++;
        trie[pos].prefixes++;
        pos = trie[pos].next[s[i]-65];
    }
    trie[pos].words++;
}

void process(string s) {
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (trie[pos].next[s[i]-65] != -1){
            int aux = ans;
            if (trie[pos].disp[s[i]-65] > 0){
                ans++;
                trie[pos].disp[s[i]-65]--;
            }
            pos = trie[pos].next[s[i]-65];
        }
        else
            break;
    }
}

int main () {
    //freopen("in", "r", stdin);
    int n;
    string g2[10004];
    while(scanf("%d", &n), n != -1) {
        string a;
        ans = 0;
        tinit();
        for (int i = 0; i < n; i++) {
            cin >> a;
            tinsert(a);
        }
        
        for (int i = 0; i < n; i++){
            cin >> a;
            process(a);
        }
        printf("%d\n", ans);
    }
    return 0;
}
