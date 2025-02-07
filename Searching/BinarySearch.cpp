//
//  BinarySearch.cpp
//  Searching
//
//  Created by Saurabh Singh Dangi on 27/01/25.
//  O(nlogn)

#include <stdio.h>
#include <iostream>

using namespace std;

int binarySearch_rec(int arr[] , int l , int h , int number){
    if(l<=h){
        int mid = l + (h-l)/2;
        if(arr[mid] == number){
            return mid;
        }
        if(number < arr[mid]){
            return binarySearch_rec(arr, l, mid-1, number);
        }
        else{
            return binarySearch_rec(arr, mid+1, h, number);
        }
    }
    return -1;
}

int binarySearch_iterative (int arr[] , int l , int h , int number){
    int low = l , high = h;
    while(low < high ){
        int mid = low + (high-low) /2;
        if(arr[mid] == number){
            return mid;
        }
        if(number < arr[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cout<<" Enter A Number : ";
    cin>>n;
    int arr[n];
    cout<<" Enter " <<n <<" numbers in sorted order : ";
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    cout<<"Enter A number to search : ";
    cin>>m;
    
    cout<<" .....  Recursive Binary Search ...... "<<endl;
    
    int index = binarySearch_rec(arr,0,n-1,m);
    if(index != -1){
        cout<<" number found at index : "<< index+1 <<endl;
    } else{
        cout<<" number not found"<<endl;
    }
    
    cout<<" .....  Iteraive Binary Search ...... "<<endl;
    
    index = binarySearch_iterative(arr,0,n-1,m);
    if(index != -1){
        cout<<" number found at index : "<< index+1 <<endl;
    } else{
        cout<<" number not found"<<endl;
    }

}

