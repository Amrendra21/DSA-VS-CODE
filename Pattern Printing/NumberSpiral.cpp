// // Enter n : 4
// // 1111111
// // 1222221
// // 1233321
// // 1234321
// // 1233321
// // 1222221
// // 1111111

// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter n : ";
//     cin>>n;

//     for(int i=1; i<=2*n-1; i++){
//         for(int j=1; j<=2*n-1; j++){
//             int a = i;     // pseudo variables
//             int b = j;
//             if(a>n) a = 2*n-i;
//             if(b>n) b = 2*n-j;
//             cout<<min(a,b);
//         }
//         cout<<endl;
//     }
// return 0;
// }


// Enter n : 4
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    for(int i=1; i<=2*n-1; i++){
        for(int j=1; j<=2*n-1; j++){
            int a = i;     // pseudo variables
            int b = j;
            if(a>n) a = 2*n-i;
            if(b>n) b = 2*n-j;
            int x = min(a,b);
            cout<<n-x+1;
        }
        cout<<endl;
    }
return 0;
}