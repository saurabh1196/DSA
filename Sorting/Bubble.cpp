//
//  Bubble.cpp
//  Sorting
//
//  Created by Saurabh Singh Dangi on 19/01/25.
//  worst case -> O(n2)  best case -> O(n)

#include <stdio.h>
#include <iostream>
using namespace std;

void bubble_sort(int *p , int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j] > p[j+1]){
                // swap number
                p[j+1] = p[j] + p[j+1];
                p[j] = p[j+1] - p[j];
                p[j+1] = p[j+1] - p[j];
            }
        }
    }
}

void swap_number (int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int n) {
    for(int i=0;i<n;i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

int main() {
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
    bubble_sort(arr,n);
    cout<< "Sorted array using bubble sort is : ";
    print_array(arr,n);
}
