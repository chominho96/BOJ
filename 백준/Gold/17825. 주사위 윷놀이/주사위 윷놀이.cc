#include <iostream>
#include <vector>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define DICE_NUMBER 11
#define MAX_SIZE 42
#define END_INDEX -1

using namespace std;

struct node {
	int value;
	int nextRedIdx;
	int nextBlueIdx;
};

int DICE[DICE_NUMBER];
node MAP[MAX_SIZE];
int ans = 0;

void init() {
	for (int i = 0; i <= 19; i++) {
		MAP[i].value = i * 2;
		MAP[i].nextRedIdx = i + 1;
	}
	MAP[20].value = 40;
	MAP[20].nextRedIdx = END_INDEX;

	MAP[5].nextBlueIdx = 21;
	MAP[10].nextBlueIdx = 27;
	MAP[15].nextBlueIdx = 24;

	MAP[21].value = 13;
	MAP[21].nextRedIdx = 22;
	MAP[22].value = 16;
	MAP[22].nextRedIdx = 23;
	MAP[23].value = 19;
	MAP[23].nextRedIdx = 29;

	MAP[24].value = 28;
	MAP[24].nextRedIdx = 25;
	MAP[25].value = 27;
	MAP[25].nextRedIdx = 26;
	MAP[26].value = 26;
	MAP[26].nextRedIdx = 29;

	MAP[27].value = 22;
	MAP[27].nextRedIdx = 28;
	MAP[28].value = 24;
	MAP[28].nextRedIdx = 29;
	MAP[29].value = 25;
	MAP[29].nextRedIdx = 30;
	MAP[30].value = 30;
	MAP[30].nextRedIdx = 31;
	MAP[31].value = 35;
	MAP[31].nextRedIdx = 20;
}

int getNextPos(int pos, int dice) {

	// 첫 번째 무빙
	if (pos == 5 || pos == 10 || pos == 15) {
		pos = MAP[pos].nextBlueIdx;
		dice--;
	}

	for (int i = 0; i < dice; i++) {
		pos = MAP[pos].nextRedIdx;
		if (pos == END_INDEX) return pos;
	}

	return pos;
}

void calc(vector<int> horsePos, int horseIdx, int diceIdx, int value) {

	if (horsePos[horseIdx] == END_INDEX) return;			// 이미 도착한 말인 경우

	int nextPos = getNextPos(horsePos[horseIdx], DICE[diceIdx]);
	int currentValue = nextPos == END_INDEX ? 0 : MAP[nextPos].value;

	if (nextPos != END_INDEX) {
		for (int i = 1; i <= 4; i++) {
			if (i == horseIdx) continue;
			if (horsePos[i] == nextPos) return;		// 다른 말과 겹치는 경우
		}
	}

	if (diceIdx == 10) {	// end condition
		if (value + currentValue > ans) ans = value + currentValue;
		return;
	}

	horsePos[horseIdx] = nextPos;
	
	// go next
	for (int i = 1; i <= 4; i++) {
		calc(horsePos, i, diceIdx + 1, value + currentValue);
	}
}

int main() {
	FASTIO;
	init();
	for (int i = 1; i <= 10; i++) {
		cin >> DICE[i];
	}
	
	for (int i = 1; i <= 4; i++) {
		vector<int> horsePos{ 0, 0, 0, 0, 0 };
		calc(horsePos, i, 1, 0);
	}

	cout << ans << endl;
}