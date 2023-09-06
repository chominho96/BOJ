#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

struct node {
	string str;
};

struct compare {
	bool operator()(const node& n1, const node& n2) {
		if (n1.str.length() == n2.str.length()) return n1.str > n2.str;
		return n1.str.length() > n2.str.length();
	}
};

int N;

int main() {
	FASTIO;
	cin >> N;


	string str;
	priority_queue<node, vector<node>, compare> pq;

	while (N--) {
		cin >> str;
		pq.push({ str });
	}

	string current = "";
	while (!pq.empty()) {
		if (pq.top().str == current) {
			pq.pop();
			continue;
		}

		current = pq.top().str;
		pq.pop();
		cout << current << endl;
	}
	
}