//
//  Merge.cpp
//  Sorting
//
//  Created by Saurabh Singh Dangi on 19/01/25.
//  worst case -> O(nlogn)  best case -> O(nlogn)

#include <stdio.h>
#include <iostream>
using namespace std;

void merge(int * , int , int , int);

// main function to do merge sort
void merge_sort (int *p , int l , int r){
    if(l<r){
        // devide array in two sub-array and call self for both half untill size == 1
        int mid = (l+r)/2;
        merge_sort(p, l, mid);
        merge_sort(p, mid+1, r);
        merge(p,l,mid,r);
    }
}


// function to merge two sorted array
// first array is p [l ... mid]
// second array is p [mid+1 ... h]
void merge(int *p , int l , int mid , int h){
    int i=l , j=mid+1 , k=0;
    int size = h-l+1;
    // temp array to store merged element
    int brr[size];
    // merge first and second array
    while(l <= mid && j <= h){
        if(p[i] < p[j]){
            brr[k] = p[i];
            i++;
            k++;
        }else{
            brr[k] = p[j];
            j++;
            k++;
        }
    }
    // copy  remaining element of first array
    while(i<=mid){
        brr[k] = p[i];
        i++;
        k++;
    }
    // copy  remaining element of second array
    while(j<=h){
        brr[k] = p[i];
        j++;
        k++;
    }
    // copy back element from temp array
    for(int i=0;i<size;i++){
        p[l+i] = brr[i];
    }
}

// A utility function to print array of size n
void print_array(int arr[], int n) {
    for(int i=0;i<n;i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

// Driver code
int main(){
    int n;
    cout<<" Enter A Number : ";
    cin>>n;
    int arr[n];
    cout<<" Enter " <<n <<" numbers : ";
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    cout<<"Unsorted array is : ";
    print_array(arr,n);
    merge_sort(arr,0,n-1);
    cout<< "Sorted array using merge sort is : ";
    print_array(arr,n);
}
