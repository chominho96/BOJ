#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#define MAX_SIZE 10001

using namespace std;

bool visited[MAX_SIZE];
// 방문 체크
bool checked[MAX_SIZE];
// 출력용

class node {
	int index;
	// 사용자 번호
	list<node*> outgoing_edge_list;
	// 해당 node로부터 나가는 edge
	list<node*> incoming_edge_list;
	// 해당 node로 들어오는 edge
	list<node*>::iterator current_outgoing_iter;
	// outgoing_edge_list에 해당하는 iterator
	list<node*>::iterator current_incoming_iter;
	// incoming_edge_list에 해당하는 iterator
public:
	node(int i) : index(i) {

	}
	int getIndex() {
		// 현재 사용자번호를 return
		return index;
	}
	void insertEdge(node* to) {
		// edge 삽입
		// 현재 node의 outgoing_edge_list에 삽입하고, 대상 node의 incoming_edge_list에 삽입
		outgoing_edge_list.push_back(to);
		to->getIncomingEdgeList().push_back(this);
	}

	// outgoing_edge_list 반환
	list<node*>& getOutgoingEdgeList() {
		return outgoing_edge_list;
	}
	// incoming_edge_list 반환
	list<node*>& getIncomingEdgeList() {
		return incoming_edge_list;
	}

	// 각 node의 edge 개수만큼 DFS의 각 단계에서 탐색할 수 있도록, outgoing_edge_list와 incoming_edge_list를 정렬
	// 기준(팔로워 수가 많고, 팔로워 수가 같다면 사용자 번호가 낮은 순)에 따라 정렬
	// compare 함수가 node 클래스의 정의 이후에 사용할 수 있기 때문에, 프로토타입으로 정의 후 뒤에서 정의
	void sortOutGoingEdges();
	void sortInComingEdges();

	node* nextDFSNode() {
		// 현재 node에서 갈 수 있는 node들 중에서 다음 DFS를 수행할 node를 return

		// 정렬되어 있는 상태이기 때문에, list의 앞에서부터 차례대로 탐색하여 방문하지 않은 node를 방문하면, 해당 node로 바로 확정 후 방문 가능
		// 방문하지 않은 node를 발견하는 과정에서 current_outgoing_iter을 이용해 마지막으로 탐색한 node를 저장
		for (list<node*>::iterator iter = current_outgoing_iter; iter != outgoing_edge_list.end(); iter++, current_outgoing_iter++) {
			if (!visited[(*iter)->getIndex()]) {
				return *iter;
			}
		}
		return NULL;

	}
	node* nextReverseDFSNode() {
		// phase 2, 즉 edge를 반대로 뒤집고 DFS를 할 때 갈 수 있는 node들 중에서 다음 DFS를 수행할 node를 return


		// 정렬되어 있는 상태이기 때문에, list의 앞에서부터 차례대로 탐색하여 방문하지 않은 node를 방문하면, 해당 node로 바로 확정 후 방문 가능
		// 방문하지 않은 node를 발견하는 과정에서 current_incoming_iter을 이용해 마지막으로 탐색한 node를 저장
		// phase 1에서 모든 node의 visited를 true로 갱신했기 때문에, phase 2에서는 visited에 대해 별도 초기화하지 않고 false를 방문한 것으로 처리
		for (list<node*>::iterator iter = current_incoming_iter; iter != incoming_edge_list.end(); iter++, current_incoming_iter++) {
			if (visited[(*iter)->getIndex()]) {
				return *iter;
			}
		}
		return NULL;
	}
};

bool compare(node* n1, node* n2) {
	// list의 sort함수를 위한 compare함수
	// node들을 기준에 따라 분류
	// 팔로워 수가 많거나, 팔로워 수가 같으면 사용자 번호가 더 앞설 때 높은 우선순위를 지닌다.
	if (n1->getIncomingEdgeList().size() == n2->getIncomingEdgeList().size()) {
		return n1->getIndex() < n2->getIndex();
	}
	return n1->getIncomingEdgeList().size() > n2->getIncomingEdgeList().size();

}

class graph {
	vector<node*> node_list;
	// 일반 user list : index 1 ~ N까지를 가지며 각각의 index에 해당하는 node가 (index)번 사용자
	vector<node*> next_node_list;
	// 기준(팔로워 수가 많은 순, 팔로워 수가 같으면 번호가 낮은 순) 상으로 정렬된 사용자 vector
	// phase 1의 DFS 시 사용
	int size;
	// 전체 사용자의 수 (N)


	vector<node*> phase_1;
	// phase 1의 결과
	// 후입선출과, 임의 index 접근을 동시에 수행해야하기 때문에 vector 자료구조를 사용
	vector<int> leader;
	// phase 2의 결과


