#include<bits/stdc++.h>
using namespace std;

bool fun(string& s, int low, int high){
    if(low>=high) return true;

    if(s[low]!=s[high]) return false;

    return fun(s,low+1,high-1);
}

int main(){
    string s;
    cout<<"Enter a string\n";
    cin>>s;

    int n = s.length();
    bool ans = fun(s,0,n-1);
    if(ans==true) cout<<"It's a palindrome";
    else cout<<"It's not a palindrome";
}