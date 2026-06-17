#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // for each loop : 

    for(int ele:s){
        cout<<ele<<" ";
    }
    cout<<endl;

    cout<<s.size()<<endl;

    s.erase(2);

    for(int ele:s){
        cout<<ele<<" ";
    }
    cout<<endl;

    cout<<s.size()<<endl;

    int target = 3;
    if(s.find(target) != s.end()){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }

return 0;
}