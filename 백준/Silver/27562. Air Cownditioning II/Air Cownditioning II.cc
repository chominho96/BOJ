	#include <iostream>
	#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
	#define MAX_SIZE 22
	#define MAX_STALL_SIZE 101
	#define endl '\n'
	#define INF 987654321

	using namespace std;

	struct cow {
		int start;
		int end;
		int value;
	};

	struct conditioner {
		int start;
		int end;
		int value;
		int cost;
	};

	int N, M;
	cow COW[MAX_SIZE];
	conditioner CONDITIONER[MAX_SIZE];
	int VALUE[MAX_STALL_SIZE];
	int COOLING[MAX_STALL_SIZE];
	bool visited[MAX_SIZE];
	long long ans = INF;
	long long current = 0;

	void add_conditioner(int index) {
		for (int i = CONDITIONER[index].start; i <= CONDITIONER[index].end; i++) {
			COOLING[i] += CONDITIONER[index].value;
		}
		visited[index] = true;
		current += CONDITIONER[index].cost;
	}

	void minus_conditioner(int index) {
		for (int i = CONDITIONER[index].start; i <= CONDITIONER[index].end; i++) {
			COOLING[i] -= CONDITIONER[index].value;
		}
		visited[index] = false;
		current -= CONDITIONER[index].cost;
	}

	bool judge() {
		for (int i = 0; i < MAX_STALL_SIZE; i++) {
			if (VALUE[i] > COOLING[i]) return false;
		}
		return true;
	}

	void calculate(int count) {
		if (judge() && current < ans) {
			ans = current;
		}

		if (count == M) return;

		for (int i = 0; i < M; i++) {
			if (!visited[i]) {
				add_conditioner(i);
				calculate(count + 1);
				minus_conditioner(i);
			}
		}
	}

	int main() {
		FASTIO;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> COW[i].start >> COW[i].end >> COW[i].value;
			for (int j = COW[i].start; j <= COW[i].end; j++) {
				if (VALUE[j] < COW[i].value) VALUE[j] = COW[i].value;
			}
		}
		for (int i = 0; i < M; i++) {
			cin >> CONDITIONER[i].start >> CONDITIONER[i].end >> CONDITIONER[i].value >> CONDITIONER[i].cost;
		}

		for (int i = 0; i < M; i++) {
			add_conditioner(i);
			calculate(1);
			minus_conditioner(i);
		}

		cout << ans << endl;
	}