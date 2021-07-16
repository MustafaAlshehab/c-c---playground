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

    ~Tree() {
        std::queue<Node *> q;
        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            Node * temp = q.front();
            if(temp->leftChild) {
                q.push(temp->leftChild);
            }
            if(temp->rightChild) {
                q.push(temp->rightChild);
            }
            delete temp;
            q.pop();
        }
    }
    void createTree();
    void preOrder(Node *p);
    void preOrderIterative(Node *p);
    void inOrder(Node *p);
    void inOrderIterative(Node *p);
    void postOrder(Node *p);
    void postOrderIterative(Node *p);
    void levelOrder(Node *p);
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

// Time complexity (2*n + 1) => O(n), where n here is number of nodes
// Space complexity (hight of a tree + 2) min of O(log n) max of O(n)
// where n is number of nodes, in skewed tree space complexity will be at most
void Tree::preOrder(Node *p) {
    if(p != nullptr) {
        std::cout << p->data << ' ';
        preOrder(p->leftChild);
        preOrder(p->rightChild);
    }
}

// Time complexity (2*n + 1) => O(n), where n here is number of nodes
// Space complexity (hight of a tree + 2) min of O(log n) max of O(n)
// where n is number of nodes, in skewed tree space complexity will be at most
void Tree::inOrder(Node *p) {
    if(p != nullptr) {
        inOrder(p->leftChild);
        std::cout << p->data << ' ';
        inOrder(p->rightChild);
    }
}

// Time complexity (2*n + 1) => O(n), where n here is number of nodes
// Space complexity (hight of a tree + 2) min of O(log n) max of O(n)
// where n is number of nodes, in skewed tree space complexity will be at most
void Tree::postOrder(Node *p) {
    if(p != nullptr) {
        postOrder(p->leftChild);
        postOrder(p->rightChild);
        std::cout << p->data << ' ';        
    }
}

// Time complexity (2*n) => O(n), where n here is number of nodes
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

// Time complexity (2*n) => O(n), where n here is number of nodes
// Space complexity, stack max will be hight of the tree + 1 => O(h)
// where h is the hight of the tree
void Tree::inOrderIterative(Node *p) {
    std::stack<Node *> st;

    while (p || !st.empty()) {
        if(p) {
            st.push(p);
            p = p->leftChild;
        } else {
            p = st.top();
            st.pop();
            std::cout << p->data << ' ';
            p = p->rightChild;
        }
    }
}

// Time complexity (2*n) => O(n), where n here is number of nodes
// Space complexity, stack max will be hight of the tree + 1 => O(n)
// where n is the hight of the tree
void Tree::postOrderIterative(Node *p) {
    std::stack<Node *> st;
    Node * lastPrinted = nullptr;
    while (p || !st.empty()) {
        if(p) {
            st.push(p);
            p = p->leftChild;
        } else {
            Node * temp = st.top();
            if (temp->rightChild && temp->rightChild != lastPrinted) {
                p = temp->rightChild;
            } else {
                std::cout << temp->data << ' ';
                lastPrinted = temp;
                st.pop();
            }
        }
    }
}
// Time complexity of O(n)
// Space complexity of O(n)
void Tree::levelOrder(Node *p) {
    std::queue<Node *> q;
    if(p) {
        q.push(p);
    }
    while(!q.empty()) {
        Node *temp = q.front();
        if(temp->leftChild) {
            q.push(temp->leftChild);
        }
        if(temp->rightChild) {
            q.push(temp->rightChild);
        }
        std::cout << temp->data << ' ';
        q.pop();
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
    std::cout << '\n' << "In Order (iterative): ";
    test.inOrderIterative(test.getRootNode());
    std::cout << '\n' << "Post Order: ";
    test.postOrder(test.getRootNode());
    std::cout << '\n' << "Post Order (iterative): ";
    test.postOrderIterative(test.getRootNode());
    std::cout << '\n' << "Level Order (iterative): ";
    test.levelOrder(test.getRootNode());
    std::cout << '\n';

    return 0;
}