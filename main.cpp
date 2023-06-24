#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

int main() {
	int n;
	cin >> n;

	int m;
	cin >> m;

	Node* root = new Node{0, nullptr};

	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;

		if (b < 0) {
			Node* itr = root;
			while (itr->next != nullptr) {
				if (b < itr->next->data) {
					itr->next = new Node{b, itr->next};
					goto exit;
				}
				itr = itr->next;
			}
			itr->next = new Node{b, itr->next};
			exit:;
		}
	}

	int sum = 0;
	root = root->next;
	while (root != nullptr) {
		sum += root->data;
		if(--m == 0) break;
		root = root->next;
	}
	cout << -sum;
}
