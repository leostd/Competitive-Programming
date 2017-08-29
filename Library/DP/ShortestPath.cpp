/*
	Este algoritmo encuentra el camino de menor costo en una matriz nxm
	desde una posicion s, hasta una posicion e. Los movimientos
	permitidos en este caso son hacia abajo, hacia la derecha y
	diagonal derecha. Cada posicion tiene un costo asociado.

	La relacion de recurrencia es la siguiente:
		minCost(start_row, start_col) : grid[start_row][start_col]
		minCost(row, col) : INF  si  row < 0 || row >= n || col < 0 || col >= m
		minCost(row, col) : min( minCost(row-1, col), minCost(row, col-1), minCost(r-1, col-1)) + grid[row][col]

	Complejidad de tiempo de este algoritmo es O(n*m)
	Complejidad en memoria de este algoritmo es O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;

int sc, sr, er, ec;
int n = 2, m = 2;
int  memo[1000][1000];

int grid[3][3] = { {1, 2, 3}, {4, 8, 2}, {1, 5, 3}};

int minCost(int r, int c){
	if (r < 0 || r > n || c < 0 || c > m)
		return 0x3f3f3f3f;
	if (r == sr && c == sc)
		return grid[r][c];
	if (memo[r][c] != -1)
		return memo[r][c];
	int a = minCost(r-1,c);
	int b = minCost(r, c-1);
	int d = minCost(r-1, c-1);
	return memo[r][c] = min(a,min(b, d))+grid[r][c];
}


int main() {
	sc = sr = 0;
	er = ec = 2;
	memset(memo, -1, sizeof(memo));
	printf("%d\n",minCost(er, ec));
	return 0;
}