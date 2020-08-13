#include<cstdio>
#include<iostream>
#include<array>

constexpr int MAX_DIGIT = 100;

template<std::size_t SIZE>
std::array<int, SIZE> counting_sort(std::array<int, SIZE>& ar, int digit, int N) {
	std::array<int, SIZE> result; 
	int cnt[10] = {0};
	for(auto const &ele : ar) {
		cnt[(ele/digit)%10]++;
	}

	for(int i = 1 ; i < 10 ; i++) {
		cnt[i] += cnt[i-1];
	}

	for(int i = 9 ; i > 0 ; i--) {
		cnt[i] = cnt[i-1];
	}
	cnt[0] = 0;

	for(auto const &ele : ar) {
		result[cnt[(ele/digit)%10]++] = ele;
	}

	for(auto const &ele : result) {
		std::cout << ele << ' ';
	}
	std::cout << std::endl << std::endl;

	return result;
}

void radix_sort(std::array<int, 6> ar) {
	int N = ar.size();
	for(int i = 1 ; i <= MAX_DIGIT ; i*=10) {
		ar = counting_sort(ar, i, N);
	}

	std::cout << "Resulting sorted list: " << std::endl;
	for(auto const &ele : ar) {
		std::cout << ele << ' ';
	}
	std::cout << std::endl << std::endl;
}

int main() {
	std::array<int, 6> ar = {53, 89, 150, 36, 633, 233};
	for(auto const &ele : ar) {
		std::cout << ele << ' ';
	}
	std::cout << std::endl << std::endl;

	radix_sort(ar);

	return 0;
}