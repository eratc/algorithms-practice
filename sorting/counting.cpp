#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

constexpr int MIN_AGE = 14, MAX_AGE = 20;

struct person {
	int age;
	std::string name;
} ;

void counting_sort(std::vector<person> players) {
	int N = players.size();
	person result[N];
	int cnt[20] = {0};

	// Count ages of players
	for(auto const &player : players) {
		cnt[player.age]++;
	}

	// Add to the right accumulatively
	for(int i = MIN_AGE+1 ; i <= MAX_AGE ; i++) {
		cnt[i] += cnt[i-1];
	}

	// Shift right
	for(int i = MAX_AGE ; i >= MIN_AGE ; i--) {
		cnt[i] = cnt[i-1];
	}

	// Stable sort of players
	for(auto const &player : players) {
		result[cnt[player.age]++] = player;
	}

	// Print result
	for(int i = 0 ; i < N ; i++) {
		std::cout << result[i].name << ' ' << result[i].age << std::endl;
	}
}

int main() {
	std::vector<person> players;
	players.push_back({16, "Sakuragi Hanamichi"});
	players.push_back({18, "Mitsui Hisashi"});
	players.push_back({17, "Miyagi Ryota"});
	players.push_back({18, "Akagi Takenori"});
	players.push_back({18, "Kogure Kiminobu"});
	players.push_back({17, "Sendoh Akira"});

	std::cout << "List of players:" << std::endl;
	for(auto const &player : players) {
		std::cout << player.name << ' ' << player.age << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Sorted list of players:" << std::endl;
	counting_sort(players);

	return 0;
}