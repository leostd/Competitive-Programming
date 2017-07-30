#include <bits/stdc++.h>
using namespace std;

set<string> possibles;
string g;
int xs, os, total;
bool mark[10];

bool play(char l, int turn){
    if (turn == total)
        return true;
    else if ((l == 'X' && !xs) || (l == 'O' && !os && xs))
        return false;
    else{
        for (int i = 0; i < 9;i++){
            //printf("%c", grid[i]);
            if (g[i] == l){
                g[i] = '.';
                if (l == 'X') 
                    xs--;
                else
                    os--;
                return play((l == 'X')? 'O': 'X', turn+1);
            }   
        }
    }
    return false;
}

int main() {
    freopen("in", "r", stdin);
    int n;
    scanf("%d\n", &n);
    char ch;
    int aux;
    while(n--){
        g = "";
        xs = os = 0;
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                scanf("%c", &ch);
                g.push_back(ch);
                if (ch == 'X') 
                    xs++;
                else if (ch == 'O')
                    os++;
            }
            scanf("\n");
        }
        aux = os;
        aux = xs;
        total = os+xs;
        aux = total;
        if (play('X', 0))
            printf("yes\n");
        else
            printf("no\n");
        scanf("\n");
    }
    return 0;
}