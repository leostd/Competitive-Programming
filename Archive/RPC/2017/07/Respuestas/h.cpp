#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL long long
#define pb push_back
#define pii pair<LL,LL>
#define mp make_pair
using namespace std;
char A[1010][1010];
int n, m;
bool NOT[1010][1010];
int movx[] = {1,-1,0,0};
int movy[] = {0,0,1,-1};
bool v[1010][1010];
bool isInter(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + movx[i],
			ny = y + movy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) return false;
		if(A[nx][ny] == '.') return false;
	}
	return true;
}
void bfs(int x, int y){
	if(v[x][y]) return;
	v[x][y] = true;
	queue<int> q;
	q.push(x); q.push(y);
	while(!q.empty()){
		x = q.front(); q.pop();
		y = q.front(); q.pop();
		NOT[x][y] = true;
		for(int i = 0; i < 4; i++){
			int nx = x + movx[i],
				ny = y + movy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(v[nx][ny]) continue;
			if(A[nx][ny] != '.') continue;
			v[nx][ny] = true;
			q.push(nx); q.push(ny);
		}
	}
}
char AA[1010][1010], BB[1010][1010];
void dfs(int x, int y, int in, int mode, int dir, int m2){
	char& c = ((mode == 0) ? (AA[x][y]) :(BB[x][y]));
	v[x][y] = true;
	if(isInter(x,y)) in++;
	if(m2 == 0) c = (/*(in&1) ? ('I'):*/((mode == 0)?('A'):('B')));
	else c = ((in&1) ? ('I'):((mode == 0)?('A'):('B')));
	int l, r;
	if(isInter(x, y)) l = dir, r = dir;
	else l = 0, r = 3;
	for(int i = l; i <= r; i++){
		int nx = x + movx[i],
			ny = y + movy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(A[nx][ny] == '.') continue;
		if(v[nx][ny]) continue;
		dfs(nx, ny, in, mode, i, m2);
	}
}
void f2(char x, int N){
	memset(v, false, sizeof(v));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(NOT[i][j]){
				for(int k = 0; k < 4; k++){
					int nx = i + movx[k],
						ny = j + movy[k];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(v[nx][ny]) continue;
					if(AA[nx][ny] == x) dfs(nx, ny, 0, N, -1, 1);
				}
			}
		}
	}
}
int d(int x, int y){
	v[x][y] = true;
	int ans = AA[x][y]=='.';
	for(int i = 0; i < 4; i++){
		int nx = x + movx[i],
			ny = y + movy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(v[nx][ny]) continue;
		if(NOT[nx][ny]) continue;
		if(AA[nx][ny] != '.') continue;
		ans += d(nx,ny);
	}
	return ans;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%s", A[i]);
	int in = 0;
	for(int i = 0; i < n; i++){
		if(A[i][0] == '.') bfs(i,0);
		if(A[i][m-1]=='.') bfs(i,m-1);
	}
	for(int i = 0; i < m; i++){
		if(A[0][i]=='.') bfs(0,i);
		if(A[n-1][i]=='.') bfs(n-1,i);
	}
	int totalpoints = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			totalpoints += (A[i][j] == '.' && !NOT[i][j]);
		}
	}
	int ax,bx,ay,by;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			AA[i][j] = BB[i][j] = A[i][j];
			if(A[i][j] == 'A'){
				ax = i; ay = j;
			}
			if(A[i][j]=='B'){
				bx = i; by = j;
			}
		}
	}
	memset(v, false, sizeof(v));
	dfs(ax, ay, 0, 0, -1, 0);
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c", AA[i][j]);
		}
		printf("\n");
	}
	*/
	memset(v, false, sizeof(v));
	dfs(bx, by, 0, 1, -1, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(BB[i][j] != 'X' && BB[i][j] != '.') AA[i][j] = BB[i][j];
		}
	}
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c", BB[i][j]);
		}
		printf("\n");
	}
	*/
	f2('A',0);
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c", AA[i][j]);
		}
		printf("\n");
	}
	*/
	f2('B',1);
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c", BB[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(AA[i][j]=='I') continue;
			if(BB[i][j] != 'X' && BB[i][j] != '.') AA[i][j] = BB[i][j];
		}
	}
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c", AA[i][j]);
		}
		printf("\n");
	}
	*/
	memset(v, false, sizeof(v));
	int vA = 0, vB = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(AA[i][j] == 'A') vA += d(i,j);
		}
	}
	memset(v, false, sizeof(v));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(AA[i][j] == 'B') vB += d(i,j);
		}
	}
	printf("%d %d %d\n", vA, vB, totalpoints - vA - vB);
	return 0;
}