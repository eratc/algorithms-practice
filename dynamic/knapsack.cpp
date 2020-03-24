#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>

constexpr int MAXN = 110;

std::vector<std::pair<int, int>> items;
int n = 5;
int dn[MAXN][MAXN];

void knapsack(int max_weight) {
	for(int i = 1 ; i <= n ; i++) {
		for(int w = 0 ; w <= max_weight ; w++) {
			if(items[i].first > w) {
				dn[i][w] = dn[i-1][w];
			}
			else {
				dn[i][w] = std::max(items[i].second + dn[i-1][w-items[i].first], dn[i-1][w]);
			}
		}
	}

	int i = n, j = max_weight;
	std::cout << "Total value: " << dn[i][j] << std::endl;
	std::cout << "Items chosen: ";
	while(dn[i][j] != 0) {
		if(dn[i-1][j] != dn[i][j]) {
			std::cout << i << ' ';
			j -= items[i].first;
		}
		i--;
	}
}

int main() {
	items.push_back({0,0});
	items.push_back({1,1});
	items.push_back({2,6});
	items.push_back({5,18});
	items.push_back({6,22});
	items.push_back({7,28});
	knapsack(11);
	return 0;
}