#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

class NODE {
private:
    int value;
    NODE* left;
    NODE* right;
    NODE* parent;
public:
    NODE(int v, NODE* p) {
        value = v;
        left = NULL;
        right = NULL;
        parent = p;
    }
    NODE* getLeft() {
        return left;
    }
    NODE* getRight() {
        return right;
    }
    NODE* setLeft(NODE* node) {
        return left = node;
    }
    NODE* setRight(NODE* node) {
        return right = node;
    }
    NODE* getParent() {
        return parent;
    }
    int getValue() {
        return value;
    }
};

void postOrder(NODE* node) {
    if (node == NULL) return;
    postOrder(node->getLeft());
    postOrder(node->getRight());
    cout << node->getValue() << '\n';
}

NODE* insert(NODE* prev, int curr) {
    if (prev->getValue() > curr) {
        return prev->setLeft(new NODE(curr, prev));
    }
    else {
        while (true) {
            if (prev->getParent() == NULL || prev->getParent()->getValue() > curr) break;
            prev = prev->getParent();
        }
        while (prev->getRight() != NULL) {
            prev = prev->getRight();
        }
        return prev->setRight(new NODE(curr, prev));
    }
}

int main() {
    FASTIO
    int h; cin >> h;
    NODE* head = new NODE(h, NULL);
    NODE* prev = head;
    while (true) {
        int curr; cin >> curr;
        if (cin.eof()) break;
        prev = insert(prev, curr);
    }
    postOrder(head);
}