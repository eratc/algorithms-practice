#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

constexpr int MAXN = 110;

int dn[MAXN][MAXN];

std::string backtrack(std::string s1, std::string s2, int i, int j) {
	if(dn[i][j] == 0) {
		return "";
	}
	if(s1[i] == s2[j]) {
		return backtrack(s1, s2, i-1, j-1) + s1[i];
	}
	else if(dn[i-1][j] > dn[i][j-1]){
		return backtrack(s1, s2, i-1, j);
	}
	else {
		return backtrack(s1, s2, i, j-1);
	}
}

void lcs(std::string s1, std::string s2) {
	int n1 = s1.length()-1;
	int n2 = s2.length()-1;

	for(int i = 1 ; i <= n1 ; i++) {
		for(int j = 1 ; j <= n2 ; j++) {
			if(s1[i] == s2[j]) {
				dn[i][j] = dn[i-1][j-1]+1;
			}
			else {
				dn[i][j] = std::max(dn[i-1][j], dn[i][j-1]);
			}
		}
	}

	std::cout << "Length of lcs: " << dn[n1][n2] << std::endl;
	std::cout << backtrack(s1, s2, n1, n2);
}

int main() {
	std::string s1 = " XMJYAUZ";
	std::string s2 = " MZJAWXU";
	lcs(s1, s2);
	return 0;
}