#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> a(n);
    cout<<"Please Enter array Elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    int low = 0;
    int high = k-1;
    int sum = 0;

    for(int i=low; i<=high; i++){
        sum+=a[i];
    }

    int res = 0;
    while(high<n){
        res = max(res,sum);
        low++;
        high++;

        if(high==n) break;
        sum = sum - a[low-1] + a[high];
    }

    cout<<res;
}