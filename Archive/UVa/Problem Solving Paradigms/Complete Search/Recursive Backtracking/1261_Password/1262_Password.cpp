#include <bits/stdc++.h>
using namespace std;


int k,c;
set<char> col_set[5];
string pass[8000];
void solve(int n, string a){
	if (n == 5)
		pass[c++] = a;
	else{
		for (auto it= col_set[n].begin(); it != col_set[n].end(); ++it){
			solve(n+1, a + *it);
		}
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &k);
		c = 0;
		string row1[6], row2[6], col1[5], col2[5], aux;
		for(int i = 0; i < 5; i++)
			col_set[i].clear();
		for(int i = 0; i < 6; i++)
			cin >> row1[i];
		for(int i = 0; i < 6; i++)
			cin >> row2[i];
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++){
				col1[j].push_back(row1[i][j]);
				col2[j].push_back(row2[i][j]);
			}
		}
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 6; j++){
				for (int k = 0; k < 6; k++){
					if (col1[i][j] == col2[i][k])
						col_set[i].insert(col1[i][j]);
				}
			}
		}
		aux = "";
		solve(0, aux);
		if (k <= c)
			cout << pass[k-1]<<"\n";
		else
			cout << "NO" << "\n";

	}
	return 0;
}