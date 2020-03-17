#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<utility>

constexpr int MAXN = 110;

int bfs(std::vector<int> adj[], int capacity[][MAXN], int path[], int start, int end) {
	std::queue<std::pair<int, int>> q;
	bool used[MAXN] = { false };
	int ele = start;
	int flow = INT_MAX;

	used[ele] = true;
	q.push({ele, flow});
	while(!q.empty()) {
		ele = q.front().first;
		flow = q.front().second;
		q.pop();
		if(ele == end) {
			return flow;
		}
		for(auto const &to : adj[ele]) {
			if(!used[to] && capacity[ele][to]) {
				used[to] = true;
				path[to] = ele;
				q.push({to, std::min(capacity[ele][to], flow)});
			}
		}
	}

	return 0;
}

int max_flow(std::vector<int> adj[], int capacity[][MAXN], int source, int sink) {
	int total_flow = 0;
	int new_flow;
	int path[MAXN];
	while(new_flow = bfs(adj, capacity, path, source, sink)) {
		total_flow += new_flow;
		for(int t = sink ; t != source ; t = path[t]) {
			int v = path[t];
			capacity[v][t] -= new_flow;
			capacity[t][v] += new_flow;
		}
	}
	std::cout << total_flow << std::endl;
	return total_flow;
}

int main() {
	std::vector<int> ar[6];
	int capacity[MAXN][MAXN] = { 0 };

	ar[0].push_back(1);
	capacity[0][1] = 7;
	ar[0].push_back(4);
	capacity[0][4] = 4;

	ar[1].push_back(0);
	ar[1].push_back(2);
	capacity[1][2] = 5;
	ar[1].push_back(3);
	capacity[1][3] = 3;
	ar[1].push_back(4);

	ar[2].push_back(1);
	ar[2].push_back(3);
	ar[2].push_back(5);
	capacity[2][5] = 8;

	ar[3].push_back(1);
	ar[3].push_back(2);
	capacity[3][2] = 3;
	ar[3].push_back(4);
	ar[3].push_back(5);
	capacity[3][5] = 5;

	ar[4].push_back(0);
	ar[4].push_back(1);
	capacity[4][1] = 3;
	ar[4].push_back(3);
	capacity[4][3] = 2;

	ar[5].push_back(2);
	ar[5].push_back(3);

	max_flow(ar, capacity, 0, 5);
	return 0;
}