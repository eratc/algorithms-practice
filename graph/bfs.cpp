#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

constexpr int MAXN = 110;

struct node {
	int index, length;
	node(const int _index, const int _length) {
		index = _index;
		length = _length;
	}
};

void bfs(std::vector<int> map[], int start, int target) {
	std::queue<node> q;
	std::unordered_map<int, int> path;
	bool used[MAXN] = { false };
	auto ele = node(start, 0);

	used[start] = true;
	q.push(ele);
	while(!q.empty()) {
		ele = q.front();
		q.pop();
		if(ele.index == target) {
			std::cout << "Path to " << target << " is " << ele.length << " long.";
			return;
		}
		for(auto const &adj : map[ele.index]) {
			if(!used[adj]) {
				used[adj] = true;
				path.insert({adj, ele.index});
				q.push(node(adj, ele.length+1));
			}
		}
	}
}

int main() {
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

	bfs(ar, 0, 2);
	return 0;
}