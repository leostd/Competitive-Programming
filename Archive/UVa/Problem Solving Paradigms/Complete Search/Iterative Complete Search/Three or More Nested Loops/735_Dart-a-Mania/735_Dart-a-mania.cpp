#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
vi values;
set<int> nums;
int main(){
    //freopen("in", "r", stdin);
    for(int i = 0; i <= 20; i++) {
        if (nums.count(i) == 0) {
            values.push_back(i);
            nums.insert(i);
        }
        if (nums.count(i*2) == 0){
            nums.insert(i*2);
            values.push_back(i*2);
        }
        if (nums.count(i*3) == 0) {
            nums.insert(i*3);
            values.push_back(i*3);
        }
    }
    values.push_back(50);
    sort(values.begin(), values.end());
    //for(int i = 0; i < values.size(); ++i) printf("%d ", values[i], values.size());
    int n;
    while(scanf("%d", &n), n > 0) {
        ll perm, comb;
        perm = comb = 0;
        for (int i = 0; i < values.size(); ++i) {
            for (int j = i; j < values.size(); ++j) {
                int a = values[i];
                int b = values[j];
                int aux = values[i] + values[j] - n;
                if (aux > 0 || -aux < values[i] || -aux < values[j] || -aux > 60) continue;
                else int a = 2;
                if (binary_search(values.begin(), values.end(), -aux)) {
                    comb++;
                    int diff = 0;
                    diff += a != b;
                    diff += a != -aux;
                    diff += b != -aux;
                    if (diff == 3) perm += 6;
                    else if (diff == 2) perm += 3;
                    else perm++;
                }

            }
        }
        if (comb == 0)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        else{
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
        }
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}