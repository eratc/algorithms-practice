#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

std::vector<int> v;

void insertion_sort() {
	int n = v.size();
	for(int i = 0 ; i < n ; i++) {
		int old_pos = i+1;
		int new_pos;
		for(new_pos = i ; new_pos >= 0 ; new_pos--) {
			if(v[new_pos] > v[old_pos]) {
				std::swap(v[new_pos], v[old_pos]);
				old_pos = new_pos;
			}
			else {
				break;
			}
		}
	}
}

int main() {
	v.push_back(6);
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	v.push_back(8);
	v.push_back(7);
	v.push_back(2);
	v.push_back(4);
	insertion_sort();

	for(auto const& ele : v) {
		std::cout << ele << ' ';
	}
	return 0;
}