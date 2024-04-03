
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    Node *left, *right;
    Node(T val) {
        this->value = val; this->left = 0; this->right = 0;
    }
    Node(T val, Node<T> left, Node<T> right) {
        this->value = val; this->left = left; this->right = right;
    }
};

template <class T>
class BST {
    private:
    Node<T> *root;
    void addHelper(Node<T> *root, T val) {
        if (root->value > val) {
            if (!root->left) {
                root->left = new Node<T>(val);
            } else {
                addHelper(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new Node<T>(val);
            } else {
                addHelper(root->right, val);
            }
        }
    }
    void printHelper(Node<T> *root) {
        if (!root) return;
        cout<<root->value<<'\n';
        // cout<<("left\n");
        printHelper(root->left);
        // cout<<("right\n");
        printHelper(root->right);
    }
    public:
    void add(T val) {
        if (root) {
            this->addHelper(root, val);
        } else {
            root = new Node<T>(val);
        }
    }
    void print() {
        printHelper(this->root);
    }
};

int main() {
    BST<int> *bst = new BST<int>();
    bst->add(11);
    bst->add(1);
    bst->add(6);
    bst->add(-1);
    bst->add(-10);
    bst->add(100);
    bst->print();
    return 0;
}
