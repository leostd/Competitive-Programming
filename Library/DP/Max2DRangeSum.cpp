/*
	Este algoritmo encuentra la submatriz que contiene la maxima suma.
	La idea a grandes rasgos, es conseguir la suma de las filas 
	de cada combinacion de columnas L y R con L < R y  L,R < COL.
	En cada iteracion, se aplica el algoritmo de Kadane para encontrar
	los limites que contienen la maxima suma y la maxima suma.

	Complejidad en tiempo: O(COL^2 * ROW)
	Complejidad en memoria: O(ROW)
*/

#include <bits/stdc++.h>
#define COL 5
#define ROW 4
using namespace std;

int matrix[ROW][COL] = {{1, 2, -1, -4, -20},{-8, -3, 4, 2, 1},{3, 8, 10, 1, 3},{-4, -1, 1, 7, -6}};

int kadane(int *arr, int *start, int *finish, int n){
	*finish = -1;
	int sum = 0, maxSum = -0x3f3f3f3f;
	int local_start = 0;
	for (int i = 0; i < n; i++){
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i+1;
		}
		else if (sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}
	return maxSum;
}

void findMaxSum(){
	int maxSum = -0x3f3f3f3f, final_left;
	int final_right, final_bottom, final_top;
	int left, right;
	int temp[ROW], sum, start, finish;
	for (left = 0; left < COL; left++){
		memset(temp, 0, sizeof(temp));
		for (right = left; right < COL; right++){
			for (int i = 0; i < ROW; i++){
				temp[i] += matrix[i][right];
			}
			sum = kadane(temp, &start, &finish, ROW);
			if (sum > maxSum){
				maxSum = sum;
				final_left = left;
				final_right = right;
				final_top = start;
				final_bottom = finish;
			}
		}
	}
	printf("(Top, Left) (%d, %d)\n", final_top, final_left);
	printf("(Bottom, Right) (%d, %d)\n", final_bottom, final_right);
	printf("Max sum is: %d\n", maxSum);
}

int main(){
	findMaxSum();
	return 0;
}