#include <bits/stdc++.h>
using namespace std;

int n;
int m[52][52];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	bool flag;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a = m[i][j];
			if (a == 1) continue;
			flag = false;
			for (int k = 1; k <= n; k++) {
				if (m[k][j] >= a) continue;
				for (int l = 1; l <= n; l++) {
					if (m[i][l] >= a) continue;
					if (a == m[i][l] + m[k][j]){
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if(!flag) break;
		}
		if (!flag) break;
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}