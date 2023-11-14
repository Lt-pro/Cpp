#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

const static int MAX_VALUE = 1000;
// TreeNode
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val0 = 0):val(val0), left(nullptr), right(nullptr){}
	TreeNode(int val0, TreeNode* left0, TreeNode* right0):val(val0), left(left0), right(right0){}
};

TreeNode* createBinaryTree(vector<int>& values, int i = 0);
TreeNode* generateBinaryTree(int n);
void destoryBinaryTree(TreeNode* root);
void printBinaryTree(TreeNode* root);
void preOrderRecursive(TreeNode* root, vector<int>& result);
void inOrderRecursive(TreeNode* root, vector<int>& result);
void postOrderRecursive(TreeNode* root, vector<int>& result);
void preOrder(TreeNode* root, vector<int>& result);
void inOrder(TreeNode* root, vector<int>& result);
void postOrder(TreeNode* root, vector<int>& result);
void levelOrder(TreeNode* root, vector<int>& result);


int main() {
	
	// BinaryTree generation ans destorision
	int n = 15;
	TreeNode *root = generateBinaryTree(n);
	printBinaryTree(root);
	cout<<endl;
	
	
	// Recursion iterator
	vector<int> ans;
	cout<<"preOrderRecursive: "<<endl;
	ans.clear();
	preOrderRecursive(root, ans);
	for (int& e: ans) cout<<e<<" ";
	cout<<endl;
	
	cout<<"inOrderRecursive: "<<endl;
	ans.clear();
	inOrderRecursive(root, ans);
	for (int& e: ans) cout<<e<<" ";
	cout<<endl;
	
	cout<<"postOrderRecursive: "<<endl;
	ans.clear();
	postOrderRecursive(root, ans);
	for (int& e: ans) cout<<e<<" ";
	cout<<endl;
	
	// NRecursion iterator
	cout<<"preOrder: "<<endl;
	ans.clear();
	preOrder(root, ans);
	for (int& e: ans) cout<<e<<" ";
	cout<<endl;
	
	cout<<"inOrder: "<<endl;
	ans.clear();
	inOrder(root, ans);
	for (int& e: ans) cout<<e<<" ";
	cout<<endl;
	
	cout<<"postOrder: "<<endl;
	ans.clear();
	postOrder(root, ans);
	for (int& e: ans) cout<<e<<" ";
	cout<<endl;
	
	// LevelOrder
	cout<<"levelOrder: "<<endl;
	ans.clear();
	levelOrder(root, ans);
	for (int& e: ans) cout<<e<<" ";
	cout<<endl;
	

	destoryBinaryTree(root);
	
	return 0;
}

TreeNode* createBinaryTree(vector<int>& values, int i) {
	if (i >= values.size()) {
		return nullptr;
	}
	TreeNode* b = new TreeNode(values[i]);
	b->left = createBinaryTree(values, 2 * i + 1);
	b->right = createBinaryTree(values, 2 * i + 2);
	return b;
}

TreeNode* generateBinaryTree(int n) {
	srand((unsigned)time(NULL));
	vector<int> values(n, 0);
	for (int i=0; i<n; i++) {
		values[i] = rand() / MAX_VALUE;
	}
	return createBinaryTree(values, 0);
}

void destoryBinaryTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	
	destoryBinaryTree(root->left);
	destoryBinaryTree(root->right);
	delete root;
}

void printBinaryTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	
	cout<<root->val<<" ";
	printBinaryTree(root->left);
	printBinaryTree(root->right);
}

void preOrderRecursive(TreeNode* root, vector<int>& result) {
	if (root == nullptr) {
		return;
	}
	
	result.push_back(root->val);
	preOrderRecursive(root->left, result);
	preOrderRecursive(root->right, result);
}

void inOrderRecursive(TreeNode* root, vector<int>& result) {
	if (root == nullptr) {
		return;
	}
	
	inOrderRecursive(root->left, result);
	result.push_back(root->val);
	inOrderRecursive(root->right, result);
}

void postOrderRecursive(TreeNode* root, vector<int>& result) {
	if (root == nullptr) {
		return;
	}
	
	postOrderRecursive(root->left, result);
	postOrderRecursive(root->right, result);
	result.push_back(root->val);
}

void preOrder(TreeNode* root, vector<int>& result) {
	if (root == nullptr) {
		return;
	}
	
	vector<TreeNode*> st;
	TreeNode *p = root;
	while (!st.empty() || p != nullptr) {
		while (p != nullptr) {
			result.push_back(p->val);
			st.push_back(p);
			p = p->left;
		}
		if (!st.empty()) {
			p = st.back();
			st.pop_back();
			p = p->right;
		}
	}
}

void inOrder(TreeNode* root, vector<int>& result) {
	if (root == nullptr) {
		return;
	}
	
	vector<TreeNode*> st;
	TreeNode *p = root;
	while (!st.empty() || p != nullptr) {
		while (p != nullptr) {
			st.push_back(p);
			p = p->left;
		}
		if (!st.empty()) {
			p = st.back();
			st.pop_back();
			result.push_back(p->val);
			p = p->right;
		}
	}
}

void postOrder(TreeNode* root, vector<int>& result) {
	if (root == nullptr) {
		return;
	}
	
	vector<TreeNode*> st;
	TreeNode *p = root;
	do {
		while (p != nullptr) {
			st.push_back(p);
			p = p->left;
		}
		bool flag = true;
		TreeNode *r = nullptr;
		
		while (!st.empty() && flag) {
			p = st.back();
			if (p->right == r) {
				result.push_back(p->val);
				st.pop_back();
				r = p;
			} else {
				p = p->right;
				flag = false;
			}
		}
	} while(!st.empty());
}

// 一种广度优先搜索的改进方法，可以逐层输出元素
void levelOrder(TreeNode* root, vector<int>& result) {
	if (root == nullptr) {
		return;
	}
	
	queue<TreeNode*> qu;
	qu.push(root);
	while (!qu.empty()) {
		int currentSize = qu.size();
		for (int i=0; i<currentSize; ++i) {
			TreeNode *p = qu.front();
			qu.pop();
			result.push_back(p->val);
			if (p->left != nullptr) {
				qu.push(p->left);
			}
			if (p->right != nullptr) {
				qu.push(p->right);
			}
		}
	}
}
