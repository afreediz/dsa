#include<iostream>
using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    Node(int key) : value(key), left(nullptr), right(nullptr) {};
}

Node *insert(Node *root, int key){
    if(root == nullptr){
        return new Node(key);
    }else{
        if(root->key > key){
            root->left = insert(root->left, key);
        }else if(root->key < key){
            root->right = insert(root->right, key);
        }
    }
}