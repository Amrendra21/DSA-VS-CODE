#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;

    pair<string,int> p1;
    p1.first = "Amrendra";
    p1.second = 21;
    m.insert(p1);

    pair<string,int> p2 = make_pair("Aman",22);
    m.insert(p2);

    m["Rajesh"] = 23;

    for(auto ele:m){
        cout<<ele.first<<" "<<ele.second<<endl;
    }


    m.erase("Aman");

    for(auto ele:m){
        cout<<ele.first<<" "<<ele.second<<endl;
    }

    m.size();

    // searching : 
    if(m.find("Amrendra") != m.end()){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }

    return 0;
}