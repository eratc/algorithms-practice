#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>

std::vector<std::vector<int>> sparseTable;

int log_floor(double val) {
	return std::floor(std::log2(val));
}

void construct_sparse_table(std::vector<int> values) {
	int N = values.size();
	int M = log_floor(N)+1;
	sparseTable.assign(M, std::vector<int>(N));

	for(int i = 0 ; i < N ; i++) {
		sparseTable[0][i] = values[i];
	}

	for(int i = 1 ; i < M ; i++) {
		int offset = (1<<(i-1));
		for(int j = 0 ; j < N - (1<<i) + 1 ; j++) {
			sparseTable[i][j] = std::min(sparseTable[i-1][j], sparseTable[i-1][j + offset]);
		}
	}

	for(auto const &row : sparseTable) {
		for(auto const &val : row) {
			std::cout << val << ' ';
		}
		std::cout << std::endl;
	}
}

void range_minimum_queries(std::vector<std::pair<int, int>> queries) {
	for(auto const &q : queries) {
		int P = log_floor(q.second - q.first + 1);
		int result = std::min(sparseTable[P][q.first], sparseTable[P][q.second - (1<<P) + 1]);
		std::cout << "Min value in range [" << q.first << ", " << q.second << "] is: " << result << std::endl;
	}
}


int main() {
	std::vector<int> values{4, 2, 3, 7, 1, 5, 3, 3, 9, 6, 7, -1, 4};

	std::vector<std::pair<int, int>> queries{std::pair<int, int>(0, 12),
											 std::pair<int, int>(5, 9),
											 std::pair<int, int>(1, 10),
											 std::pair<int, int>(2, 7),
											 std::pair<int, int>(0, 2),
											 std::pair<int, int>(8, 10),
											 std::pair<int, int>(5, 10)};

	construct_sparse_table(values);

	range_minimum_queries(queries);
	return 0;
}