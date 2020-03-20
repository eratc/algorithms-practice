#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>

constexpr int MAXN = 110;

int map[MAXN][MAXN];

struct Edge {
	int to = -1, weight = INT_MAX;
};

void mst(int n) {
	int cost = 0;
	std::vector<std::pair<int, int>> result;
	std::vector<Edge> min_edges(n);
	bool selected[MAXN] = { false };
	min_edges[1].weight = 0;
	selected[1] = true;

	int new_node = 1;
	for(int i = 0 ; i < n-1 ; i++) {
		// recalculate min edges
		for(int j = 1 ; j <= n ; j++) {
			if(!selected[j] && map[j][new_node] && map[j][new_node] < min_edges[j].weight) {
				min_edges[j].weight = map[j][new_node];
				min_edges[j].to = new_node;
			}
		}

		Edge new_edge;
		for(int j = 1 ; j <= n ; j++) {
			if(!selected[j] && min_edges[j].weight && min_edges[j].weight < new_edge.weight) {
				new_edge.to = min_edges[j].to;
				new_edge.weight = min_edges[j].weight;
				new_node = j;
			}
		}

		if(new_edge.to == -1) {
			std::cout << "NO MST" << std::endl;
			return;
		}

		selected[new_node] = true;
		cost += new_edge.weight;
		result.push_back({new_node, new_edge.to});
	}

	std::cout << "Cost: " << cost << std::endl;
	for(const auto &edge : result) {
		std::cout << edge.first << ' ' << edge.second << std::endl;
	}
}

int main() {
	map[5][4] = map[4][5] = 9;
	map[5][1] = map[1][5] = 4;
	map[1][4] = map[4][1] = 1;
	map[1][2] = map[2][1] = 2;
	map[4][2] = map[2][4] = 3;
	map[4][3] = map[3][4] = 5;
	map[3][2] = map[2][3] = 3;
	map[3][6] = map[6][3] = 8;
	map[2][6] = map[6][2] = 7;
	mst(6);
	return 0;
}