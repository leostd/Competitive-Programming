#include <bits/stdc++.h>
using namespace std;

int r, c, counter;
int m[102][102];

void process(int row, int col){
	// left
	if (col == 1) counter++;
	else {
		bool flag = true;
		for (int cl = col-1; cl >= 1; --cl){
			if (m[row][cl] >= m[row][col]){
				flag = false;
				break;
			}
		}
		if (flag) counter++;
	}
	// right
	if (col == c) counter++;
	else{
		bool flag = true;
		for(int cl = col+1; cl <= c; ++cl){
			if (m[row][cl] >= m[row][col]){
				flag = false;
				break;
			}
		}
		counter += flag;
	}

	// up
	if (row == 1) counter++;
	else{
		bool flag = true;
		for (int rw = row-1; rw >= 1; --rw){
			if (m[rw][col] >= m[row][col]){
				flag = false;
				break;
			}
		}
		counter += flag;
	}

	// down
	if (row == r) counter++;
	else{
		bool flag = true;
		for (int rw = row+1; rw <= r; ++rw){
			if (m[rw][col] >= m[row][col]){
				flag = false;
				break;
			}
		}
		counter += flag;
	}
}

int main(){
	scanf("%d %d",&r, &c);
	for (int row = 1; row  <= r; ++row)
		for (int col = 1; col <= c; ++col)
			scanf("%d", &m[row][col]);
	counter = 0;
	for(int row = 1; row <= r; ++row){
		for(int col = 1; col <= c; ++col){
			process(row, col);
		}
	}
	printf("%d\n", counter);
	return 0;
}