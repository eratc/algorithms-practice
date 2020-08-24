#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>

constexpr int MAXN = 10;

std::vector<int> tree[MAXN];
std::vector<std::pair<int, int>> queries{std::pair<int, int>(3, 6), // 0
										 std::pair<int, int>(3, 5), // 0
										 std::pair<int, int>(5, 6), // 2
										 std::pair<int, int>(1, 4), // 0
										 std::pair<int, int>(5, 6), // 2
										 std::pair<int, int>(4, 5), // 2
										 std::pair<int, int>(2, 4)};// 2


std::vector<int> euler_tour, depths;
int indexes[MAXN];

std::vector<std::vector<std::pair<int, int>>> sparseTable;

int log_floor(double val) {
	return std::floor(std::log2(val));
}

void construct_sparse_table() {
	int N = depths.size();
	int M = log_floor(N)+1;
	sparseTable.assign(M, std::vector<std::pair<int, int>>(N));

	for(int i = 0 ; i < N ; i++) {
		sparseTable[0][i].first = depths[i];
		sparseTable[0][i].second = i;
	}

	for(int i = 1 ; i < M ; i++) {
		int offset = (1<<(i-1));
		for(int j = 0 ; j < N - (1<<i) + 1 ; j++) {
			if(sparseTable[i-1][j].first < sparseTable[i-1][j + offset].first) {
				sparseTable[i][j] = sparseTable[i-1][j];
			}
			else {
				sparseTable[i][j] = sparseTable[i-1][j + offset];
			}
			
		}
	}
}

int rmq(std::pair<int, int> query) {
	int a = std::min(indexes[query.first], indexes[query.second]);
	int b = std::max(indexes[query.first], indexes[query.second]);
	int k = log_floor(b - a + 1);
	if(sparseTable[k][a].first < sparseTable[k][b - (1<<k) + 1].first) {
		return euler_tour[sparseTable[k][a].second];
	}
	else {
		return euler_tour[sparseTable[k][b - (1<<k) + 1].second];
	}
}

void dfs(int node, int depth = 0) {
	euler_tour.push_back(node);
	depths.push_back(depth);
	indexes[node] = euler_tour.size()-1;
	for(auto const &child : tree[node]) {
		dfs(child, depth + 1);
		euler_tour.push_back(node);
		depths.push_back(depth);
		indexes[node] = euler_tour.size()-1;
	}
}

void LCA() {
	// Euler Tour on the tree
	dfs(0);
	// Construct a sparse table based on depths of euler tour nodes
	construct_sparse_table();

	// Answer LCA queries
	for(auto const &query : queries) {
		std::cout << "LCA of " << query.first << " and " << query.second << " is " 
				  << rmq(query) << std::endl;
	}
}

int main() {
	tree[0].push_back(1);
	tree[0].push_back(2);

	tree[1].push_back(3);

	tree[2].push_back(4);
	tree[2].push_back(5);

	tree[4].push_back(6);

	LCA();
	return 0;
}