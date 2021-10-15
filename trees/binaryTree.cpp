// we will be using a queue to create a binary tree.

#include <queue>
#include <iostream>
#include <stack>
#include <array>

constexpr const int noNewNode = -1;


class Node {
public:
    Node * leftChild, * rightChild;
    int data;

    Node();
    Node(int data);
};

Node::Node() {};

Node::Node(int data) {
    leftChild = rightChild = nullptr;
    this->data = data;
}
class Tree 
{

private:
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
    void postOrderIterative2(Node *p);
    void levelOrder(Node *p);
    void height(Node *root);
    Node * buildTreeFromTraversal(int inOrder[], int preOrder[], int inOrderStart, int inOrderEnd);
    int helper(int inOrder[],int inOrderStart, int inOrderEnd, int data);
    Node * getRootNode() {
        return root;
    }
    void setRoot(Node *root) {
        this->root = root;
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
void Tree::postOrderIterative2(Node *p) {
    if(!p) {
        return;
    }
    
    std::stack<Node *> resultSt;
    std::stack<Node *> st;

    st.push(p);
    
    while(!st.empty()) {
        Node *temp = st.top();
        st.pop();
        resultSt.push(temp);
        if(temp->leftChild) {
            st.push(temp->leftChild);
        }
        if(temp->rightChild) {
            st.push(temp->rightChild);
        }
    }
    
    while(!resultSt.empty()) {
        std::cout << resultSt.top()->data << ' ';
        resultSt.pop();
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

// Time complexity O(n^2), where n here is number of nodes
// Space complexity O(n), depens on the hight of a tree
// resources:
// https://algorithms.tutorialhorizon.com/make-a-binary-tree-from-given-inorder-and-preorder-traveral/
// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
Node * Tree::buildTreeFromTraversal(int inOrder[], int preOrder[], int inOrderStart, int inOrderEnd) {
    static int preOrderIndex = 0;

    if (inOrderStart > inOrderEnd) {
        return nullptr;
    }

    Node * p = new Node(preOrder[preOrderIndex++]);

    if (inOrderStart == inOrderEnd) {
        return p;
    }

    int splitIndex = helper(inOrder,inOrderStart,inOrderEnd,p->data);
    p->leftChild = buildTreeFromTraversal(inOrder, preOrder, inOrderStart, splitIndex-1);
    p->rightChild = buildTreeFromTraversal(inOrder,preOrder,splitIndex+1,inOrderEnd);

    return p;
}

int Tree::helper(int inOrder[],int inOrderStart, int inOrderEnd, int data) {
    for(int i = inOrderStart; i <= inOrderEnd; i++) {
        if (inOrder[i] == data) {
            return i;
        }
    }

    return -1;
}

int main() {
    Tree t1;
    t1.createTree();
    std::cout << "Tree 1: Pre Order: ";
    t1.preOrder(t1.getRootNode());
    std::cout << '\n' << "Tree 1: Pre Order (iterative): ";
    t1.preOrderIterative(t1.getRootNode());
    std::cout << '\n' << "Tree 1: In Order: ";
    t1.inOrder(t1.getRootNode());
    std::cout << '\n' << "Tree 1: In Order (iterative): ";
    t1.inOrderIterative(t1.getRootNode());
    std::cout << '\n' << "Tree 1: Post Order: ";
    t1.postOrder(t1.getRootNode());
    std::cout << '\n' << "Tree 1: Post Order (iterative): ";
    t1.postOrderIterative(t1.getRootNode());
    std::cout << '\n' << "Tree 1: Post Order (iterative2): ";
    t1.postOrderIterative2(t1.getRootNode());
    std::cout << '\n' << "Tree 1: Level Order (iterative): ";
    t1.levelOrder(t1.getRootNode());

    int preOrder[] = {1,2,3,4,5,6,7};
    int inOrder[] = {3,2,4,1,6,5,7};
    int inOrderSize = sizeof(inOrder) / sizeof(inOrder[0]) - 1;
    Tree t2;
    Node * root = t2.buildTreeFromTraversal(inOrder,preOrder,0,inOrderSize);
    t2.setRoot(root);
    std::cout << '\n' << "Tree 2: Pre Order: ";
    t2.preOrder(t2.getRootNode());
    std::cout << '\n';

    return 0;
}