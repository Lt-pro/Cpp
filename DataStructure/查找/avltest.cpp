#include <iostream>
#include <algorithm>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

template <typename T>
class AVLTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;

        Node(const T& val) : data(val), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;
	int n;

    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(Node* node) {
        if (node != nullptr) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* insert(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            // Duplicate values not allowed
            return node;
        }

        updateHeight(node);

        int balance = getBalanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            if (value < node->left->data) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (value > node->right->data) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* node, const T& value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with only one child or no child
            if ((node->left == nullptr) || (node->right == nullptr)) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }

                delete temp;
            } else {
                // Node with two children
                Node* temp = minValueNode(node->right);

                node->data = temp->data;

                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr) {
            return node;
        }

        updateHeight(node);

        int balance = getBalanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

public:
    AVLTree() : root(nullptr), n(0) {}

    void insert(const T& value) {
        root = insert(root, value);
		n++;
    }

    void remove(const T& value) {
        root = deleteNode(root, value);
		n--;
    }

    void printInOrder() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
	
	int height(){
		return getHeight(root);
	}
	
	int size(){
		return n;
	}
};



const int MAX = 100000;
int main() {
	default_random_engine engine(time(nullptr));
	normal_distribution<double> normal;
	
    AVLTree<double> tree;
	double key = 0;
	double keys[MAX];

	cout <<"insert Ele"<<endl;
    for (int i=0;i<MAX;i++){
		keys[i] = normal(engine);
		tree.insert(keys[i]);
		cout <<"Ele "<<i+1<<":\t key = "<<fixed<<setprecision(5)<<keys[i]<<"\theight = "<<tree.height()<<"\tsize = "<<tree.size()<<endl;
	}

    //std::cout << "In-order traversal of AVL tree: ";
    //tree.printInOrder();
	
	cout <<"remove Ele"<<endl;
	for (int i=0;i<MAX;i++){
		tree.remove(keys[i]);
		cout <<"Ele "<<i+1<<":\t key = "<<fixed<<setprecision(5)<<keys[i]<<"\theight = "<<tree.height()<<"\tsize = "<<tree.size()<<endl;
	}

    //std::cout << "In-order traversal after removing 30: ";
    //tree.printInOrder();

    return 0;
}
