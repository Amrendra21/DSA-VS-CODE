#include<iostream>
#include<climits>
using namespace std;
void display(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];

    cout<<"Please Enter array Elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    display(arr,n);    // print the array

    // selection sort algorithm : 
    for(int i=0; i<n-1; i++){
        int min = INT_MAX;
        int minidx = -1;
        for(int j=i+1; j<n; j++){
            if(arr[j]<min){
                min = arr[j];
                minidx = j;
            }
        }
        int temp = arr[minidx];
        arr[minidx] = arr[i];
        arr[i] = temp;
    }

    cout<<endl;
    display(arr,n);      // print the array 
return 0;
}
