#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

constexpr int MAXN = 110;

struct Point {
	int x, y;
	bool operator<(Point const& other) {
		return x < other.x || (x == other.x && y < other.y);
	}
};

bool cw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(std::vector<Point> dots) {
	std::vector<Point> upper_hull;
	std::vector<Point> lower_hull;

	std::sort(dots.begin(), dots.end());
	Point leftmost = dots[0];
	Point rightmost = dots.back();
	upper_hull.push_back(leftmost);
	lower_hull.push_back(leftmost);

	int n = dots.size();
	for(int i = 1 ; i < n ; i++) {
		if(i == n-1 || cw(leftmost, dots[i], rightmost)) {
			while(upper_hull.size() >= 2 && ccw(upper_hull[upper_hull.size()-2], upper_hull[upper_hull.size()-1], dots[i])) {
				upper_hull.pop_back();
			}
			upper_hull.push_back(dots[i]);
		}
		if(i == n-1 || ccw(leftmost, dots[i], rightmost)) {
			while(lower_hull.size() >= 2 && cw(lower_hull[lower_hull.size()-2], lower_hull[lower_hull.size()-1], dots[i])) {
				lower_hull.pop_back();
			}
			lower_hull.push_back(dots[i]);
		}
	}

	for(auto const& point : upper_hull) {
		std::cout << point.x << ' ' << point.y << std::endl;
	}
	for(int i = lower_hull.size()-2 ; i > 0 ; i--) {
		Point point = lower_hull[i];
		std::cout << point.x << ' ' << point.y << std::endl;
	}
}

int main() {
	std::vector<Point> dots;
	dots.push_back({0, 3});
	dots.push_back({1, 1});
	dots.push_back({2, 2});
	dots.push_back({4, 4});

	dots.push_back({0, 0});
	dots.push_back({1, 2});
	dots.push_back({3, 1});
	dots.push_back({3, 3});
	convex_hull(dots);
	return 0;
}