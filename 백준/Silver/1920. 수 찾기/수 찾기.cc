#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binary_search(vector<int>& list, const int& key, const int& left, const int& right) {
	if (left <= right) {
		int middle = (right + left) / 2;
		if (key == list[middle]) {
			cout << "1\n";
			return;
		}
		else if (key < list[middle]) {
			binary_search(list, key, left, middle - 1);
			return;
		}
		else if (key > list[middle]) {
			binary_search(list, key, middle + 1, right);
			return;
		}
	}
	
	cout << "0\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> input;
	vector<int> result;

	int test_num;
	int test_num_2;
	int input_value;

	cin >> test_num;

	for (int count = 0; count < test_num; count++) {
		cin >> input_value;
		input.push_back(input_value);
	}
	sort(input.begin(), input.end());
	

	cin >> test_num_2;

	for (int count = 0; count < test_num_2; count++) {
		cin >> input_value;
		result.push_back(input_value);
	}

	for (int index = 0; index < test_num_2; index++) {
		binary_search(input, result[index], 0, test_num - 1);
	}


	
}