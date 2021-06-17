#include <bits/stdc++.h>
using namespace std;
int F(int n){
    int arr[n + 1], i, j;
    arr[0] = 0, arr[1] = 1;    
    for(i = 2; i <= n; i ++){
     arr[i] = i;    
     }  
    for(i = 2; i <= n; i ++){
        if(arr[i] == i){
            for(j = i; j <= n; j += i){
                arr[j] -= (arr[j] / i); 
            }  
        }
    }
    return arr[n];  
}

int main(){
    int n;
    cout<<"Enter a integer: " ;
    cin>>n;   
    cout<<F(n); 
return 0;
}
