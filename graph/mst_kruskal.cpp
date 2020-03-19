#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

constexpr int MAXN = 110;

struct Edge {
	int u, v, weight;
	Edge(const int _u, const int _v, const int _weight) : u(_u), v(_v), weight(_weight) { }
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};

void mst(std::vector<Edge> edges) {
	int n = edges.size();
	int cost = 0;
	std::vector<Edge> result;
	std::sort(edges.begin(), edges.end());
	int tree_id[n];

	for(int i = 0 ; i < n ; i++) {
		tree_id[i] = i;
	}

	for(auto const &edge : edges) {
		if(tree_id[edge.u] != tree_id[edge.v]) {
			int old_id = tree_id[edge.u];
			int new_id = tree_id[edge.v];
			for(int i = 0 ; i < n ; i++) {
				if(tree_id[i] == old_id) {
					tree_id[i] = new_id;
				}
			}
			result.push_back(edge);
			cost += edge.weight;
		}
	}

	std::cout << "Cost: " << cost << std::endl;
	for(auto const &edge : result) {
		std::cout << edge.u << ' ' << edge.v << std::endl;
	}
}

int main() {
	std::vector<Edge> edges;

	edges.push_back(Edge(5,4,9));
	edges.push_back(Edge(5,1,4));
	edges.push_back(Edge(1,4,1));
	edges.push_back(Edge(1,2,2));
	edges.push_back(Edge(4,2,3));
	edges.push_back(Edge(4,3,5));
	edges.push_back(Edge(3,2,3));
	edges.push_back(Edge(3,6,8));
	edges.push_back(Edge(2,6,7));

	mst(edges);
	return 0;
}