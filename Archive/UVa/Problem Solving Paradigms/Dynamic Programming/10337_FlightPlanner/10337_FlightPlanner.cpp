#include <bits/stdc++.h>
using namespace std;

int m[10][1002], memo[10][1002];
int start_row = 0, start_col = 0;
int end_row = 0, end_col;

int dp(int row, int col){
	if (row == end_row && col == end_col+1)
		return 0;
	if (col < 0 || col > end_col || row < 0 || row > 9)
		return 0x3f3f3f3f;
	if (memo[row][col] != -1)
		return memo[row][col];
	int a = dp(row+1, col+1) + 60;
	int b = dp(row, col+1) + 30;
	int c = dp(row-1, col+1) + 20;
	memo[row][col] = min(a,min(b, c))-m[row][col];
	return memo[row][col];
}

void printMatrix(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j <= end_col; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int miles;
		int columns;
		scanf("%d", &miles);
		columns = miles/100;
		end_col = columns - 1;
		memset(memo, -1, sizeof(memo));
		for (int row = 9; row >= 0; row--)
			for (int col = 0; col < columns; col++)
				scanf("%d", &m[row][col]);
		//printMatrix();
		int ans = dp(0, 0);
		printf("%d\n\n", ans);

	}
	return 0;
}