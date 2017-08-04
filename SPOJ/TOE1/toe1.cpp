#include <bits/stdc++.h>
using namespace std;

set<string> gset;

bool win(string game){
    string x = "XXX", o = "OOO";
    for (int i = 0; i < 9; i += 3){
        if (game.substr(i,3) == x || game.substr(i,3) == o)
            return true;
    }
    for (int i = 0; i < 3; i++){
        if (game[i] == game[i+3] && game[i+3] == game[i+6] && game [i] != '.')
            return true;
    }
    if (game[0] == game[4] && game[4] == game[8] && game[4] != '.')
        return true;
    if (game[2] == game[4] && game[4] == game[8] && game[4] != '.')
        return true;
    return false;
}


void generate(string &game, bool turn){
    if (gset.count(game))
        return;
    gset.insert(game);
    if (win(game)) return;
    for(int i = 0; i < 9; i++){
        if (game[i] == '.'){
            game[i] = turn ? 'X': 'O';
            generate(game, !turn);
            game[i] = '.';
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d\n", &n);
    char ch;
    int aux;
    string g = ".........";
    generate(g, 1);
    while(n--){
        g = "";
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                scanf("%c", &ch);
                g.push_back(ch);
            }
            scanf("\n");
        }
        scanf("\n");
        printf("%s\n", gset.count(g) ? "yes" : "no");
    }
    return 0;
}