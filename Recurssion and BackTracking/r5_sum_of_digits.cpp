#include<iostream>
using namespace std;
int fun(int n){
    if(n<=9) return n;

    int ld = n%10;
    int ans = fun(n/10);

    return ld+ans;
}
int main(){
    int n;
    cin>>n;

    cout<<"The sum of the digits of "<<n<<" is : "<<fun(n)<<endl;
return 0;
}