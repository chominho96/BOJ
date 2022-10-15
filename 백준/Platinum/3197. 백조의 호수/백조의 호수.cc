#include <iostream>
#include <string>
#include <queue>
#include <deque>

using namespace std;

struct row_and_col {
	short Row;
	short Col;
};

char adj[1500][1500];
bool visited[1500][1500];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

class Graph {
	short row;
	short col;
	short start_row;
	short start_col;
	short last_row;
	short last_col;
	queue<row_and_col> melt_r_c;
	deque<row_and_col> next_route;
public:
	Graph() {

	}
	void reset_visit() {
		for (short r = 0; r < row; r++) {
			for (short c = 0; c < col; c++) {
				visited[r][c] = false;
			}
		}
	}
	void load(short r, short c) {

		// input and initialize

		row = r;
		col = c;


		reset_visit();

		string input_string;

		bool flag = false;

		for (short count = 0; count < r; count++) {
			cin >> input_string;
			for (short index = 0; index < c; index++) {
				adj[count][index] = input_string[index];
				if (flag == false && adj[count][index] == 'L') {
					start_row = count;
					start_col = index;
					flag = true;
				}
				else {
					if (flag == true && adj[count][index] == 'L') {
						last_row = count;
						last_col = index;
					}
				}
			}
		}
		setMelt();
	}

	bool is_next_melt(int r, int c) {

		// for initialize

		if (r == 0 && c == 0) {						// UP-LEFT
			if (adj[r + 1][c] == '.' || adj[r + 1][c] == 'L' || adj[r][c + 1] == '.' || adj[r][c + 1] == 'L') {
				return true;
			}
		}
		else if (r == 0 && c == col - 1) {			// UP-RIGHT
			if (adj[r + 1][c] == '.' || adj[r + 1][c] == 'L' || adj[r][c - 1] == '.' || adj[r][c - 1] == 'L') {
				return true;
			}

		}
		else if (r == row - 1 && c == 0) {			// DONW-LEFT
			if (adj[r - 1][c] == '.' || adj[r - 1][c] == 'L' || adj[r][c + 1] == '.' || adj[r][c + 1] == 'L') {
				return true;
			}
		}
		else if (r == row - 1 && c == col - 1) {	// DOWN-RIGHT
			if (adj[r - 1][c] == '.' || adj[r - 1][c] == 'L' || adj[r][c - 1] == '.' || adj[r][c - 1] == 'L') {
				return true;
			}
		}
		else if (r == 0) {							// first row
			if (adj[r + 1][c] == '.' || adj[r + 1][c] == 'L'
				|| adj[r][c + 1] == '.' || adj[r][c + 1] == 'L' || adj[r][c - 1] == '.' || adj[r][c - 1] == 'L') {
				return true;
			}
		}
		else if (r == row - 1) {					// last row
			if (adj[r - 1][c] == '.' || adj[r - 1][c] == 'L'
				|| adj[r][c + 1] == '.' || adj[r][c + 1] == 'L' || adj[r][c - 1] == '.' || adj[r][c - 1] == 'L') {
				return true;
			}
		}
		else if (c == 0) {							// first col
			if (adj[r + 1][c] == '.' || adj[r + 1][c] == 'L' || adj[r - 1][c] == '.' || adj[r - 1][c] == 'L'
				|| adj[r][c + 1] == '.' || adj[r][c + 1] == 'L') {
				return true;
			}
		}
		else if (c == col - 1) {					// last col
			if (adj[r + 1][c] == '.' || adj[r + 1][c] == 'L' || adj[r - 1][c] == '.' || adj[r - 1][c] == 'L'
				|| adj[r][c - 1] == '.' || adj[r][c - 1] == 'L') {
				return true;
			}
		}
		else {										// general case
			if (adj[r + 1][c] == '.' || adj[r + 1][c] == 'L' || adj[r - 1][c] == '.' || adj[r - 1][c] == 'L'
				|| adj[r][c + 1] == '.' || adj[r][c + 1] == 'L' || adj[r][c - 1] == '.' || adj[r][c - 1] == 'L') {
				return true;
			}
		}
		return false;
	}

	void setMelt() {

		// for initialize

		for (short r = 0; r < row; r++) {
			for (short c = 0; c < col; c++) {
				if (adj[r][c] == 'X' && is_next_melt(r, c)) {
					melt_r_c.push({ r, c });
				}
			}
		}
	}

	void melt() {
		int count = melt_r_c.size();
		while (true) {
			if (count == 0) {
				break;
			}
			count--;

			short m_r = melt_r_c.front().Row;
			short m_c = melt_r_c.front().Col;
			melt_r_c.pop();

			if (adj[m_r][m_c] == '.') {
				continue;
			}

			adj[m_r][m_c] = '.';

			for (int i = 0; i < 4; i++) {
				short nx = m_r + dx[i];
				short ny = m_c + dy[i];

				if (nx >= 0 && ny >= 0 && nx < row && ny < col) {
					if (adj[nx][ny] == 'X') {
						melt_r_c.push({ nx, ny });
					}
				}
			}

			
			
		}
	}


	bool first_BFS() {
		visited[start_row][start_col] = true;

		queue<row_and_col> que_r_c;
		que_r_c.push({ start_row, start_col });


		while (!que_r_c.empty()) {
			short current_r = que_r_c.front().Row;
			short current_c = que_r_c.front().Col;

			que_r_c.pop();

			if (current_r == last_row && current_c == last_col) {
				return true;
			}

			for (int i = 0; i < 4; i++) {
				short nx = current_r + dx[i];
				short ny = current_c + dy[i];

				if (nx >= 0 && ny >= 0 && nx < row && ny < col && visited[nx][ny] == false) {
					if (adj[nx][ny] == 'X') {
						next_route.push_back({ nx, ny });
						visited[nx][ny] = true;
					}
					else {
						que_r_c.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}
			}



		}
		return false;
	}

	bool second_search() {
		// it is not actually BFS
		int count = next_route.size();


		while (true) {
			if (count == 0) {
				break;
			}
			count--;

			short current_r = next_route.front().Row;
			short current_c = next_route.front().Col;


			next_route.pop_front();

			if (current_r == last_row && current_c == last_col) {
				return true;
			}


			for (int i = 0; i < 4; i++) {
				short nx = current_r + dx[i];
				short ny = current_c + dy[i];

				if (nx >= 0 && ny >= 0 && nx < row && ny < col && visited[nx][ny] == false) {
					if (adj[nx][ny] == 'X') {
						next_route.push_back({ nx, ny });
						visited[nx][ny] = true;
					}
					else {
						next_route.push_front({ nx, ny });
						visited[nx][ny] = true;
						count++;
					}
				}
			}


		}

		return false;

		
	
	}
	void meltBFS() {
		int result = 0;

		if (first_BFS()) {
			cout << result << "\n";
			return;
		}
		melt();
		result++;

		while (true) {
			if (second_search()) {
				cout << result << "\n";
				return;
			}
			result++;
			melt();
		}
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input_row, input_col;
	cin >> input_row >> input_col;

	Graph graph;
	graph.load(input_row, input_col);
	graph.meltBFS();
}