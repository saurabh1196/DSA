//
//  Selection.cpp
//  Sorting
//
//  Created by Saurabh Singh Dangi on 16/01/25.
//  worst case -> O(n2)  best case -> O(n2) 

#include <stdio.h>
#include <iostream>
using namespace std;

void selection_sort (int arr[], int n) {
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
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
    cout<< "Enter "<< n <<" numbers :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Unsorted array is : ";
    print_array(arr,n);
    selection_sort(arr,n);
    cout<< "Sorted array using selection sort is : ";
    print_array(arr,n);
}
