//
//  rsaini.cpp
//  Lab4
//
//  Created by Ryan Saini on 10/1/20.
//

#include <iostream>
#include <cmath>
using namespace std;
int maxCrossingSubarray(int *arr, int low, int mid, int high);
int maxSubarray(int *arr, int low, int high);

int main(int argc, const char * argv[]) {

    int size = 0;
    cin>>size; //arr size
    int *arr = new int[size];
    
    int i;
    for(i=0;i<size;i++){ //input
        cin>> arr[i];
    }
    
    int found = maxSubarray(arr, 0, size-1);
    
    cout<< found;
}

int maxCrossingSubarray(int *arr, int low, int mid, int high){
    int leftSum = -2147483647; //infinity  value
    int sum =0;
    int maxRight=0;
    int maxLeft=0;
    
    for (int i = mid; i>=low; i--){
        sum = sum + arr[i];
        if (sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightSum = -2147483647;
    sum = 0;
    
    for (int j = mid + 1; j<=high; j++){
        sum = sum + arr[j];
        if (sum > rightSum){
            rightSum = sum;
            maxRight = j;
        }
    }
    
    return(maxLeft, maxRight, leftSum + rightSum);
}

int maxSubarray(int *arr, int low, int high){
    int leftLow;
    int leftHigh;
    int leftSum;
    int rightLow;
    int rightHigh;
    int rightSum;
    int crossLow;
    int crossHigh;
    int crossSum;
    
    if(high==low){
        return(low, high, arr[low]);
    }
    
    else {
        int mid = trunc((low + high)/2);
        (leftLow, leftHigh, leftSum) = maxSubarray(arr, low, mid);
        (rightLow, rightHigh, rightSum) = maxSubarray(arr, mid + 1, high);
        (crossLow, crossHigh, crossSum) = maxCrossingSubarray(arr, low, mid, high);
        
        if(leftSum >= rightSum && leftSum >= crossSum){
            return(leftLow, leftHigh, leftSum);
        }
        else if(rightSum >= leftSum && rightSum >= crossSum){
            return(rightLow, rightHigh, rightSum);
        }
        else{
            return(crossLow, crossHigh, crossSum);
        }
    }
    
}
