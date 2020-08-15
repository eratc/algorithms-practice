#include<cstdio>
#include<iostream>
#include<vector>

int N;
std::vector<int> adj[6];
bool used[6];

int timer;
int tin[6], low[6];

void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = low[v] = timer++;

	for(auto const &adj : adj[v]) {
		if(adj == p) {
			continue;
		}
		else if(used[adj]) {
			low[v] = std::min(low[v], tin[adj]);
		}
		else {
			dfs(adj, v);
			low[v] = std::min(low[v], low[adj]);
			if(low[adj] > tin[v]) {
				std::cout << v << " - " << adj << " edge is a bridge." << std::endl;
			}
		}
	}
}

void find_bridges() {
	for(int i = 1 ; i < N ; i++) {
		if(!used[i]) {
			dfs(i);
		}
	}
}

int main() {
	N = 6;
	adj[0].push_back(1);
	adj[0].push_back(2);

	adj[1].push_back(0);
	adj[1].push_back(2);

	adj[2].push_back(0);
	adj[2].push_back(1);
	adj[2].push_back(4);

	adj[3].push_back(4);

	adj[4].push_back(2);
	adj[4].push_back(3);
	adj[4].push_back(5);

	adj[5].push_back(4);

	find_bridges();
	return 0;
}