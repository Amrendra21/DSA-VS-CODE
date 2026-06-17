#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    int m = n-1;  // new line size
    
    // for the first line
    for(int i=1; i<=2*n-1; i++){
        cout<<"*";
    }
    cout<<endl;
    
    // for pattern 
    for(int i =1; i<=m; i++){
        for(int j=1; j<=m+1-i; j++){
            cout<<"*";
        }
        for(int j=1; j<=2*i-1; j++){
            cout<<" ";
        }
        for(int j=1; j<=m+1-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }

return 0;
}