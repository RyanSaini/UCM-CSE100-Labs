//
//  rsaini.cpp
//  Lab11
//
//  Created by Ryan Saini on 11/9/20.
//

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>
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

createNode* insert(createNode *node, int key);
createNode* deleteNode(createNode *node, int key);
createNode* nodeSuc(createNode *node);
void preOrder(createNode *node);
void postOrder(createNode *node);
void inOrder(createNode *node);

int main(int argc, const char * argv[]) {
    
    createNode *node = NULL;
    
    int key = 0;
    string input;
    
    while(input != "e"){
        cin>> input;
        if(input == "i"){
            cin>>key;
            node = insert(node, key);
        }
        else if(input ==  "d"){
            cin>>key;
            node = deleteNode(node, key);
        }
        else if(input == "pre"){
            preOrder(node);
            cout<<"++++++++++++++++++++"<<endl;
        }
        else if(input == "post"){
            postOrder(node);
            cout<<"++++++++++++++++++++"<<endl;
        }
        else if(input == "in"){
            inOrder(node);
            cout<<"++++++++++++++++++++"<<endl;
        }
        
    }
    
}

createNode* insert(createNode *node, int key){
    
    if(node == NULL){
        node = new createNode(key);
    }
    
    else if(key < node->data){
        node->left = insert(node->left, key);
    }
    else if(key > node->data){
        node->right = insert(node->right, key);
    }
    return node;
}

createNode* deleteNode(createNode *node, int key){
    
    if(node  == NULL){
        return node;
    }
    
    else if(key < node->data){
        node->left = deleteNode(node->left, key);
    }
    
    else if(key > node->data){
        node->right = deleteNode(node->right, key);
    }
    
    else if(key == node ->data){
        
        if(node->left == NULL){
            createNode* tempNode = node ->right;
            delete node;
            return tempNode;
        }
        
        else if(node->right == NULL){
            createNode* tempNode = node ->left;
            delete node;
            return tempNode;
        }
        
        createNode* finishNode = nodeSuc(node->right);
        node->data = finishNode -> data;
        node->right = deleteNode(node->right, finishNode->data);
        
    }
        
        
    return node;
}

createNode* nodeSuc(createNode *node){
    createNode* newNode = node;
    while(newNode -> left  && newNode != NULL){
        newNode = newNode->left;
    }
    return newNode;
}

void inOrder(createNode *node){
    if(node!=NULL){
        inOrder(node->left);
        cout<< node->data<<endl;
        inOrder(node->right);
    }
}

void preOrder(createNode *node){
    if(node!=NULL){
        cout<<node->data<<endl;
        preOrder(node->left);
        preOrder(node->right);
        
    }
}

void postOrder(createNode *node){
    if(node!=NULL){
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->data<<endl;
    }
}
