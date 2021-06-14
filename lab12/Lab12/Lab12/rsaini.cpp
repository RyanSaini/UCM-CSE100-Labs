//
//  rsaini.cpp
//  Lab12
//
//  Created by Ryan Saini on 11/18/20.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
void cutRod(int *arr, int size);

int main(int argc, const char * argv[]) {
    
    int size = 0;
    cin>>size;
    int *arr = new int[size];

    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    
    cutRod(arr, size);
    return 0;
}

void cutRod(int *arr, int size){
    
    int *r = new int[size + 1];
    int *s = new int[size + 1];
    
    for(int h = 0; h<size; h++){
        s[h] = -1;
    }
    
    int q = -2147483647;
    
    for (int j = 1; j<=size; j++){
        q = -2147483647;
        
        for(int i = 0; i<j; i++){
            if(q < arr[i] + r[j-i-1]){
                q = arr[i] + r[j-i-1];
                s[j] = i + 1;
            }
        }
        r[j] = q;
    }
    
    cout<<r[size]<<"\n";
    
    while (size > 0){
        cout<<s[size]<<" ";
        size = size - s[size];
    }
    
    cout<<"-1";
}
