#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct coordinate {
	int x;
	int y;
};

bool cmp(const coordinate& a, const coordinate& b) {
	if (a.y < b.y) {
		return true;
	}
	else if (a.y > b.y) {
		return false;
	}
	else {
		if (a.x < b.x) {
			return true;
		}
		else {
			return false;
		}
	}
}


int main() {
	int test_num;
	int input_x;
	int input_y;

	vector<coordinate> list;

	cin >> test_num;

	for (int count = 0; count < test_num; count++) {
		cin >> input_x >> input_y;
		list.push_back({ input_x, input_y });
	}

	sort(list.begin(), list.end(), cmp);

	for (int index = 0; index < test_num; index++) {
		cout << list[index].x << " " << list[index].y << "\n";
	}
}