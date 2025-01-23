//
//  Quick.cpp
//  Sorting
//
//  Created by Saurabh Singh Dangi on 19/01/25.
//  worst case -> O(n2)  avg/best case -> O(nlogn)

#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int *, int *);
int partition(int * , int , int);

void quick_sort(int *p , int l , int h){
    if(l<h){
        // pi index of pivot
        int pi = partition(p,l,h);
        quick_sort(p, l, pi);
        quick_sort(p, pi+1, h);
    }
}


int partition (int *p , int l ,int h){
    // First element is taken as pivot to partition array in two half
    int pivot = p[l];
    int k=h;
    // Move larger element to right side
    for(int i=h; i>l;i--){
        if(p[i] > pivot){
            swap(&p[i],&p[k]);
            k--;
        }
    }
    // Move pivot before larger elements
    swap(&p[k],&p[l]);
    return k;
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
    quick_sort(arr,0,n-1);
    cout<< "Sorted array using quick sort is : ";
    print_array(arr,n);
}
