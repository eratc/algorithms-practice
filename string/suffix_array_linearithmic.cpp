#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<utility>

std::vector<int> sort_cyclic_shifts(std::string const& s) {
	int N = s.size();
	const int alphabet = 256;
	std::vector<int> p(N), c(N), cnt(std::max(alphabet, N), 0);

	// Sort suffixes by first character
	for(int i = 0 ; i < N ; i++) {
		cnt[s[i]]++;
	}

	for(int i = 1 ; i < alphabet ; i++) {
		cnt[i] += cnt[i-1];
	}

	for(int i = alphabet-1 ; i > 0 ; i--) {
		cnt[i] = cnt[i-1];
	}
	cnt[0] = 0;

	for(int i = 0 ; i < N ; i++) {
		p[cnt[s[i]]++] = i;
	}

	int classes = 0;
	c[p[0]] = 0;
	for(int i = 1 ; i < N ; i++) {
		if(s[p[i]] != s[p[i-1]]) {
			classes++;
		}
		c[p[i]] = classes;
	}
	classes++;

	std::vector<int> pn(N), cn(N);
	for(int s = 0 ; (1 << s) < N ; s++) {
		std::fill(cnt.begin(), cnt.end(), 0);

		for(int i = 0 ; i < N ; i++) {
			pn[i] = p[i] - (1 << s);
			if(pn[i] < 0) {
				pn[i] += N;
			}
		}

		for(int i = 0 ; i < N ; i++) {
			cnt[c[pn[i]]]++;
		}

		for(int i = 1 ; i < classes ; i++) {
			cnt[i] += cnt[i-1];
		}

		for(int i = classes-1 ; i > 0 ; i--) {
			cnt[i] = cnt[i-1];
		}
		cnt[0] = 0;

		for(int i = 0 ; i < N ; i++) {
			p[cnt[c[pn[i]]]++] = pn[i];
		}

		classes = 0;
		cn[p[0]] = 0;
		for(int i = 1 ; i < N ; i++) {
			std::pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << s)) % N]};
			std::pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << s)) % N]};
			if(cur != prev) {
				classes++;
			}
			cn[p[i]] = classes;
		}
		classes++;
		c.swap(cn);
	}
	return p;
}

std::vector<int> suffix_array(std::string s) {
	s += "$";
	std::vector<int> sorted_shifts = sort_cyclic_shifts(s);
	sorted_shifts.erase(sorted_shifts.begin());
	return sorted_shifts;
}

int main() {
	std::string str = "mississippi";
	std::cout << str << std::endl << std::endl;
	std::vector result = suffix_array(str);
	
	for(auto const &ele : result) {
		std::cout << ele << ' ';
		for(int i = ele ; i < str.length() ; i++) {
			std::cout << str[i];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}