//
//  rsaini.cpp
//  Lab5
//
//  Created by Ryan Saini on 10/4/20.
//

#include <iostream>
#include <cmath>
using namespace std;
void heapsort(int *arr, int size);
void maxHeap(int *arr, int i, int size);
void buildMaxHeap(int *arr, int size);
void printArr(int* arr, int size);

int main(int argc, const char * argv[]) {
    
    int size = 0;
    cin>>size; //arr size
    int *arr = new int[size];
    
    int i;
    for(i=0;i<size;i++){ //input
        cin>> arr[i];
    }
    
    heapsort(arr,size);
    printArr(arr,size);
    
}

void heapsort(int *arr, int size){
    buildMaxHeap(arr, size);
    int i = 0;
    int key;
    for(i = size-1; i>=0; i--){
        key = arr[0];
        arr[0] = arr[i];
        arr[i] = key;
        
        maxHeap(arr, 0, i);
        
    }
}

void buildMaxHeap(int *arr, int size){
    int i = 0;
    for (i = trunc((size/2)); i>=0; i--){
        maxHeap(arr, i, size);
    }
}

void maxHeap(int *arr, int i, int size){
    int left = (2*i) + 1;
    int right = (2*i) + 2;
    int largest = 0;
    int key = 0;
    
    if(left < size && arr[left]>arr[i]){
        largest = left;
    }
    else{
        largest = i;
    }

    if(right < size && arr[right]>arr[largest]){
        largest = right;
    }
    
    if(largest != i){
        key = arr[i];
        arr[i] = arr[largest];
        arr[largest] = key;
        maxHeap(arr, largest, size);
    }
    
}

void printArr(int* arr, int size){
    int i = 0;
    for (i = 0; i < size; i++){
        cout << arr[i]<< ";";
    }
}

