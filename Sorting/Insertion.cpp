//
//  Insertion.cpp
//  Sorting
//
//  Created by Saurabh Singh Dangi on 16/01/25.
//  worst case -> O(n2)  best case -> O(n)

#include <stdio.h>
#include <iostream>
using namespace std;

void insertion_sort (int arr[], int n) {
    for(int i=1,j;i<n;i++){
        int min = arr[i];
        for(j=i-1;j>=0 && arr[j]>min;j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = min;
    }
}

void swap (int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<" Enter Number : ";
    cin>>n;
    int arr[n];
    cout<< "Enter "<< n <<" numbers : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Unsorted array is : ";
    print_array(arr,n);
    insertion_sort(arr,n);
    cout<< "Sorted array using insertion sort is : ";
    print_array(arr,n);
}
