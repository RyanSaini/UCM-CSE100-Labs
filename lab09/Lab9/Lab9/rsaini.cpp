//
//  rsaini.cpp
//  Lab9
//
//  Created by Ryan Saini on 10/28/20.
//

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
vector<list<int> > insertKey(vector<list<int> > hash, int key, int size);
vector<list<int> > deleteKey(vector<list<int> > hash, int key, int size);
vector<list<int> > searchKey(vector<list<int> > hash, int key, int size);
void output(vector<list<int> > hash, int size);

int main(int argc, const char * argv[]) {
    
    int size = 0;
    int key = 0;
    char input;
    cin>>size;
    
    vector<list<int> > hash;
    
    for(int i = 0; i < size; i++){
        list<int> emptyList;
        hash.push_back(emptyList);
    }
    
    while(input != 'e'){
        cin>> input;
        if(input == 'i'){
            cin>>key;
            hash = insertKey(hash, key, size);
        }
        else if(input == 'd'){
            cin>>key;
            hash = deleteKey(hash, key, size);
        }
        else if(input == 's'){
            cin>>key;
            hash = searchKey(hash, key ,size);
        }
        else if(input == 'o'){
            output(hash, size);
        }
        
    }
}

vector<list<int> > insertKey(vector<list<int> > hash, int key, int size){
    hash[key%size].push_front(key);
    return hash;
}

vector<list<int> > deleteKey(vector<list<int> > hash, int key, int size){
    
    list<int> :: iterator it; //Variable pointer that 'iterates' through the list.
    it = find(hash[key%size].begin(), hash[key%size].end(), key);
    //set = to hash, search from begin and end looking for 'key'.
    
    if(it !=  hash[key%size].end()){
        hash[key%size].erase(it);
        cout<<key<<" : "<<"DELETED"<<"\n";
        cout << "++++++++++++++++++++" << endl;
    }
    else{
        cout<<key<<" : "<<"DELETE FAILED"<<"\n";
        cout << "++++++++++++++++++++" << endl;
    }
    
    return hash;
}

vector<list<int> > searchKey(vector<list<int> > hash, int key, int size){
    list<int> ::iterator it;
    it = find(hash[key%size].begin(), hash[key%size].end(), key);
    int difference = distance(hash[key%size].begin(), it);
    if(it !=hash[key%size].end()){
        
        cout<<key<<" : "<<"FOUND AT "<< key%size<< ","<< difference<<"\n";
        cout << "++++++++++++++++++++" << endl;
    }
    else{
        cout<<key<<" : "<<"NOT FOUND"<<"\n";
        cout << "++++++++++++++++++++" << endl;
    }
    return hash;
}

void output(vector<list<int> > hash, int size){
    //creating copy of lists so we don't alter the final production of it
    vector<list<int> > tempHash;
    tempHash = hash;
    
    for(int i = 0; i<size; i++){
        cout<<i<< " : ";
        for(int j = 0; j<hash[i].size(); j++){ //each list has different size
            if(j != hash[i].size()-1){
                cout<<tempHash[i].front()<< "->";
                tempHash[i].pop_front();
        }
            else{
                cout<<tempHash[i].front();
                tempHash[i].pop_front();
            }
    }
        cout<<"\n";
}
    cout << "++++++++++++++++++++" << endl;
}
