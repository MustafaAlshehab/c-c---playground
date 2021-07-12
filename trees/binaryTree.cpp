// we will be using a queue to create a binary tree.

#include <queue>
#include <iostream>
#include <stack>

constexpr const int noNewNode = -1;

class Tree 
{

private:
    struct Node
    {
        Node * leftChild, * rightChild;
        int data;
    };

    Node *root;

public:
    Tree() {
        root = nullptr;
    }
    void createTree();
    void preOrder(Node *p);
    void preOrderIterative(Node *p);
    void postOrder(Node *p);
    void inOrder(Node *p);
    void levelOrder();
    void height(Node *root);
    Node * getRootNode() {
        return root;
    }
};

void Tree::createTree() {
    Node *ptr, *temp;
    int value;
    std::queue<Node *> q;

    std::cout << "Enter a value for root node " << '\n';
    std::cin >> value;
    
    root = new Node;
    root->data = value;
    root->leftChild = root->rightChild = 0;
    q.push(root);

    while (q.size() > 0) 
    {
        ptr = q.front();
        q.pop();
        std::cout << "Enter a value for leftChild of the node with value " << ptr->data << '\n';
        std::cin >> value;
        if (value != noNewNode) {
            temp = new Node;
            temp->data = value;
            temp->leftChild = temp->rightChild = 0;
            ptr->leftChild = temp;
            q.push(temp);
        }

        std::cout << "Enter a value for rightChild of the node with value " << ptr->data << '\n';
        std::cin >> value;
        if (value != noNewNode) {
            temp = new Node;
            temp->data = value;
            temp->leftChild = temp->rightChild = 0;
            ptr->rightChild = temp;
            q.push(temp);
        }
    }
}

// Time complexity (2*n + 1) => O(n)
// Space complexity (hight of a tree + 2) min of O(log n) max of O(n)
// where n is number of nodes, in skewed tree space complexity will be at most
void Tree::preOrder(Node *p) {
    if(p != nullptr) {
        std::cout << p->data << ' ';
        preOrder(p->leftChild);
        preOrder(p->rightChild);
    }
}

// Time complexity (2*n + 1) => O(n)
// Space complexity (hight of a tree + 2) min of O(log n) max of O(n)
// where n is number of nodes, in skewed tree space complexity will be at most
void Tree::inOrder(Node *p) {
    if(p != nullptr) {
        inOrder(p->leftChild);
        std::cout << p->data << ' ';
        inOrder(p->rightChild);
    }
}

// Time complexity (2*n + 1) => O(n)
// Space complexity (hight of a tree + 2) min of O(log n) max of O(n)
// where n is number of nodes, in skewed tree space complexity will be at most
void Tree::postOrder(Node *p) {
    if(p != nullptr) {
        postOrder(p->leftChild);
        postOrder(p->rightChild);
        std::cout << p->data << ' ';        
    }
}

// Time complexity (2*n) => O(n)
// Space complexity, stack max will be hight of the tree + 1 => O(h)
// where h is the hight of the tree
void Tree::preOrderIterative(Node *p) {
    std::stack<Node *> st;

    while (p || !st.empty()) {
        if(p) {
            std::cout << p->data << ' ';
            st.push(p);
            p = p->leftChild;
        } else {
            p = st.top();
            st.pop();
            p = p->rightChild;
        }
    }
}

int main() {
    Tree test;
    test.createTree();
    std::cout << "Pre Order: ";
    test.preOrder(test.getRootNode());
    std::cout << '\n' << "Pre Order (iterative): ";
    test.preOrderIterative(test.getRootNode());
    std::cout << '\n' << "In Order: ";
    test.inOrder(test.getRootNode());
    std::cout << '\n' << "Post Order: ";
    test.postOrder(test.getRootNode());
    std::cout << '\n';

    return 0;
}