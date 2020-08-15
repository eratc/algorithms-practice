#include<cstdio>
#include<iostream>
#include<vector>

class DSU {
	std::vector<int> parent, size;
public:
	DSU(int);
	void make_set(int);
	int find_set(int);
	void union_sets(int, int);
};

DSU::DSU(int N) {
	parent.assign(N, 0);
	size.assign(N, 0);
}

void DSU::make_set(int v) {
	parent[v] = v;
	size[v] = 1;
}

int DSU::find_set(int v) {
	if(v == parent[v]) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

void DSU::union_sets(int v, int u) {
	v = find_set(v);
	u = find_set(u);
	if(u != v) {
		if(size[v] < size[u]) {
			std::swap(v, u);
		}
		parent[u] = v;
		size[v] += size[u];
	}
}


void print_sets(DSU dsu) {
	for(int i = 0 ; i < 10 ; i++) {
		std::cout << dsu.find_set(i) << ' ';
	}
	std::cout << std::endl << std::endl;
}

int main() {
	DSU dsu(10);

	dsu.make_set(0);
	dsu.make_set(1);
	dsu.make_set(2);
	dsu.make_set(3);
	dsu.make_set(4);
	dsu.make_set(5);
	dsu.make_set(6);
	dsu.make_set(7);
	dsu.make_set(8);
	dsu.make_set(9);

	dsu.union_sets(0,1);
	dsu.union_sets(2,3);
	dsu.union_sets(4,5);
	dsu.union_sets(6,7);
	dsu.union_sets(8,9);

	print_sets(dsu);
	dsu.union_sets(6,9);
	print_sets(dsu);
	dsu.union_sets(5,7);
	print_sets(dsu);
	dsu.union_sets(0,2);
	print_sets(dsu);
	dsu.union_sets(3,4);
	print_sets(dsu);
	dsu.union_sets(1,6);
	print_sets(dsu);
	dsu.union_sets(8,9);
	print_sets(dsu);
	
	return 0;
}