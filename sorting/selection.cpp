#include<cstdio>
#include<iostream>
#include<vector>

std::vector<int> v;

void selection_sort() {
	int n = v.size();
	for(int i = 0 ; i < n ; i++) {
		int min = INT_MAX;
		int min_index ;
		for(int j = i ; j < n ; j++) {
			if(v[j] < min) {
				min = v[j];
				min_index = j;
			}
		}
		std::swap(v[i], v[min_index]);
	}
}

int main() {
	v.push_back(8);
	v.push_back(5);
	v.push_back(2);
	v.push_back(6);
	v.push_back(9);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(0);
	v.push_back(7);

	selection_sort();

	for(auto const& ele : v) {
		std::cout << ele << ' ';
	}
	return 0;
}