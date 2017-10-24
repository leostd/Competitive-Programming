#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = 21, M = 21;
int n, m, x, y, mp[M][N], visited[M][N];
char c;
vii possible, zero_v, one_v;
int cur, mx;
int mvx[] = {0, 0, 1, -1};
int mvy[] = {1, -1, 0, 0};
int lnd, wtr;

bool valid(int row, int col){
	if (row < 0 || row >= m || mp[row][col] == wtr)
		return false;
	return true;
}

void bfs(int row, int col){
	int a,b;
	cur = 1;
	queue<ii> q;
	q.push(ii(row, col));
	visited[row][col] = 1;
	while(!q.empty()){
		ii f  = q.front();
		q.pop();
		a = f.first;
		b = f.second;
		int x, y;
		for(int i = 0; i < 4; i++){
			x = a + mvx[i];
			y = b + mvy[i];
			if (y == n)
				y = 0;
			else if(y == -1)
				y = n-1;
			if (valid(x, y) && visited[x][y] == -1){
				cur++;
				q.push(ii(x, y));
				visited[x][y] = 1;
			}
		}
	}
}

int main(){
	while(scanf("%d %d\n", &m, &n) != EOF){
		char ch0, ch1=(char) 0;
		one_v.clear();
		zero_v.clear();
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				c = getchar();
				if (i == 0 && j == 0)
					ch0 = c;
				if (c != ch0 && ch1 == '\0')
					ch1 = c;
				if (c == ch1){
					mp[i][j] = 1;
					one_v.push_back(ii(i,j));
				}
				else{
					mp[i][j] = 0;
					zero_v.push_back(ii(i,j));
				}
			}
			getchar();
		}
		scanf("%d %d\n", &x, &y);
		if (mp[x][y] == 1){
			lnd = 1;
			wtr = 0;
			possible = vii(one_v);
		}
		else{
			lnd = 0;
			wtr = 1;
			possible = vii(zero_v);
		}
		memset(visited, -1, sizeof(visited));
		bfs(x, y);
		mx = 0;
		for (int i = 0; i < possible.size(); i++){
			ii aux = possible[i];
			if (visited[aux.first][aux.second] == -1){
				cur = 0;
				bfs(aux.first, aux.second);
				mx = max(cur, mx);
			}
		}
		printf("%d\n", mx);
	}
	return 0;
}