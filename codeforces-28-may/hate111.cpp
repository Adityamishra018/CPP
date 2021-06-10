#include<iostream>
#define ll long long int
using namespace std;

int main(){
 ll t; cin>>t;
 while(t--){
  ll x; cin>>x;
  ll rem = (x-(x%11)*111);
  if(rem>=0 and rem%11==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
    }
}