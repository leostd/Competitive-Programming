#include <bits/stdc++.h>
using namespace std;

struct card {
	int val;
	char suit;
};

card cs[50];

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int n;
		scanf("%d", &n);
		card prev, cur;
		bool flag = true;
		scanf("%d %c", &prev.val, &prev.suit);
		for (int i = 1; i < n; ++i){
			scanf("%d %c", &cur.val, &cur.suit);
			if (flag && (cur.suit == prev.suit || cur.val == prev.val))
				flag = false;
			prev = cur;
		}
		if (flag)
			printf("B\n");
		else
			printf("M\n");

	}
	return 0;
}