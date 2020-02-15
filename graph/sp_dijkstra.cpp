#include<cstdio>
#include<iostream>
#include<queue>
#include<limits>

constexpr int MAXN = 110;
constexpr int INTMAX = std::numeric_limits<int>::max();

struct Node {
	int index, length;
	Node(const int _index, const int _length) : index(_index), length(_length) { }
};

void sp(std::vector<Node> map[], int start, int target) {
	auto compare = [](Node a, Node b) { return a.length > b.length; };
	std::priority_queue<Node, std::vector<Node>, decltype(compare)> pq(compare);
	bool used[MAXN] = { false };
	int dist[MAXN] = { 0 };
	int via[MAXN] = { 0 };

	pq.push(Node(start, 0));
	dist[start] = 0;
	while(!pq.empty()) {
		Node ele = pq.top();
		pq.pop();
		used[ele.index] = true;

		if(ele.index == target) {
			break;
		}

		for(auto const &adj : map[ele.index]) {
			int new_dist = dist[ele.index] + adj.length;
			if(!used[adj.index] && (dist[adj.index] == 0 || new_dist < dist[adj.index])) {
				dist[adj.index] = new_dist;
				pq.push(Node(adj.index, new_dist));
				via[adj.index] = ele.index;
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
	std::vector<Node> ar[6];

	ar[1].push_back(Node(2,4));
	ar[1].push_back(Node(3,2));

	ar[2].push_back(Node(3,5));
	ar[2].push_back(Node(4,10));

	ar[3].push_back(Node(5,3));

	ar[4].push_back(Node(6,11));

	ar[5].push_back(Node(4,4));

	sp(ar, 1, 6);
	return 0;
}