	int current_idx;
	// 방문 중인 index를 저장하여, 반복문의 반복 횟수를 user의 개수만큼만 반복할 수 있도록 함
	int cnt;
	// 방문한 user의 횟수
	int result;
public:
	graph(int s) : size(s), current_idx(1), cnt(0), result(0) {
		// node_list 초기화
		node_list.resize(s + 1);
		next_node_list.resize(s + 1);
		for (int i = 1; i <= size; i++) {
			node* new_node = new node(i);
			node_list[i] = new_node;
			next_node_list[i] = new_node;
		}

		phase_1.reserve(s);
		leader.resize(s + 1);
	}
	vector<node*>& getNodeList() {
		return node_list;
	}
	vector<int>& getLeader() {
		return leader;
	}
	int getResult() {
		return result;
	}
	void insertEdge(int from, int to) {
		// edge 삽입 메서드
		if (from != to) {
			node_list[from]->insertEdge(node_list[to]);
		}
	}
	void sortNextNodeList() {
		// next_node_list를 기준에 맞게 정렬
		sort(next_node_list.begin() + 1, next_node_list.end(), compare);
	}
	node* nextGraphDFSNode() {
		// phase 1용 메서드
		// 모든 그래프가 서로 reachable하지 않을 때, 어느 한쪽의 reachable한 node들을 모두 탐색하고 더 이상 재귀가 이루어지지 않을 때
		// 다음에 선택되어야 하는 node를 선택하는 메서드
		node* result = NULL;

		// node의 개수만큼의 반복문만으로 모든 stack의 node를 탐색하기 위해 current_idx를 이용
		for (int i = current_idx; i <= size; i++) {
			if (!visited[next_node_list[i]->getIndex()]) {
				result = next_node_list[i];
				current_idx = i + 1;
				break;
			}
		}
		return result;
	}
	void DFS() {
		while (cnt != size) {
			// 모든 node를 방문할 때까지 재귀
			DFS(nextGraphDFSNode());
		}

	}
	void DFS(node* n) {
		visited[n->getIndex()] = true;
		// 현재 node 방문 처리
		while (true) {
			node* next = n->nextDFSNode();
			// 다음 방문할 node 선택
			if (next == NULL) {
				// end condition
				// 결과 stack에 push 후 cnt 증가
				phase_1.push_back(n);
				cnt++;
				return;
			}

			DFS(next);
			// recursion
		}
	}
	void reverseDFS() {
		cnt = 0;
		// phase 1에서 갱신된 cnt 초기화
		current_idx = size - 1;
		// current_idx 초기화

		while (cnt != size) {
			// 모든 node를 방문할 때까지 재귀

			// phase 1에서 만들어진 stack을 역순으로 탐색
			// node의 개수만큼의 반복문만으로 모든 stack의 node를 탐색하기 위해 current_idx를 이용
			// 한 개의 scc를 찾은 뒤 while문을 다시 반복할 때, 이전의 결과에서 갱신된 current_idx를 재사용하기 때문에 node의 개수만큼만 반복문을 돌 수 있음
			for (int i = current_idx; i >= 0; i--) {
				if (visited[phase_1[i]->getIndex()]) {
					current_idx = i - 1;
					result++;
					reverseDFS(node_list[phase_1[i]->getIndex()], phase_1[i]->getIndex());
					// 현재 node의 index를 leader로 하여 DFS 수행
					break;
				}
			}
		}

	}
	void reverseDFS(node* n, int leader_index) {
		visited[n->getIndex()] = false;
		// 방문 처리
		// phase 1에서 모든 node의 visited를 true 설정하였기 때문에, 별도 초기화를 하지 않고 여기서는 false를 방문했다는 의미로 사용

		leader[n->getIndex()] = leader_index;
		// leader 갱신
		while (true) {
			node* next = n->nextReverseDFSNode();
			// 다음 방문할 node 선정
			if (next == NULL) {
				// end condition
				cnt++;
				return;
			}

			reverseDFS(next, leader_index);
			// recursion
		}
	}
};


void node::sortOutGoingEdges() {
	// node의 outgoing_edge_list를 정렬하는 메서드
	outgoing_edge_list.sort(compare);
	// current_outgoing_iter 초기화
	current_outgoing_iter = outgoing_edge_list.begin();
}

void node::sortInComingEdges() {
	// node의 incoming_edge_list를 정렬하는 메서드
	incoming_edge_list.sort(compare);
	// current_incoming_iter 초기화
	current_incoming_iter = incoming_edge_list.begin();
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, follower, followee;
	cin >> N >> M;

	// 1. create graph
	graph inhaStagram(N);

	// 2. create edges
	for (int i = 0; i < M; i++) {
		cin >> followee >> follower;

		inhaStagram.insertEdge(followee, follower);
	}

	// 3. sort next_node_list and edges
	inhaStagram.sortNextNodeList();
	for (int i = 1; i <= N; i++) {
		inhaStagram.getNodeList()[i]->sortInComingEdges();
		inhaStagram.getNodeList()[i]->sortOutGoingEdges();
	}

	// 4. phase 1
	inhaStagram.DFS();


	// 5. phase 2
	inhaStagram.reverseDFS();

	// 6. print result
	cout << inhaStagram.getResult() << '\n';
	int index = 1;
	while (index < inhaStagram.getLeader().size()) {
		bool flag = false;
		int current;
		for (int i = index; i < inhaStagram.getLeader().size(); i++) {
			if (!flag && !checked[inhaStagram.getLeader()[i]]) {
				index = i + 1;
				flag = true;
				checked[inhaStagram.getLeader()[i]] = true;
				current = inhaStagram.getLeader()[i];
				cout << i << ' ';
			}
			else if (flag && inhaStagram.getLeader()[i] == current) {
				cout << i << ' ';
			}
			
		}
		if (!flag) {
			break;
		}
		cout << "-1\n";
	}

}