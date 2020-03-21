#include<cstdio>
#include<iostream>
#include<vector>

constexpr int MAXN = 110;

int n;
bool used[MAXN][MAXN];
std::vector<int> adj[MAXN];
std::vector<int> result;

void eulerian_path(int v) {
	for(const auto &to : adj[v]) {
		if(!used[v][to]) {
			used[v][to] = used[to][v] = true;
			eulerian_path(to);
		}
	}
	result.push_back(v);
}

int main() {
	n = 9;
	adj[1].push_back(2);
	adj[1].push_back(8);

	adj[2].push_back(1);
	adj[2].push_back(3);

	adj[3].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(4);
	adj[3].push_back(7);

	adj[4].push_back(3);
	adj[4].push_back(5);
	adj[4].push_back(7);
	adj[4].push_back(9);

	adj[5].push_back(4);
	adj[5].push_back(9);

	adj[6].push_back(7);
	adj[6].push_back(9);

	adj[7].push_back(1);
	adj[7].push_back(3);
	adj[7].push_back(4);
	adj[7].push_back(6);
	adj[7].push_back(8);
	adj[7].push_back(9);

	adj[8].push_back(1);
	adj[8].push_back(7);

	adj[9].push_back(4);
	adj[9].push_back(5);
	adj[9].push_back(6);
	adj[9].push_back(7);

	eulerian_path(1);
	for(const auto &node : result) {
		std::cout << node << std::endl;
	}
	return 0;
}