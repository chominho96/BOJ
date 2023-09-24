#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 51
#define MAX_COUNT 1001

using namespace std;

struct FIRE_BALL {
    int mass;
    int dir;
    int speed;
};

vector<FIRE_BALL> MAP[MAX_SIZE][MAX_SIZE][MAX_COUNT];
int N, M, K;
int dx[]{-1, -1, 0, 1, 1, 1, 0, -1};
int dy[]{0, 1, 1, 1, 0, -1, -1, -1};

void magic(int cnt) {

    // 1. 이동
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < MAP[i][j][cnt].size(); k++) {
                FIRE_BALL current = MAP[i][j][cnt][k];

                int dist = current.speed;
                int next_row = i;
                int next_col = j;
                while (true) {
                    if (dist-- == 0) break;

                    next_row += dx[current.dir];
                    next_col += dy[current.dir];

                    if (next_row == 0) next_row = N;
                    else if (next_row == N + 1) next_row = 1;
                    if (next_col == 0) next_col = N;
                    else if (next_col == N + 1) next_col = 1;
                }

                MAP[next_row][next_col][cnt + 1].push_back(current);
            }
        }
    }

    // 2. 파이어볼 생성
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            int fireballNumber = MAP[i][j][cnt + 1].size();
            if (fireballNumber >= 2) {

                int totalMass = 0;
                int totalSpeed = 0;
                bool isAllOdd = true;
                bool isAllEven = true;

                for (int k = 0; k < MAP[i][j][cnt + 1].size(); k++) {
                    totalMass += MAP[i][j][cnt + 1][k].mass;
                    totalSpeed += MAP[i][j][cnt + 1][k].speed;

                    if (MAP[i][j][cnt + 1][k].dir % 2 == 0) isAllOdd = false;
                    else isAllEven = false;
                }

                MAP[i][j][cnt + 1].clear();

                int next_mass = totalMass / 5;
                if (next_mass > 0) {
                    int next_speed = totalSpeed / fireballNumber;

                    if (isAllEven || isAllOdd) {
                        MAP[i][j][cnt + 1].push_back({next_mass, 0, next_speed});
                        MAP[i][j][cnt + 1].push_back({next_mass, 2, next_speed});
                        MAP[i][j][cnt + 1].push_back({next_mass, 4, next_speed});
                        MAP[i][j][cnt + 1].push_back({next_mass, 6, next_speed});
                    }
                    else {
                        MAP[i][j][cnt + 1].push_back({next_mass, 1, next_speed});
                        MAP[i][j][cnt + 1].push_back({next_mass, 3, next_speed});
                        MAP[i][j][cnt + 1].push_back({next_mass, 5, next_speed});
                        MAP[i][j][cnt + 1].push_back({next_mass, 7, next_speed});
                    }
                }
            }
        }
    }

}

int calc() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < MAP[i][j][K].size(); k++) {
                ans += MAP[i][j][K][k].mass;
            }
        }
    }
    return ans;
}

int main() {
    FASTIO;
    cin >> N >> M >> K;
    int r, c, m, s, d;
    while (M--) {
        cin >> r >> c >> m >> s >> d;
        MAP[r][c][0].push_back({m, d, s});
    }

    for (int i = 0; i < K; i++) {
        magic(i);
    }

    cout << calc() << endl;
}