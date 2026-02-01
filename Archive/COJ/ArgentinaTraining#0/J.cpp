#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
struct city{
	int soldiers, zombies, move_cost, total_cost;
	bool operator <(const city &other) {
		return total_cost < other.total_cost;
	}
};

int p, n, c = 0;
city cities[100005];
vector<city> vc;
int main() {
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d", &cities[i].zombies, &cities[i].soldiers, &cities[i].move_cost);
		if (cities[i].zombies > cities[i].soldiers*10)
		{
			int z = cities[i].zombies;
			int s = cities[i].soldiers;
			int r = z - s * 10;
			int t = ceil((double)r/10);
			cities[i].total_cost = t*cities[i].move_cost;
			vc.push_back(cities[i]);
		}else{
			c++;
		}
		sort(vc.begin(), vc.end());
		for (int i = 0; i < vc.size(); i++){
			if (vc[i].total_cost < p){
				p -= vc[i].total_cost;
				c++;
			}
			else
				break;
		}
	}
	printf("%d\n", c);
	return 0;
}