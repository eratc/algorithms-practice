#include<cstdio>
#include<iostream>
#include<vector>

constexpr int MAXN = 110;

int dn[MAXN][MAXN];
int m[6] = {4, 10, 3, 12, 20, 7};

int mcp(int a, int b) {
	if(dn[a][b]) {
		return dn[a][b];
	}

	if(b == a+1) {
		return 0;
	}

	int min = INT_MAX;
	for(int i = a+1 ; i < b ; i++) {
		min = std::min(mcp(a, i) + mcp(i, b) + m[a]*m[i]*m[b], min);
	}

	return dn[a][b] = min;
}

int main() {
	int n = 6;
	std::cout << mcp(0, n-1) << std::endl;
	return 0;
}