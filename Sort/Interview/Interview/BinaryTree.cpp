#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

Node* constructBTree(vector<int> arr, int index) {
	if ((index >= arr.size()) || (arr[index] < 0)) {
		//std::cout << "index:" << index << " arr.size:" << arr.size() << endl;
 		return NULL;
	}
	//std::cout << "new node, index:" << index << " data:" << arr[index] << endl;
	Node *root = new Node();
	if (NULL == root) {
		return NULL;
	}

	root->data = arr[index];
	std::cout << "add data " << root->data << endl;
	root->left = constructBTree(arr, 2*index + 1);
	root->right = constructBTree(arr, 2*index + 2);
	return root;
}

void destructBTree(Node* root) {
	if (NULL == root) {
		return;
	}
	if (NULL != root->left) {
		destructBTree(root->left);
	}
	if (NULL != root->right) {
		destructBTree(root->right);
	}
	delete root;
	root = NULL;
}
void depthFirstSearch(Node *root) {
	if (NULL == root) {
		return;
	}
	cout << root->data << endl;
	depthFirstSearch(root->left);
	depthFirstSearch(root->right);
}

void output(vector<int>& arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void rand_vec(vector<int>& arr, int size = 10, int low = 0, int high = 100) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		arr.push_back((rand() % (high - low + 1)) + low);
	}
}

int main(int argc, char** argv) {
	vector<int> arr;
	for (int i = 0; i < 1; i++) {
		arr.clear();
		rand_vec(arr);
		std::cout << i << " original vector:" << std::endl;
		output(arr);
		Node* root = constructBTree(arr, 0);
		std::cout << "root is" << root << endl;
		depthFirstSearch(root);
		std::cout << "-------------------------" << std::endl;
		destructBTree(root);

	}
	system("pause");
	return 0;
}