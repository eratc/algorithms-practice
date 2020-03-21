#include<cstdio>
#include<iostream>
#include<vector>

constexpr int MAXN = 110;

std::vector<int> adj[MAXN];
bool used[MAXN];
int low[MAXN], id[MAXN];
int timer;

void dfs(int v, int parent) {
	int children = 0;
	used[v] = true;
	low[v] = id[v] = ++timer;
	for(auto const &to : adj[v]) {
		if(to == parent) {
			continue;
		}
		if(!used[to]) {
			children++;
			dfs(to, v);
			if(low[to] >= id[v] && parent != -1) {
				std::cout << v << " is a cut vertex." << std::endl;
			}
			low[v] = std::min(low[v], low[to]);
		}
		else {
			low[v] = std::min(low[v], id[to]);
		}
	}

	if(parent == -1 && children > 1) {
		std::cout << v << " is a cut vertex." << std::endl;
	}
}

void articul(int n) {
	for(int i = 0 ; i < n ; i++) {
		if(!used[i]) {
			dfs(i, -1);
		}
	}
}

int main() {
	adj[0].push_back(13);

	adj[1].push_back(2);
	adj[1].push_back(3);

	adj[2].push_back(1);
	adj[2].push_back(4);

	adj[3].push_back(1);
	adj[3].push_back(4);

	adj[4].push_back(2);
	adj[4].push_back(3);
	adj[4].push_back(5);

	adj[5].push_back(4);
	adj[5].push_back(6);

	adj[6].push_back(5);
	adj[6].push_back(7);

	adj[7].push_back(6);
	adj[7].push_back(8);
	adj[7].push_back(9);
	adj[7].push_back(13);

	adj[8].push_back(7);

	adj[9].push_back(7);
	adj[9].push_back(10);

	adj[10].push_back(9);
	adj[10].push_back(11);

	adj[11].push_back(9);
	adj[11].push_back(10);
	adj[11].push_back(12);

	adj[12].push_back(11);
	adj[12].push_back(13);

	adj[13].push_back(0);
	adj[13].push_back(7);
	adj[13].push_back(12);

	articul(14);
	return 0;
}