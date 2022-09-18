#include <iostream>
#define MAX_SIZE 65537
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int arr[250001];
int segmentTree[MAX_SIZE * 4];


void updateNode(int nodeIdx, int left, int right, int value, int diff) {
	// end condition
	if (left == right) {
		segmentTree[nodeIdx] += diff;
		return;
	}

	int mid = (left + right) / 2;

	if (value <= mid) {
		updateNode(nodeIdx * 2, left, mid, value, diff);
	}
	else {
		updateNode(nodeIdx * 2 + 1, mid + 1, right, value, diff);
	}

	segmentTree[nodeIdx] = segmentTree[nodeIdx * 2] + segmentTree[nodeIdx * 2 + 1];

}


int findNode(int nodeIdx, int left, int right, int value) {
	// end condition
	if (left == right) {
		return left;
	}

	int mid = (left + right) / 2;

	if (segmentTree[nodeIdx * 2] >= value) {
		return findNode(nodeIdx * 2, left, mid, value);
	}
	else {
		return findNode(nodeIdx * 2 + 1, mid + 1, right, value - segmentTree[nodeIdx * 2]);
	}
}



int main() {

	FASTIO;

	int N, K;
	cin >> N >> K;
	long long ans = 0;

	// 1. insert
	for (int j = 0; j < K - 1; j++) {
		cin >> arr[j];
		updateNode(1, 0, MAX_SIZE, arr[j], 1);
	}

	for (int j = K - 1; j < N; j++) {
		cin >> arr[j];
		updateNode(1, 0, MAX_SIZE, arr[j], 1);

		ans += findNode(1, 0, MAX_SIZE, (K + 1) / 2);

		updateNode(1, 0, MAX_SIZE, arr[j - K + 1], - 1);
	}

	cout << ans << '\n';

}