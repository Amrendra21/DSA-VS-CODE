// 424. Longest Repeating Character Replacement

#include<bits/stdc++.h>
using namespace std;

int fun(string s, int k) {
    int n = s.length();
    int low = 0;
    int res = INT_MIN;

    vector<int> f(26,0);
    for(int high=0; high<n; high++){
        f[s[high]-'A']++;
        int len = high-low+1;
        int maxi = *max_element(f.begin(), f.end());
        int diff = len - maxi;

        while(diff > k){
            f[s[low]-'A']--;
            low++;
            len = high-low+1;
            maxi = *max_element(f.begin(), f.end());
            diff = len - maxi;
        }
        res = max(res, len);
    }

    return res;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<fun(s,k)<<endl;


}