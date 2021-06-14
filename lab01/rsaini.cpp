//
//  rsaini.cpp
//  Lab1
//
//  Created by Ryan Saini on 9/10/20.
//  Copyright © 2020 Ryan Saini. All rights reserved.
//

#include <iostream>
using namespace std;
int linearSearch(int *arr, int size, int a);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int size = 0;
    cin>>size; //arr size
    int *arr = new int[size];
    int a = 0;
    cin>>a; //# looking for
    
    int i;
    for(i=0;i<size;i++){ //input
           cin>> arr[i];
       }
    
    int found = linearSearch(arr, size, a);
    cout<< found;
    
    
}
       
    int linearSearch(int *arr, int size, int a){
        
        for(int i=0;i<size;i++){ //Linear search
            
            if(arr[i] == a){
                return i;
            }
            
        }
        return -1;
    }
