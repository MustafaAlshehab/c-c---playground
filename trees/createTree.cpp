// we will be using a queue to create a binary tree.

#include <queue>
#include <iostream>

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
    void preOreder(Node *p);
    void postOrder();
    void inOrder();
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
        if (value != -1) {
            temp = new Node;
            temp->data = value;
            temp->leftChild = temp->rightChild = 0;
            ptr->leftChild = temp;
            q.push(temp);
        }

        std::cout << "Enter a value for rightChild of the node with value " << ptr->data << '\n';
        std::cin >> value;
        if (value != -1) {
            temp = new Node;
            temp->data = value;
            temp->leftChild = temp->rightChild = 0;
            ptr->rightChild = temp;
            q.push(temp);
        }
    }
}

void Tree::preOreder(Node *p) {
    if(p != nullptr) {
        std::cout << p->data << " ";
        preOreder(p->leftChild);
        preOreder(p->rightChild);
    }
}

int main() {
    Tree test;
    test.createTree();
    test.preOreder(test.getRootNode());

    return 0;
}