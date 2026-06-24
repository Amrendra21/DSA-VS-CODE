#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &v){
    cout<<"{";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"}  ";
}

void fun(vector<int>& a, int n,int idx, vector<int>& temp){
    if(idx == n){
        display(temp);
        return;
    }

    // include the element
    temp.push_back(a[idx]);
    fun(a,n,idx+1,temp);

    // exclude the element
    temp.pop_back();
    fun(a,n,idx+1,temp);
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    int n = arr.size();

    vector<int> temp;

    fun(arr,n,0,temp);
return 0;
}