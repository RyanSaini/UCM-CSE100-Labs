//
//  rsaini.cpp
//  Lab10
//
//  Created by Ryan Saini on 11/2/20.
//

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
int h1(int key);
int h2(int key);
void insert(int *arr);
void search(int *arr);
void deleteOp(int *arr);
void print(int *arr);

int main(int argc, const char * argv[]) {
    
    int size = 13;
    int *arr = new int[size];
    
    for(int i = 0; i<size; i++){
        arr[i] = -1;
    }
    
    insert(arr);
    print(arr);
    search(arr);
    deleteOp(arr);
    print(arr);
}

int h1(int key){
    
    return key % 13;
}

int h2(int key){
    
    return 1 + (key % 11);
}

void insert(int *arr){
    
    int input = 0;
    int counter = 0;
    int i =1;
    
    while(true){
        i = 1;
        cin>>input;
        if(input != -1){
            counter++;
            if(counter<=13){
                if(arr[h1(input)] ==-1){
                    arr[h1(input)] = input;
                }
                else {
                    do {
                        if(arr[(h1(input) + i * h2(input)) % 13] == -1){
                            arr[(h1(input) + i * h2(input)) % 13] = input;
                            break;
                        }
                        i++;
                    }
                    while (true);
                }
            }
        }
            
        else{
            break;
        }
        
    }
    
}

void search(int *arr){
    int input = 0;
    cout<<"++++searching++++"<<"\n";
    
    while(true){
        cin>> input;
        if(input != -2){
            for(int i=0; i<=13; i++){
                if(arr[(h1(input) + i * h2(input)) % 13] == input){
                    cout<<(h1(input) + i * h2(input)) % 13<<"\n";
                    break;
                }
                else if(i==13){
                    cout<<"NOT_FOUND"<<"\n";
                }
                    
            }
        }
        
        
        else{
            break;
        }
    }
}

void deleteOp(int *arr){
    int input = 0;
    cout<<"++++deleting++++"<<"\n";
    
    while(true){
        cin>> input;
        if(input != -3){
            for(int i=0; i<=13; i++){
                if(arr[(h1(input) + i * h2(input)) % 13] == input){
                    arr[(h1(input) + i * h2(input)) % 13] = -1;
                    break;
                }
                    
            }
        }
        
        
        else{
            break;
        }
    }
}

void print(int *arr){
    cout<<"++++table printout++++"<<"\n";
    for(int i = 0; i<13; i++){
        
        if(arr[i]!=-1){
        cout<<arr[i]<<"\n";
        }
        else{
            cout<<"\n";
        }
    }
}

    
