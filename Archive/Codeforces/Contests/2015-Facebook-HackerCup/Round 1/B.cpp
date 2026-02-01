#include <bits/stdc++.h>
#define N 1000000
using namespace std;

struct TNode {
    int words;
    int prefixes;
    map<char, int> ref;
};

TNode trie[N];
int t, n, used, ans;

void inicializar()
{
    used = 1;
    trie[0].ref.clear();
    trie[0].words = 0;
    trie[0].prefixes = 0;
}

void vaciar(int node)
{
    trie[node].ref.clear();
    trie[node].words = 0;
    trie[node].prefixes = 0;
}

void addWord(string w)
{
    int pos = 0;
    int c = 0;
    bool first = true;
    for (int i = 0; i < w.size(); ++i)
    {
        if (first)
            c++;
        if (trie[pos].ref.count(w[i]) == 0)
        {
            trie[pos].ref[w[i]] = used;
            vaciar(used++);
            if (first)
            {
                ans += c;
                first = false;
            }
        }
        pos = trie[pos].ref[w[i]];
    }
    if (first)
        ans += c;
    trie[pos].words++;
}

int main()
{
    scanf("%d", &t);
    char ch;
    string w;
    for (int i = 0; i < t; i++)
    {
        scanf("%d\n", &n);
        ans = 0;
        inicializar();
        for (int j = 0; j < n; ++j)
        {
            cin >> w;
            addWord(w);
        }
        printf("Case #%d: %d\n", i+1, ans);
    }
    return 0;
}