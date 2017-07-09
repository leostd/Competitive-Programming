#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL long long
#define pb push_back
#define pii pair<LL,LL>
#define mp make_pair
using namespace std;
char game[100010];
int n;
string names[20];
int arrived[30];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) cin>>names[i];
	scanf("%s", game);
	int m = strlen(game);
	int maxlen = 1, curlen = 1;
	for(int i = 1; i < m; i++){
		if(game[i] == game[i-1]){
			curlen++;
			maxlen = max(maxlen, curlen);
		}else curlen = 1;
	}
	int wo = 0, wd = 2, bo = 1, bd = 3;
	queue<int> q;
	for(int i = 4; i < n; i++) q.push(i);
	int streak = 0, col;
	if(game[0] == 'W') col = 0;
	else col = 1;
	for(int i = 0; i < 4; i++) arrived[i] = i;
	int turn = 4;
	for(int i = 0; i < m; i++){
		if(game[i] == 'W'){
			swap(wo, wd);
			int aux = bd;
			bd = bo;
			q.push(aux);
			bo = q.front(); q.pop();
			arrived[bo] = turn++;
			if(col == 0) streak++;
			else{
				streak = 1;
				col = 1-col;
			}
		}else{
			swap(bo, bd);
			int aux = wd;
			wd = wo;
			q.push(aux);
			wo = q.front(); q.pop();
			arrived[wo] = turn++;
			if(col == 1) streak++;
			else{
				streak = 1;
				col = 1-col;
			}
		}
		if(streak == maxlen){
			if(col == 0){
				if(arrived[wo] < arrived[wd]) printf("%s %s\n", names[wo].c_str(), names[wd].c_str());
				else printf("%s %s\n", names[wd].c_str(), names[wo].c_str());
			}else{
				if(arrived[bo] < arrived[bd]) printf("%s %s\n", names[bo].c_str(), names[bd].c_str());
				else printf("%s %s\n", names[bd].c_str(), names[bo].c_str());
			}
		}
	}
	return 0;
}