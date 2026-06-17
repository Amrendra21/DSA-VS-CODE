#include<iostream>
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

    // Bubble sorting : 
    for(int i=0; i<n-1; i++){
        bool flag = true;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
            flag = false;
        }
        if(flag==true) break;
    }
    
    cout<<endl;
    display(arr,n);      // print the array 
return 0;
}

// Enter the size of the array: 9
// Please Enter array Elements: 9 1 8 2 7 3 6 4 5
// 9 1 8 2 7 3 6 4 5 
// 1 2 3 4 5 6 7 8 9 