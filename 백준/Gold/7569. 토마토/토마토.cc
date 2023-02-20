#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 101

using namespace std;

struct tomato {
	int x;
	int y;
	int z;
	int order;
};

int MAP[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int M, N, H;
int dx[]{ 1, -1, 0, 0, 0, 0 };
int dy[]{ 0, 0, 1, -1, 0, 0 };
int dz[]{ 0, 0, 0, 0, 1, -1 };

bool isRoute(const int& x, const int& y, const int& z) {
	return x >= 1 && x <= M && y >= 1 && y <= N && z >= 1 && z <= H;
}

void BFS() {
	queue<tomato> que;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= H; k++) {
				if (MAP[i][j][k] == 1) {
					que.push({ i, j, k, 0 });
				}
			}
		}
	}

	int ans = 0;
	while (!que.empty()) {
		tomato current = que.front();
		que.pop();

		for (int i = 0; i < 6; i++) {
			int next_x = current.x + dx[i];
			int next_y = current.y + dy[i];
			int next_z = current.z + dz[i];
			if (isRoute(next_x, next_y, next_z) && MAP[next_x][next_y][next_z] == 0) {
				MAP[next_x][next_y][next_z] = 1;
				que.push({ next_x, next_y, next_z, current.order + 1 });
				if (current.order + 1 > ans) {
					ans = current.order + 1;
				}
			}
		}
	}


	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= H; k++) {
				if (MAP[i][j][k] == 0) {
					cout << -1 << endl;
					exit(0);
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
	FASTIO;
	cin >> M >> N >> H;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> MAP[k][j][i];
			}
		}
	}
	BFS();
}