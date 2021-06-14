//
//  rsaini.cpp
//  Lab14
//
//  Created by Ryan Saini on 12/5/20.
//

#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <algorithm>


using namespace std;
class createNode{
public:
    int m_data;
    createNode* left;
    createNode* right;
    
    createNode(int data){
        this->m_data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void huffman(int size, vector<int> vec, vector<int> order);
createNode* insert(createNode *node, int key);
createNode* tree(createNode* Q, createNode* z);
bool bitCheck(createNode* root, int route, int key);

string bits = "";
vector<createNode*> globalNode;

int main(int argc, const char * argv[]) {
    
    int size = 0;
    int input = 0;
    vector<int> vec;
    vector<int> order;
    
    cin>>size;
    
    for(int i=0; i<size; i++){
        cin>>input;
        vec.push_back(input);
    }
    createNode* tempNode = NULL;
    tempNode = insert(tempNode, INT_MAX);
    tempNode->left = insert(tempNode->left, INT_MAX);
    tempNode->right = insert(tempNode->right, INT_MAX);
    globalNode.push_back(tempNode);
    
    
    order = vec;
    
    sort(vec.begin(), vec.end());
    
    huffman(size, vec, order);
}

createNode* insert(createNode *node, int key){
    
    if(node == NULL){
        node = new createNode(key);
    }
    
    else if(key < node->m_data){
        node->left = insert(node->left, key);
    }
    else if(key > node->m_data){
        node->right = insert(node->right, key);
    }
    return node;
}

void huffman(int size, vector<int> vec, vector<int> order){
    createNode* Q = NULL;
    while(vec.size()!=1){
        createNode* z = NULL;
        z = insert(z, vec[0] + vec[1]);
        z->left = insert(z->left, vec[0]);
        z->right = insert(z->right, vec[1]);
        vec[0] = vec[0] + vec[1];
        vec.erase(vec.begin() + 1);
        sort(vec.begin(), vec.end());
        Q = tree(Q,z);
        Q = tree(Q, globalNode[0]);
        
    }
    
    
    
    for(int i = 0; i < size; i++){
        int key = order[i];
        if(bitCheck(Q, -1, key)){
            for(int i = 0; i < bits.size(); i++){
                cout << bits[i];
            }
            cout << "" << endl;
        }
        bits = "";
    }
}

createNode* tree(createNode* Q, createNode* z){
    if(Q == NULL){
        Q = new createNode(z->m_data);
        Q->left = z->left;
        Q->right = z->right;
    }
    if(Q->left->m_data == z->m_data){
        Q->left = z;
        return Q;
    }
    if(Q->right->m_data == z->m_data){
        Q->right = z;
        return Q;
    }
    if(z->left->m_data == Q->m_data){
        z->left = Q;
        return z;
    }
    if(z->right->m_data == Q->m_data){
        z->right = Q;
        return z;
    }
    globalNode.pop_back();
    globalNode.push_back(z);
    return Q;

}

bool bitCheck(createNode* root, int route, int key){
    if(root == NULL){
        return false;
    }
    if(route == 0){
        bits += "0";
    }
    else if(route == 1){
        bits += "1";
    }
    if(root->m_data == key){
        return true;
    }
    if (bitCheck(root->left, 0, key) || bitCheck(root->right, 1, key)){
        return true;
    }
    bits.pop_back();
    return false;
}

