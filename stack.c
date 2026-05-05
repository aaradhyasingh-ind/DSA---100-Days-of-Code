#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// traversal

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

#include <queue>

Node* insert(Node* root, int value) {
    Node* newNode = new Node(value);

    if (root == nullptr)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = newNode;
            return root;
        } else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = newNode;
            return root;
        } else {
            q.push(temp->right);
        }
    }
 
    
    void deleteDeepest(Node* root, Node* delNode) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) {
            if (temp->left == delNode) {
                temp->left = nullptr;
                delete delNode;
                return;
            } else {
                q.push(temp->left);
            }
        }

        if (temp->right) {
            if (temp->right == delNode) {
                temp->right = nullptr;
                delete delNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (root->left == nullptr && root->right == nullptr) {
        if (root->data == key) {
            delete root;
            return nullptr;
        } else {
            return root;
        }
    }


    queue<Node*> q;
    q.push(root);

    Node* keyNode = nullptr;
    Node* temp = nullptr;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            keyNode = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (keyNode != nullptr) {
        int x = temp->data;   // deepest rightmost node data
        deleteDeepest(root, temp);
        keyNode->data = x;
    }

    return root;
}

void deleteDeepest(Node* root, Node* delNode) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) {
            if (temp->left == delNode) {
                temp->left = nullptr;
                delete delNode;
                return;
            } else {
                q.push(temp->left);
            }
        }

        if (temp->right) {
            if (temp->right == delNode) {
                temp->right = nullptr;
                delete delNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (root->left == nullptr && root->right == nullptr) {
        if (root->data == key) {
            delete root;
            return nullptr;
        } else {
            return root;
        }
    }

    queue<Node*> q;
    q.push(root);

    Node* keyNode = nullptr;
    Node* temp = nullptr;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            keyNode = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (keyNode != nullptr) {
        int x = temp->data;   // deepest rightmost node data
        deleteDeepest(root, temp);
        keyNode->data = x;
    }

    return root;
}