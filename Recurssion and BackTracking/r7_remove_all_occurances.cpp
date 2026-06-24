#include<bits/stdc++.h>
using namespace std;

string fun(string& s, char c, int i, int n){
    if(i==n) return "";

    string ans = fun(s,c,i+1,n);

    if(s[i]==c) return ans;
    return s[i]+ans;
}

int main(){
    string s;
    cout<<"Enter a string : ";
    cin>>s;

    char c;
    cout<<"Enter the character that is to be removed : ";
    cin>>c;

    int n = s.length();

    cout<<fun(s,c,0,n);
return 0;
}