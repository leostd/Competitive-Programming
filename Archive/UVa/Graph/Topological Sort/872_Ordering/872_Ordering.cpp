#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;
typedef vector<int> vi;
char var[30], ord[30];
vi g[30];
int v, in_degree[30], idx;
bool a[30], flag;


void debug(string str){
    if (DEBUG == 1)
        cout << "DEBUG: " << str << "\n";
}

void print_order(){
    for (int i = 0; i < v; i++){
        printf("%c", ord[i]);
        if (i < v-1)
            printf(" ");
    }
    printf("\n");
}

void orderings(int availables){
    if (!availables){
        flag = true;
        print_order();
    }
    else{
        for (int i = 0; i < v; i++){
            if (in_degree[var[i]-'A'] == 0 && a[var[i]-'A']){
                ord[idx++] = var[i];
                a[var[i]-'A'] = 0;
                for(int j = 0; j < g[var[i]-'A'].size(); j++)
                    in_degree[g[var[i]-'A'][j]]--;
                orderings(availables-1);
                idx--;
                a[var[i]-'A'] = 1;
                for (int j = 0; j < g[var[i]-'A'].size(); j++)
                    in_degree[g[var[i]-'A'][j]]++;
            }
        }
    }
}

int main(){
    int t;
    scanf("%d\n", &t);
    while(t--){
        scanf("\n");
        char in[1000];
        fgets(in, 1000, stdin);
        v = 0;
        flag = false;
        memset(in_degree, -1, sizeof(in_degree));
        for (int i = 0; i < strlen(in); i += 2){
            var[i/2] = in[i];
            v++;
            in_degree[in[i]-'A'] = 0;
        }
        sort(var, var+v);
        fgets(in, 1000, stdin);
        for (int i = 0; i < 30; i++)
            g[i] = vi();
        for (int i = 0; i < strlen(in); i+=4){
            g[in[i]-'A'].push_back(in[i+2]-'A');
            in_degree[in[i+2]-'A']++;
        }
        memset(a, true, sizeof(a));
        idx = 0;
        orderings(v);
        if (!flag)
            printf("NO\n");
        if (t > 0)
            printf("\n");
    }
    return 0;
}