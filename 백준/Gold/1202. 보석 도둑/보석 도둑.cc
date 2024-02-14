#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct wei_val {
	int weight;
	int value;
};


struct cmp {
	bool operator()(const wei_val& w_v_1, const wei_val& w_v_2) {
		return w_v_1.value < w_v_2.value;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	priority_queue<wei_val, vector<wei_val>, cmp> jewerly;
	//priority_queue<int, vector<int>, greater<int>> bag;
	multiset<int> bag;

	int M, V;
	for (int count = 0; count < N; count++) {
		cin >> M >> V;
		jewerly.push(wei_val{ M, V });
	}

	int C;
	for (int count = 0; count < K; count++) {
		cin >> C;
		bag.insert(C);
	}

	long long result = 0;
	
	while (!jewerly.empty() && !bag.empty()) {
		wei_val currnet_jew = jewerly.top();
		jewerly.pop();

		multiset<int>::iterator bag_iter = bag.lower_bound(currnet_jew.weight);

		if (bag_iter != bag.end()) {
			// if bag exists
			result += currnet_jew.value;
			bag.erase(bag_iter);
		}
	}

	cout << result << endl;



}