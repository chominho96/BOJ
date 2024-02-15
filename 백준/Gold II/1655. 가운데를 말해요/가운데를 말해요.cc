#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int test_num;
	int input_num;

	cin >> test_num;
	
	cin >> input_num;
	max_heap.push(input_num);

	cout << input_num << "\n";							// only for first case
	
	for (int count = 1; count < test_num; count++) {	// repeat n - 1 times
		cin >> input_num;

		if (input_num <= max_heap.top()) {				// push
			max_heap.push(input_num);
		}
		else{
			min_heap.push(input_num);
		}
		
		if (min_heap.size() > max_heap.size()) {		// maintain balance of both max heap and min heap
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		else if (max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		
		cout << max_heap.top() << "\n";
	}

}