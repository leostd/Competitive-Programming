#include <bits/stdc++.h>
#define MAXN 20
#define MAXM 10
using namespace  std;

typedef vector<int> vi;

map<int, int> intersections;
vi customers,real_customers;
int n, b, m, common, a, towers[21], max_customers;

void init(){
	intersections.clear();
	memset(towers, 0, sizeof(towers));
	max_customers = -0x3f3f3f3f;
}


void check_intersections(int &total, int mask){
	for (auto it=intersections.begin(); it != intersections.end(); ++it){
		int intersect = (*it).first & mask;
		int counter = 0;
		for (int i = 1; i <= n; i++){
			if (intersect & (1 << i))
				counter++;
		}
		if (counter <= 1)
			continue;
		total -= (counter-1) * (*it).second;
	}
}


int main(){
	int case_number = 1;
	while(scanf("%d %d", &n, &b), n || b){
		init();
		for (int i=1; i <= n; i++)
			scanf("%d", &towers[i]);
		scanf("%d", &m);
		for (int i=0; i < m; i++){
			scanf("%d", &common);
			int bitmask = 0;
			for (int j = 0; j < common; j++){
				scanf("%d", &a);
				bitmask |= (1 << a);
			}
			scanf("%d", &a);
			intersections[bitmask] += a;
		}
		for (int mask = 1; mask < (1 << (n+1)); mask++){
			int total_customers=0;
			customers.clear();
			
			for (int i=1; i <= n; i++){
				if (mask & (1 << i)){
					total_customers += towers[i];
					customers.push_back(i);
				}
			}
			if (customers.size() != b)
				continue;
			check_intersections(total_customers, mask);
			if (total_customers > max_customers){
				max_customers = total_customers;
				real_customers = vi(customers);
			}
			else if (total_customers == max_customers){
				int i =  0;
				while(customers[i] == real_customers[i])
					i++;
				if (customers[i] < real_customers[i])
					real_customers = vi(customers);
			}
		}
		printf("Case Number  %d\n", case_number++);
		printf("Number of Customers: %d\n", max_customers);
		printf("Locations recommended: ");
		for(int i=0;i<real_customers.size();i++){
			if (i < real_customers.size()-1)
				printf("%d ", real_customers[i]);
			else
				printf("%d", real_customers[i]);
		}
		printf("\n\n");
	}
	return 0;
}