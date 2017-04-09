#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
using std::string;
using std::cin;
using std::cout;
using std::set;

int main()
{
    string a;
    cin >> a;
    set<string> words;
    words.insert(a);
    char aux;
    for (int i = 0; i < a.size(); i++)
    {
        aux = a.back();
        a.pop_back();
        a = aux + a;
        words.insert(a);
    }
    printf("%lu\n", words.size());
}