#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>

constexpr int MAXN = 110;

std::vector<int> map[MAXN];
std::stack<int> stack;
bool used[MAXN], on_stack[MAXN];
int ids[MAXN], low_links[MAXN];
int color;

void dfs(int at) {
	used[at] = true;
	ids[at] = low_links[at] = color;
	color++;
	stack.push(at);
	on_stack[at] = true;

	for(auto const &adj : map[at]) {
		if(!used[adj]) {
			dfs(adj);
		}
		if(on_stack[adj]) {
			low_links[at] = std::min(low_links[adj], low_links[at]);
		}
	}

	if(ids[at] == low_links[at]) {
		std::cout << "SCC:" << std::endl;
		for(int node = stack.top() ; node != at ; stack.pop(), node = stack.top()) {
			on_stack[node] = false;
			std::cout << node << std::endl;
		}
		stack.pop();
		std::cout << at << std::endl << std::endl;
	}
}

void scc(int n) {
	for(int i = 0 ; i < n ; i++) {
		if(!used[i]) {
			dfs(i);
		}
	}
}

int main() {
	map[0].push_back(1);
	map[1].push_back(2);
	map[2].push_back(3);
	map[3].push_back(0);

	map[2].push_back(4);

	map[4].push_back(5);
	map[5].push_back(6);
	map[6].push_back(4);

	map[7].push_back(6);
	map[7].push_back(8);
	scc(9);
	return 0;
}