#include<cstdio>
#include<iostream>
#include<string>

constexpr int MAXN = 110;

int dist[MAXN][MAXN];

void fill_inf(int n) {
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			dist[i][j] = INT_MAX;
		}
		dist[i][i] = 0;
	}
}

void apsp(int n) {
	for(int k = 1 ; k <= n ; k++) {
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 1 ; j <= n ; j++) {
				if(dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			if(dist[i][j] < INT_MAX) {
				std::cout << dist[i][j] << " ";
			}
			else {
				std::cout << "X ";
			}
		}
		std::cout << std::endl;
	}
}

int main() {
	fill_inf(6);
	dist[1][2] = 4;
	dist[1][3] = 2;

	dist[2][3] = 5;
	dist[2][4] = 10;

	dist[3][5] = 3;

	dist[4][6] = 11;

	dist[5][4] = 4;

	apsp(6);
	return 0;
}