#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

constexpr int MAXN = 110;

std::vector<int> ar[MAXN];
std::vector<int> result;
bool used[MAXN];

void dfs(int node) {
	used[node] = true;
	for(auto const &adj : ar[node]) {
		if(!used[adj]) {
			dfs(adj);
		}
	}
	result.push_back(node);
}

void topsort(int n) {
	for(int i = 0 ; i < n ; i++) {
		if(!used[i]) {
			dfs(i);
		}
	}
	std::reverse(result.begin(), result.end());

	for(auto const &ele : result) {
		std::cout << ele << std::endl;
	}
}

int main() {
	ar[0].push_back(1);
	ar[0].push_back(2);

	ar[1].push_back(5);
	ar[1].push_back(2);

	ar[2].push_back(3);

	ar[5].push_back(3);
	ar[5].push_back(4);

	ar[6].push_back(1);
	ar[6].push_back(5);

	topsort(7);
	return 0;
}