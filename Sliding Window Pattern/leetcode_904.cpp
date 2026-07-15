#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0;

        int k=2; // 2 different baskets 

        int res = INT_MIN;
        unordered_map<int,int> m;

        for(int high=0; high<n; high++){
            m[fruits[high]]++;

            while(m.size()>k){
                m[fruits[low]]--;
                if(m[fruits[low]]==0) m.erase(fruits[low]);
                low++;
            }

            int len = high-low+1;
            res = max(res,len);
        }

        return res;
}

int main(){
    vector<int> fruits = {1, 2, 1};
    cout << totalFruit(fruits) << endl;
    return 0;
}