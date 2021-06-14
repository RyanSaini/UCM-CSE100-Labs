//
//  rsaini.cpp
//  Lab2
//
//  Created by Ryan Saini on 9/15/20.
//  Copyright © 2020 Ryan Saini. All rights reserved.
//

#include <iostream>
#include <cmath> //used to identify remainder
using namespace std;
int binarySearch(int *arr, int high, int low, int a);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int size = 0;
    cin>>size; //arr size
    int *arr = new int[size];
    int a = 0;
    cin>>a; // #looking for
    
    int i;
    for(i=0;i<size;i++){ //input
        cin>> arr[i];
    }
    
    int found = binarySearch(arr, size, 0, a);
    cout<< found;
    
}

int binarySearch(int *arr, int high, int low, int a){
    
    while(low <= high){
        int mid = trunc((low + high) / 2 ); //trunc takes care of .s
        
        if(a == arr[mid]){
            return mid; //if value found
        }
        
        else if(a < arr[mid]){
            high = mid - 1; //gotta shift it one to the left
        }
        
        else if(a > arr[mid]){
            low = mid + 1; //gotta shift it one to the right
        }
    }
    return -1; //nothing found
}
