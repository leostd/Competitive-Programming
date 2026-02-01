#include <bits/stdc++.h>
using namespace std;

int ac[13], s, d, ans;

bool check(int month){
	int sum = 0;
	for(int i=month; i >= month-4; i--)
		sum += ac[i];
	return sum < 0;
}


void bt(int month, int acum){
	if (month == 12 && check(month-1)){
		if (acum > ans) 
			ans = acum;
	}
	else if(month >= 5 && !check(month-1))
		return;
	else
	{
		ac[month] = s;
		bt(month+1, acum+s);
		ac[month] = -d;
		bt(month+1, acum-d);
	} 
}

int main(){
	while(scanf("%d %d", &s, &d) != EOF){
		ans = -0x3f3f3f3f;
		bt(0,0);
		if (ans < 0)
			printf("Deficit\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}