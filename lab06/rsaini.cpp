//
//  rsaini.cpp
//  Lab6
//
//  Created by Ryan Saini on 10/5/20.
//

#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
void rQuickSort(int *arr, int p, int r);
int partition(int *arr, int p, int q);
void printArr(int* arr, int size);

int main(int argc, const char * argv[]) {
    
    int size = 0;
    cin>>size; //arr size
    int *arr = new int[size];
    
    int i;
    for(i=0;i<size;i++){ //input
        cin>> arr[i];
    }
    
    rQuickSort(arr, 0, size-1);
    printArr(arr, size);
    
}

void rQuickSort(int *arr, int p, int r){
    if(p<r){
        int q = partition(arr, p, r);
        rQuickSort(arr, p, q - 1);
        rQuickSort(arr, q + 1, r);
        
    }
}

int partition(int *arr, int p, int r){
    int temp = 0;
    int temp2 = 0;
    int random = p + rand()% (r-p);
    temp2 = arr[random];
    arr[random] = arr[r];
    arr[r] = temp2;
    
    int x = arr[r];
    int i = p - 1;
    
    for(int j =p; j<r;j++){
        if(arr[j] <= x){
            i = i + 1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    temp2 = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp2;
    
    return i+1;
}

void printArr(int* arr, int size){
    for (int i = 0; i < size; i++){
        cout << arr[i]<< ";";
    }
}
