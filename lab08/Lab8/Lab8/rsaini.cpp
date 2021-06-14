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
void bucketSort(int *arr, int size);

int main(int argc, const char * argv[]) {
    
    int size = 0;
    cin>>size;
    int *arr = new int[size];
    
    int i;
    for(i=0;i<size;i++){
        cin>> arr[i];
    }
    
    bucketSort(arr, size);
}
void bucketSort(int *arr, int size){
    vector<list<float> > sortArr;
    
    for(int i = 0; i < size; i++){
        list<float> emptyList;
        sortArr.push_back(emptyList);
    }
    
    for(int i = 0; i < size; i++){
        sortArr[trunc(size*arr[i])].push_front(arr[i]);
    }
    
    for(int i = 0; i < size; i++){
        //call insertion sort
        sortArr[i].sort();
    }
    for(int i = 0; i < size; i++){
        int listSize = sortArr[i].size();
        for(int j = 0; j < listSize; j++){
            cout<<sortArr[i].front();
            sortArr[i].pop_front();
            cout<<"\n";
        }
    }
}

