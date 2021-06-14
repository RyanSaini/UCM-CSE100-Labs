//
//  rsaini.cpp
//  Lab3
//
//  Created by Ryan Saini on 9/22/20.
//

#include <iostream>
#include <cmath>
using namespace std;


void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);
void printArr(int* arr, int size);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int size = 0;
    cin>>size; //arr size
    int *arr = new int[size];
    
    int i;
    for(i=0;i<size;i++){ //array values
        cin>> arr[i];
    }
    
    
    mergeSort(arr, 0, size - 1);
    printArr(arr, size);
    
}

void mergeSort(int *arr, int left, int right){
    if(left < right){
        int mid = trunc((right + left)/2);
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
    
void merge(int *arr, int left, int mid, int right){
        int i =0;
        int j = 0;
        int k = 0;
        
        int L = mid - left + 1;
        int R = right - mid;
        
        int *Larr = new int[L + 1];
        int *Rarr = new int[R + 1];
    
        
        
        for(i = 0; i<L; i++){
            Larr[i] = arr[left + i];
        }
        
        
        for(j=0; j<R; j++){
            Rarr[j] = arr[mid + j + 1];
        }
        
        Larr[L] = 2147483647; //infinity  value to compare to
        Rarr[R] = 2147483647;
        i=0;
        j=0;
        
        for(k=left; k<=right; k++){
            if(Larr[i] <= Rarr[j]){
                arr[k] = Larr[i];
                i++;
        }
        
            else{
                arr[k] = Rarr[j];
                j++;
        }
            
    }
}

    void printArr(int* arr, int size){
        for (int i = 0; i < size; i++){
            cout << arr[i]<< ";";
        }
    }
