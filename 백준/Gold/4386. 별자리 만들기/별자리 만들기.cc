#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 101
#define INF 987654321.0
#define endl '\n'

using namespace std;

struct edge {
	int node;
	double value;
};

vector<edge> MAP[MAX_SIZE];
int n;
double COORD[MAX_SIZE][2];
double DIST[MAX_SIZE];
bool visited[MAX_SIZE];

double getDistance(int x, int y) {
	return sqrt(pow(COORD[x][0] - COORD[y][0], 2) + pow(COORD[x][1] - COORD[y][1], 2));
}

int main() {
	FASTIO;
	cin >> n;
	for (int i = 1; i <= n; i++) DIST[i] = INF;
	for (int i = 1; i <= n; i++) {
		cin >> COORD[i][0] >> COORD[i][1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			double dist = getDistance(i, j);
			MAP[i].push_back({ j, dist });
			MAP[j].push_back({ i, dist });
		}
	}
	DIST[1] = 0;
	double res = 0;
	for (int i = 1; i <= n; i++) {
		int current = -1;
		double minDist = INF;
		for (int j = 1; j <= n; j++) {
			if (!visited[j] && minDist > DIST[j]) {
				minDist = DIST[j];
				current = j;
			}
		}

		res += minDist;
		visited[current] = true;
		for (int i = 0; i < MAP[current].size(); i++) {
			int next = MAP[current][i].node;
			DIST[next] = min(DIST[next], MAP[current][i].value);
		}
	}
	
	cout << fixed;
	cout.precision(2);
	cout << res << endl;
	
}