//
//  rsaini.cpp
//  Lab14
//
//  Created by Ryan Saini on 12/5/20.
//

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

using namespace std;

class createNode{

public:
    int data;
    createNode* left;
    createNode* right;

    createNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

createNode* insert(createNode* node, int data);
createNode* huffman(vector<int> vect);
createNode* constructTree(createNode* Q, createNode* z);
bool tree(createNode* root, int route, int key);
void print(createNode* Q, int num, vector<int> vectCopy);
void nodesInit();

vector<createNode*> nodes;
string bits = "";

int main(){
    int num, input;
    vector<int> vect;
    vector<int> vectCopy;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> input;
        vect.push_back(input);
    }
    createNode* Q = NULL;
    nodesInit();
    vectCopy = vect;
    sort(vect.begin(), vect.end());
    Q = huffman(vect);
    print(Q, num, vectCopy);
 return 0;
}

createNode* insert(createNode* node, int data){
        if(node == NULL){
            node = new createNode(data);
        }
        else if(data < node->data){
            node->left = insert(node->left, data);
        }
        else if(data > node->data){
            node->right = insert(node->right, data);
        }
        return node;
    }

createNode* constructTree(createNode* Q, createNode* z){
    if(Q == NULL){
        Q = new createNode(z->data);
        Q->left = z->left;
        Q->right = z->right;
    }
    if(z->left->data == Q->data){
        z->left = Q;
        return z;
    }
    if(z->right->data == Q->data){
        z->right = Q;
        return z;
    }
    nodes.pop_back();
    nodes.push_back(z);
    return Q;

}

bool tree(createNode* root, int route, int key){
    if(root == NULL){
        return false;
    }
    if(route == 0){
        bits += "0";
    }
    else if(route == 1){
        bits += "1";
    }
    if(root->data == key){
        return true;
    }
    if (tree(root->left, 0, key) ||tree(root->right, 1, key)){
        return true;
    }
    bits.pop_back();
    return false;
}

createNode* huffman(vector<int> vect){
    createNode* Q = NULL;
    while(vect.size() > 1){
        createNode* z = NULL;
        z = insert(z, vect[0] + vect[1]);
        z->left = insert(z->left, vect[0]);
        z->right = insert(z->right, vect[1]);
        vect[0] = vect[0] + vect[1];
        vect.erase(vect.begin() + 1);
        sort(vect.begin(), vect.end());
        Q = constructTree(Q, z);
        Q = constructTree(Q, nodes[0]);
    }
    return Q;
}

void print(createNode* Q, int num, vector<int> vectCopy){
    for(int i = 0; i < num; i++){
        int key = vectCopy[i];
        if(tree(Q, -1, key)){
            for(int i = 0; i < bits.size(); i++){
                cout << bits[i];
            }
            cout << "" << "\n";
        }
        bits = "";
    }
}

void nodesInit(){
    createNode* Q = NULL;
    createNode* tempNode = NULL;
    tempNode = insert(tempNode, INT_MAX);
    tempNode->left = insert(tempNode->left, INT_MAX);
    tempNode->right = insert(tempNode->right, INT_MAX);
    nodes.push_back(tempNode);
}
