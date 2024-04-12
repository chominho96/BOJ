#include <iostream>
#include <vector>

using namespace std;

class Node {
	int key;
	Node* next;

public:
	Node(int k = 0) : key(k), next(NULL){
		
	}
	int getKey() {
		return key;
	}
	Node* getNext() {
		return next;
	}
	void setNext(Node* node) {
		next = node;
	}
	Node* deleteNext() {
		if (next == NULL) {
			return NULL;
		}
		next = next->next;
		return next;
	}
};

class LinkedList {
	Node* head;
	int size;
public:
	LinkedList() : head(NULL), size(0) {
		
	}
	~LinkedList() {
		if (!isEmpty()) {
			Node* p = head;
			while (p != NULL) {
				delete p->deleteNext();
			}
			delete p;
		}
		
	}
	bool isEmpty() {
		return size == 0;
	}
	int getSize() {
		return size;
	}
	Node* getHead() {
		return head;
	}
	void push(Node* node) {
		if (isEmpty()) {
			head = node;
			size++;
		}
		else {
			Node* p = head;
			while (p->getNext() != NULL) {
				p = p->getNext();
			}
			p->setNext(node);
			size++;
		}
	}
};



int main() {
	LinkedList* arr = new LinkedList[1001];		// not use index 0
	

	int test_num;
	int time;
	int current_time = 0;
	int result = 0;

	vector<int> result_vec;

	cin >> test_num;

	for (int count = 0; count < test_num; count++) {
		cin >> time;
		arr[time].push(new Node(time));
	}

	for (int index = 1; index < 1001; index++) {
		Node* p = arr[index].getHead();
		while (p != NULL) {

			current_time += p->getKey();
			result_vec.push_back(current_time);

			p = p->getNext();
		}
	}
	
	for (int index = 0; index < result_vec.size(); index++) {
		result += result_vec[index];
	}

	cout << result << endl;
}