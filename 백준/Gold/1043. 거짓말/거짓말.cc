#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 51

using namespace std;

int N, M, K;
bool KNOW_TRUTH[MAX_SIZE];
bool FINISH[MAX_SIZE];
vector<int> PARTY[MAX_SIZE];
bool KNOW_TRUTH_PARTY[MAX_SIZE];
vector<int> PEOPLE[MAX_SIZE];

int main() {
	FASTIO;
	cin >> N >> M;
	cin >> K;

	int know;
	queue<int> SPLASH;
	for (int i = 0; i < K; i++) {
		cin >> know;
		KNOW_TRUTH[know] = true;
		SPLASH.push(know);
	}
	int party;

	for (int i = 0; i < M; i++) {
		cin >> party;

		PARTY[i].resize(party);
		for (int j = 0; j < party; j++) {
			cin >> PARTY[i][j];
			PEOPLE[PARTY[i][j]].push_back(i);
		}
	}

	while (!SPLASH.empty()) {
		int current = SPLASH.front();
		if (!FINISH[current]) {
			FINISH[current] = true;
			for (int i = 0; i < PEOPLE[current].size(); i++) {
				int team = PEOPLE[current][i];
				for (int j = 0; j < PARTY[team].size(); j++) {
					if (!FINISH[PARTY[team][j]]) {
						KNOW_TRUTH[PARTY[team][j]] = true;
						SPLASH.push(PARTY[team][j]);
					}
				}
			}
		}
		SPLASH.pop();
	}


	for (int i = 0; i < M; i++) {
		if (!KNOW_TRUTH_PARTY[i]) {
			for (int j = 0; j < PARTY[i].size(); j++) {
				if (KNOW_TRUTH[PARTY[i][j]]) {
					KNOW_TRUTH_PARTY[i] = true;
					break;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (!KNOW_TRUTH_PARTY[i]) ans++;
	}
	
	cout << ans << endl;

}