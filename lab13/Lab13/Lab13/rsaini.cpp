//
//  rsaini.cpp
//  Lab13
//
//  Created by Ryan Saini on 11/27/20.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
void matrixChainOrder(int *arr, int size);
void printParens(int i, int j, int n, int *brackets, int count);
int counter = 0;

int main(int argc, const char * argv[]) {
    
    int size = 0;
    cin>>size;
    int *arr = new int[size];
    
    for(int i = 0; i<=size; i++){
        cin>>arr[i];
    }
    
    matrixChainOrder(arr, size + 1);
    
}

void matrixChainOrder(int *arr, int size){
    int m[size][size];
    int s[size][size];
    int j = 0;
    int q = 0;
    
    for(int i = 1; i < size; i++){
         m[i][i] = 0;
    }
    
    for(int l = 2; l < size; l++){
        
        for(int i = 1; i < size - l + 1; i++){
            j = i + l - 1;
            m[i][j] = 2147483647;
            
            for(int k = i; k <= j - 1; k++){
                q = m[i][k] + m[k+1][j] + ((arr[i-1]) * (arr[k]) * (arr[j]));
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
            }
        }
    }
}
    
    cout<<m[1][size-1]<<"\n";
    
    printParens(1, size-1, size, (int *)s, counter);
}


void printParens(int i, int j, int n, int *brackets, int count){

    if (i == j){
        cout <<"A"<<counter;
        counter++;
        return ;
   }
    else{
        cout << "(";

        printParens(i, *((brackets+i*n)+j), n, brackets, counter);
    
        printParens(*((brackets+i*n)+j) + 1, j, n, brackets, counter);

        cout << ")";
}
}
