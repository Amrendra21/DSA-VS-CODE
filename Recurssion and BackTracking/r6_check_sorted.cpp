#include<bits/stdc++.h>
using namespace std;

bool fun(vector<int>& a, int i, int n){
    if(i==n or i==n-1) return 1;

    if(a[i]>a[i+1]) return false;

    return fun(a,i+1,n);
}

int main(){
    vector<int> a = {1,2,3,4,5};

    cout<<fun(a,0,a.size());
return 0;
}