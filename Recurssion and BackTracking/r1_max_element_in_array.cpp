#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> arr,int n){
    if(n==1){
        return arr[0];
    }
    int last = arr[n-1];
    int answer = fun(arr,n-1);

    return max(last,answer);
}
int main(){
    vector<int> arr = {1,10,4,9,3,5,6,7,8,2};

    int n = arr.size();

    cout<<"Max Element in the array is: "<<fun(arr,n)<<endl;
return 0;
}