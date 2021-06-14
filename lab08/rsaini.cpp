//
//  rsaini.cpp
//  Lab8
//
//  Created by Ryan Saini on 10/21/20.
//

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
void bucketSort(float *arr, int size);

int main(int argc, const char * argv[]) {
    
    int size = 0;
    cin>>size;
    float *arr = new float[size];
    
    int i;
    float floatInput = 0;
    for(i=0;i<size;i++){
        cin>> floatInput;
        arr[i] = floatInput;
    }
    
    bucketSort(arr, size);
}
void bucketSort(float *arr, int size){
    vector<list<float> > sortV;
    
    for(int i = 0; i < size; i++){
        list<float> emptyList;
        sortV.push_back(emptyList);
    }
    
    for(int i = 0; i < size; i++){
        sortV[trunc(size*arr[i])].push_front(arr[i]);
    }
    
    for(int i = 0; i < size; i++){
        sortV[i].sort();
    }
    for(int i = 0; i < size; i++){
        int listSize = sortV[i].size();
        for(int j = 0; j < listSize; j++){
            cout<<sortV[i].front();
            sortV[i].pop_front();
            cout<<"\n";
        }
    }
    
}

