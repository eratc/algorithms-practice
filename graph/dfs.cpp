#include<cstdio>
#include<iostream>
#include<vector>

constexpr int MAXN = 110;

int dfs(std::vector<int> map[], bool used[], int current, int target) {
	used[current] = true;
	if(current == target) {
		std::cout << current << '\n';
		return current;
	}
	for(auto const &adj : map[current]) {
		if(!used[adj]){
			int result = dfs(map, used, adj, target);
			if(result > -1) {
				std::cout << current << '\n';
				return current;
			}
		}
	}
	return -1;
}

int main() {
	bool used[MAXN] = { false };
	std::vector<int> ar[5];
	ar[0].push_back(1);
	ar[1].push_back(0);

	ar[0].push_back(4);
	ar[4].push_back(0);

	ar[1].push_back(2);
	ar[2].push_back(1);

	ar[1].push_back(3);
	ar[3].push_back(1);

	ar[1].push_back(4);
	ar[4].push_back(1);

	ar[2].push_back(3);
	ar[3].push_back(2);

	ar[3].push_back(4);
	ar[4].push_back(3);

	dfs(ar, used, 0, 2);
	return 0;
}