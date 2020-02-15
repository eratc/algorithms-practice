#include<cstdio>
#include<iostream>
#include<queue>

constexpr int MAXN = 110;

struct Node {
	int index, length;
	Node(const int _index, const int _length) : index(_index), length(_length) { }
};

void sp(std::vector<Node> map[], int start, int target, int n) {
	bool unchanged;
	int dist[MAXN];
	int via[MAXN] = { 0 };

	for(int i = 0 ; i < MAXN ; i++) {
		dist[i] = INT_MAX;
	}

	dist[start] = 0;
	for(int i = 1 ; i < n ; i++) {
		unchanged = true;
		for(int j = 1 ; j <= n ; j++) {
			for(auto const &adj : map[j]) {
				int new_dist = dist[j] + adj.length;
				if(dist[j] != INT_MAX && new_dist < dist[adj.index]) {
					via[adj.index] = j;
					dist[adj.index] = new_dist;
					unchanged = false;
				}
			}
		}
		if(unchanged == true) {
			break;
		}
	}

	for(int i = 1 ; i <= n ; i++) {
		for(auto const &adj : map[i]) {
			if(dist[i] != INT_MAX && dist[i] + adj.length < dist[adj.index]) {
				std::cout << "Negative cycle detected!" << std::endl;
				return;
			}
		}
	}

	int parent = target;
	std::cout << "Shortest path is " << dist[target] << " long.\n";
	while(parent > 0) {
		std::cout << parent << std::endl;
		parent = via[parent];
	}
	return;
}

int main() {
	std::vector<Node> negative_path[7];

	negative_path[1].push_back(Node(2,4));
	negative_path[1].push_back(Node(3,2));

	negative_path[2].push_back(Node(3,5));
	negative_path[2].push_back(Node(4,-10));

	negative_path[3].push_back(Node(5,3));

	negative_path[4].push_back(Node(6,11));

	negative_path[5].push_back(Node(4,4));

	std::vector<Node> negative_cycle[6];

	negative_cycle[1].push_back(Node(2,4));
	negative_cycle[1].push_back(Node(3,2));

	negative_cycle[3].push_back(Node(2,5));
	negative_cycle[2].push_back(Node(4,-10));

	negative_cycle[5].push_back(Node(3,-3));

	negative_cycle[4].push_back(Node(6,11));

	negative_cycle[4].push_back(Node(5,4));

	std::cout << "Graph without negative cycles: " << std::endl;
	sp(negative_path, 1, 6, 6);
	std::cout << "Graph with negative cycles: " << std::endl;
	sp(negative_cycle, 1, 6, 6);
	return 0;
}