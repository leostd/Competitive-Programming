#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <string.h>
using namespace std;

struct TNode
{
    int words = 0;
    int prefixes = 0;
    map<char, int> ref;
};

TNode nodes[2000000];
int used = 0;

void addWord (TNode &v, deque<char> &word)
{
    if (word.empty())
    {
        v.prefixes++;
        v.words++;
    }
    else
    {
        v.prefixes++;
        char f = word.front();
        if (v.ref.count(f) == 0)
            v.ref[f] = used++;
        word.pop_front();
        addWord(nodes[v.ref[f]], word);
    }
}

int countPrefixes(TNode v, deque<char> &word)
{
    if (word.empty())
        return v.prefixes;
    else
    {
        char f = word.front();
        word.pop_front();
        if (v.ref.count(f) == 0)
            return 0;
        else
            return countPrefixes(nodes[v.ref[f]], word);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    char op[10];
    char c;
    deque<char> w;
    TNode trie;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s ", op);
        while(c = getchar(), c != '\n' && c != EOF)
            w.push_back(c);
        if (strcmp(op, "add") == 0)
            addWord(trie, w);
        else if (strcmp(op, "find") == 0)
            cout << countPrefixes(trie, w) << "\n";
        w.clear();
    }
    return 0;
}
