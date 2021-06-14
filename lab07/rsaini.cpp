//
//  rsaini.cpp
//  Lab7
//
//  Created by Ryan Saini on 10/11/20.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void radixSort(vector<int> *arr, int size);
vector<int> *countSort(vector<int> *arr, int size, int j);
void print(vector<int> *arr, int size);

int main(int argc, const char * argv[]) {
    
    int size = 0;
    int input = 0;
    cin>>size;
    vector<int> *arr;
    arr = new vector<int>[size];
    
    int i;
    int j;
    for(i=0;i<size;i++){ //outter for loop changes which vector we are filling in
        
        for (j=0;j<=9;j++){ //inner for loop gives 10 values for the vector.
            cin>>input;
            arr[i].push_back(input);
        }
    }
    
    radixSort(arr, size);
}

void radixSort(vector<int> *arr, int size){
    for(int j = 9; j>=0; j--){
        arr = countSort(arr, size, j);
    }
    
    print(arr, size);
}

vector<int> *countSort(vector<int> *arr, int size, int j){
    vector<int> *finish;
    finish = new vector<int>[size];
    
    for(int i =0; i<size; i++){
        for(int j = 0; j<=9; j++){
            finish[i].push_back(0);
        }
    }
    
    int counter[10] = {0};
    
    for(int i = 0; i<size; i++){
        counter[(arr[i][j] % 10)] = counter[(arr[i][j] % 10)] + 1;
    }
    
    for(int i = 1 ; i<10; i++){
        counter[i] = counter[i] + counter[i - 1];
    }
    
    for(int i = size-1; i>= 0;i--){
        finish[counter[arr[i][j] % 10] - 1] = arr[i];
         counter[arr[i][j] % 10] =counter[arr[i][j] % 10] - 1;
    }
       
        /*for(int i = 0; i<size; i++){
           arr[i] = finish[i];
        }*/
    
    return finish;
    }

void print(vector<int> *arr, int size){
    
    for(int i = 0; i < size; i++){
        
        for(int j = 0; j < 10; j++){
            cout << arr[i][j] << ";";
        }
        cout << "\n";
    }
}



