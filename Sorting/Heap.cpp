//
//  Heap.cpp
//  Sorting
//
//  Created by Saurabh Singh Dangi on 19/01/25.
//  worst case -> O(nlogn)  avg/best case -> O(nlogn)

#include <stdio.h>
#include <iostream>
using namespace std;

void swap (int * , int *);

// to heapify a subtree rooted with index i
// which is a index in array arr[]
void heapify (int arr[] , int n , int i){
    
    // left child  =  2 * i +1
    int lChild = i*2+1;
    
    // right child =  2 * i +2
    int rChild = i*2+2;
    
    // initialize largest child as root
    int largestChild = i;
    
    // if left child is greater than root
    if(lChild < n && arr[lChild] > arr[largestChild]){
        largestChild = lChild;
    }
    
    // if left child is greater than largest child so far
    if(rChild < n && arr[rChild] > arr[largestChild]){
        largestChild = rChild;
    }
    
    // swap root to largest child
    if(largestChild != i){
        swap(&arr[i],&arr[largestChild]);
        // recursively  heapify the affected subtree
        heapify(arr, n, largestChild);
    }
}

// main function to do heapsort
void heap_sort(int *arr , int n){
    
    // build heap (max heap)
    for(int i= n/2-1 ; i>=0;i--){
        heapify(arr,n,i);
    }
    
    // one by one extract an element from max heap
    for(int i = n-1;i>0 ;i--){
        // move root to the end
        swap(&arr[0],&arr[i]);
        // call max heapify on reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to swap two element
void swap (int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
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
    heap_sort(arr,n);
    cout<< "Sorted array using heap sort is : ";
    print_array(arr,n);
}
